#include "Arduino.h"
#include "Ship.h"
#include <FastLED.h>

#define MATRIX_PIN 4
#define NUM_LEDS this->rows * this->cols
#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define BRIGHTNESS 10
#define CURSOR_DELAY_TIME 200 // Miliseconds

class Board {
  private:
    int rows;
    int cols;

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