#include "Arduino.h"
#include "Ship.h"
#include <FastLED.h>

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

  public:
    int **main;
    int **enemy;
    Board(int rows, int cols);
    void print();
    void illuminate();
    void scroller();
    void placeShip(Ship ship);
    void setCursor(char id, int x, int y); // id = 'm' for main board, 'e' for enemy board
    int getCursorX();
    int getCursorY();
    int getPixel(char id, int x, int y);
    void setPixel(char id, int x, int y, int value);
};
