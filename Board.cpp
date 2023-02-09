#include "Board.h"
#include <FastLED.h>

#define MATRIX_PIN 4
#define NUM_LEDS this->rows * this->cols
#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define BRIGHTNESS 2

Board::Board(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  this->get = new int*[rows];

  for (int row = 0; row < rows; row++) {
    get[row] = new int[cols];
  }

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      get[row][col] = 0;
    }
  }
}

void Board::print() {
  Board::illuminate();

  Serial.print("  |");
  for (int i = 1; i <= cols; i++) {
      Serial.print(" ");
      Serial.print(i);
      Serial.print(" |");
  }
  Serial.println("\n  -----------------------------------------");

  for (int row = 0; row < rows; row++) {
    Serial.print((char)('A' + row % 26)); // Increase the letter -> A, B, C, ...
    Serial.print(" |");
    for (int col = 0; col < cols; col++) {
        Serial.print(" ");
        Serial.print(get[row][col]);
        Serial.print(" |");
    }
    Serial.println();
    Serial.print("  ");
    for (int i = 0; i <= cols; i++) {
        Serial.print("---");
    }
    Serial.println("--------");
  }

  Serial.println("");
}

void Board::illuminate() {
  CRGB leds[NUM_LEDS];
  FastLED.addLeds<CHIPSET, MATRIX_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int value = get[i][j];
      if (value == 0) {
        leds[i * cols + j] = CRGB::Blue;
      } else if (value == 1) {
        leds[i * cols + j] = CRGB::Green;
      } else if (value == 2) {
        leds[i * cols + j] = CRGB::White;
      } else if (value == 3) {
        leds[i * cols + j] = CRGB::Red;
      }
    }
  }

  FastLED.show();
}

/**
  * Takes an object of type Ship and and change the values
  * of the coordinates from zero to one on the board
  */
void Board::placeShip(Ship ship) {
  for (int row = ship.getStartY(); row <= ship.getEndY(); row++) {
    for (int col = ship.getStartX(); col <= ship.getEndX(); col++) {
      get[row][col] = 1;
    }
  }
}

int Board::getPixel(int x, int y) {
  return this->get[y - 1][x - 1];
}

void Board::setPixel(int x, int y, int value) {
  this->get[y - 1][x - 1] = value;
}