#include "Board.h"

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
