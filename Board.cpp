#include "Board.h"

Board::Board(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  this->get = new int*[rows];

  for(int row = 0; row < rows; row++) {
    get[row] = new int[cols];
  }

  for(int row = 0; row < rows; row++) {
    for(int col = 0; col < cols; col++) {
      get[row][col] = 0;
    }
  }
}

void Board::serialPrint() {
  Serial.print("  |");
  for (int i = 1; i <= cols; i++) {
      Serial.print(" ");
      Serial.print(i);
      Serial.print(" |");
  }
  Serial.println("\n  -----------------------------------------");

  for(int row = 0; row < rows; row++) {
    Serial.print((char)('A' + row % 26)); // Increase the letter -> A, B, C, ...
    Serial.print(" |");
    for(int col = 0; col < cols; col++) {
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

void Board::placeShip(Ship ship) {
  for (int row = ship.getStartY(); row <= ship.getEndY(); row++) {
    for (int col = ship.getStartX(); col <= ship.getEndX(); col++) {
      get[row][col] = 1;
    }
  }  
}