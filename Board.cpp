#include "Board.h"

Board::Board(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  this->board = new int*[rows];

  for (int row = 0; row < rows; row++) {
    board[row] = new int[cols];
  }

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      board[row][col] = 0;
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
        Serial.print(board[row][col]);
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
  FastLED.addLeds<CHIPSET, MATRIX_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int value = board[i][j];
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
      board[row][col] = 1;
    }
  }
}

void Board::setCursor(int x, int y) {
  // TODO: Make this with millis
  int pixel = Board::getPixel(x, y);
  Board::setPixel(x, y, 3);
  Board::print();
  delay(CURSOR_DELAY_TIME);
  Board::setPixel(x, y, pixel);
  Board::print();
  delay(CURSOR_DELAY_TIME);
}

void Board::removeCursor(int x, int y) {

}

int Board::getPixel(int x, int y) {
  return this->board[y - 1][x - 1];
}

void Board::setPixel(int x, int y, int value) {
  this->board[y - 1][x - 1] = value;
}