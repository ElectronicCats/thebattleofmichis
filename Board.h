#include "Arduino.h"
#include "Ship.h"
#include <FastLED.h>

#include <LEDMatrix.h>
#include <LEDSprites.h>

#define MATRIX_PIN 4
#define NUM_LEDS this->rows * this->cols
#define COLOR_ORDER    RGB
#define CHIPSET        WS2812B

#define MATRIX_WIDTH   -8
#define MATRIX_HEIGHT  8

#define MATRIX_TYPE    VERTICAL_ZIGZAG_MATRIX

#define BRIGHTNESS 10
#define CURSOR_DELAY_TIME 200 // Miliseconds

#define SHAPE_WIDTH    8
#define SHAPE_HEIGHT   8

class Board {
  private:
    int rows;
    int cols;

  public:
    int **board;
    Board(int rows, int cols);
    void print();
    void init();
    void illuminate();
    void placeShip(Ship ship);
    void setCursor(int x, int y);
    void removeCursor(int x, int y);
    int getPixel(int x, int y);
    void setPixel(int x, int y, int value);
};
