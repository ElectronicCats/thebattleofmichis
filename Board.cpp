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

struct CRGB SpriteBoardCols[64]; 

cSprite SpriteBoard(8, 8, SpriteBoardData, 1, _8BIT, SpriteBoardCols);

cLEDSprites Sprites(&boardUp);

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

void Board::init() {

  Serial.println("\n  Start board...");

  FastLED.addLeds<CHIPSET, MATRIX_PIN, COLOR_ORDER>(boardUp[0], boardUp.Size());
  FastLED.setBrightness(8);
  FastLED.clear(true);
  delay(500);
  FastLED.showColor(CRGB::Blue);
  delay(1000);
  FastLED.show();

  //SpriteBoard.SetPositionFrameMotionOptions(0/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 0/*XRate*/, 0/*YChange*/, 0/*YRate*/, SPRITE_DETECT_EDGE | SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);
  Sprites.AddSprite(&SpriteBoard);
}

void Board::illuminate() {
  FastLED.clear();
   
  bool CUSTOM_BOARD = false;
  
  if (CUSTOM_BOARD) {
//    for (int i = 0; i < NUM_LEDS; i++) {
//      int index = i; //customMap[i];
//      int row = index / cols;
//      int col = index % cols;
//      int value = board[row][col];
//
//      if (value == 0) {
//        leds[i] = CRGB::Blue;
//      } else if (value == 1) {
//        leds[i] = CRGB::Green;
//      } else if (value == 2) {
//        leds[i] = CRGB::White;
//      } else if (value == 3) {
//        leds[i] = CRGB::Red;
//      }
//    }
  } else {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int value = board[i][j];
        if (value == 0) {
          SpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Blue;
        } else if (value == 1) {
          SpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Green;
        } else if (value == 2) {
          SpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::White;
        } else if (value == 3) {
          SpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Red;
        }
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
