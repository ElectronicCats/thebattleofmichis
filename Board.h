#include "Arduino.h"
#include "Ship.h"
#include <FastLED.h>
#include <vector>

#include <LEDMatrix.h>    // https://github.com/AaronLiddiment/LEDMatrix.git
#include <LEDSprites.h>   // https://github.com/AaronLiddiment/LEDSprites.git

#define CUSTOM_BOARD      false // true -> Electronic Cats board, false -> CJMCU-64 board
#define PIN_MATRIX_1      16
#define PIN_MATRIX_2      17
#define COLOR_ORDER       GRB // GRB ordering is typical for the WS2812B chipset
#define CHIPSET           WS2812B

#define BRIGHTNESS        10
#define CURSOR_DELAY_TIME 200 // Miliseconds

#define SHAPE_WIDTH       8
#define SHAPE_HEIGHT      8
#define MATRIX_TYPE CUSTOM_BOARD ? VERTICAL_ZIGZAG_MATRIX : HORIZONTAL_MATRIX
#define MATRIX_WIDTH CUSTOM_BOARD ? -8 : 8
#define MATRIX_HEIGHT CUSTOM_BOARD ? 8 : -8

class Board {
  private:
    int rows;
    int cols;
    void initMainBoard();
    void initEnemyBoard();
    int cursorX;
    int cursorY;
    void serialPrint(int **matrix);
    enum Color { Blue = 0, Green = 1, White = 2, Red = 3 };
    enum Orientation { Horizontal = 0, Vertical = 1 };

  public:
    int **main;
    int **enemy;
    Board(int rows, int cols);
    void print();
    void illuminate(char id, int **matrix);
    void scroller();
    void placeShip(Ship ship);
    void setCursor(char id, int x, int y, int length, int orientation);
    int getCursorX();
    int getCursorY();
    int getPixel(char id, int x, int y);
    void setPixel(char id, int x, int y, int value);
    void setHorizontalLine(char id, int x, int y, int length, int color);
    void setVerticalLine(char id, int x, int y, int length, int color);
};
