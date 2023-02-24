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
  bool CUSTOM_BOARD = true;
  
  if (CUSTOM_BOARD) {
    int customMap[64] = {
      56, 55, 40, 39, 24, 23,  8,  7,
      57, 54, 41, 38, 25, 22,  9,  6,
      58, 53, 42, 37, 26, 21, 10,  5,
      59, 52, 43, 36, 27, 20, 11,  4,
      60, 51, 44, 35, 28, 19, 12,  3,
      61, 50, 45, 34, 29, 18, 13,  2,
      62, 49, 46, 33, 30, 17, 14,  1,
      63, 48, 47, 32, 31, 16, 15,  0};

    for (int i = 0; i < NUM_LEDS; i++) {
      int index = customMap[i];
      int row = index / cols;
      int col = index % cols;
      int value = board[row][col];

      if (value == 0) {
        leds[i] = CRGB::Blue;
      } else if (value == 1) {
        leds[i] = CRGB::Green;
      } else if (value == 2) {
        leds[i] = CRGB::White;
      } else if (value == 3) {
        leds[i] = CRGB::Red;
      }
    }
  } else {
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