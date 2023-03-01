#include "Arduino.h"
#include "Ship.h"
#include <FastLED.h>

#include <LEDMatrix.h>
#include <LEDSprites.h>

#define CUSTOM_BOARD      true // true -> Electronic Cats board, false -> CJMCU-64 board
#define MATRIX_PIN        4
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
    void init_leds();

  public:
    int **board;
    Board(int rows, int cols);
    void print();
    void illuminate();
    void placeShip(Ship ship);
    void setCursor(int x, int y);
    void removeCursor(int x, int y);
    int getPixel(int x, int y);
    void setPixel(int x, int y, int value);
};
