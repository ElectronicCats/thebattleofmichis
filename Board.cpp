#include "Board.h"

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> boardUp;

const uint8_t SpriteBoardData[] = {
  0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
  0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,
  0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,
  0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,
  0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,
  0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,
  0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
  0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,0x40
};

struct CRGB MainSpriteBoardCols[64];
struct CRGB EnemySpriteBoardCols[64];

cSprite MainSpriteBoard(8, 8, SpriteBoardData, 1, _8BIT, MainSpriteBoardCols);
cSprite EnemySpriteBoard(8, 8, SpriteBoardData, 1, _8BIT, EnemySpriteBoardCols);

cLEDSprites Sprites(&boardUp);

Board::Board(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  this->main = new int*[rows];
  this->enemy = new int*[rows];

  // Fill the main board with 0
  for (int row = 0; row < rows; row++) {
    main[row] = new int[cols];
  }
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      main[row][col] = 0;
    }
  }

  // Fill the enemy board with 0
  for (int row = 0; row < rows; row++) {
    enemy[row] = new int[cols];
  }
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      enemy[row][col] = 0;
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
        Serial.print(main[row][col]);
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

void Board::initMainBoard() {
  FastLED.addLeds<CHIPSET, PIN_MATRIX_1, COLOR_ORDER>(boardUp[0], boardUp.Size());
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear(true);
  Sprites.AddSprite(&MainSpriteBoard);
}

void Board::initEnemyBoard() {
  FastLED.addLeds<CHIPSET, PIN_MATRIX_2, COLOR_ORDER>(boardUp[0], boardUp.Size());
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear(true);
  Sprites.AddSprite(&MainSpriteBoard);
}

// Fill the board with the colors
void Board::illuminate() {
  Board::initMainBoard();
  Board::initEnemyBoard();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int value = main[i][j];
      if (value == 0) {
        MainSpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Blue;
      } else if (value == 1) {
        MainSpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Green;
      } else if (value == 2) {
        MainSpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::White;
      } else if (value == 3) {
        MainSpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Red;
      }
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int value = enemy[i][j];
      if (value == 0) {
        EnemySpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Blue;
      } else if (value == 1) {
        EnemySpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Green;
      } else if (value == 2) {
        EnemySpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::White;
      } else if (value == 3) {
        EnemySpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Red;
      }
    }
  }

  Sprites.UpdateSprites();
  Sprites.RenderSprites();
  FastLED.show();
}

/**
  * Takes an object of type Ship and and change the values
  * of the coordinates from zero to one on the board
  */

void Board::placeShip(Ship ship) {
  for (int row = ship.getStartY(); row <= ship.getEndY(); row++) {
    for (int col = ship.getStartX(); col <= ship.getEndX(); col++) {
      main[row][col] = 1;
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
  return this->main[y - 1][x - 1];
}

void Board::setPixel(int x, int y, int value) {
  this->main[y - 1][x - 1] = value;
}
