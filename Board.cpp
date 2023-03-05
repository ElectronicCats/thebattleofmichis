#include "Board.h"

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> mainBoardUp;
cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> enemyBoardUp;

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

const uint8_t SpriteopenData[] = {
  B8_4BIT(11111111),B8_4BIT(11222311),B8_4BIT(11111111),B8_4BIT(01111110),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11144444),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(14411144),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(51111115),B8_4BIT(11111121),B8_4BIT(11112223),B8_4BIT(21121111),
  B8_4BIT(11211121),B8_4BIT(11333311),B8_4BIT(12111111),B8_4BIT(00111100),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11144114),B8_4BIT(41111111),B8_4BIT(11111441),B8_4BIT(11111441),B8_4BIT(11114441),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111444),B8_4BIT(11111111),B8_4BIT(14441444),B8_4BIT(11144111),B8_4BIT(11111111),B8_4BIT(14411111),B8_4BIT(11144111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(55111155),B8_4BIT(11111112),B8_4BIT(11113333),B8_4BIT(31662221),
  B8_4BIT(11126112),B8_4BIT(61223216),B8_4BIT(21111101),B8_4BIT(00000000),B8_4BIT(10111111),B8_4BIT(11111111),B8_4BIT(11144114),B8_4BIT(41114444),B8_4BIT(11144444),B8_4BIT(41144444),B8_4BIT(41111441),B8_4BIT(11144441),B8_4BIT(11111111),B8_4BIT(11144441),B8_4BIT(11114411),B8_4BIT(11111111),B8_4BIT(14444444),B8_4BIT(11111111),B8_4BIT(11444411),B8_4BIT(14411111),B8_4BIT(11111111),B8_4BIT(14444411),B8_4BIT(11111111),B8_4BIT(11111151),B8_4BIT(55555555),B8_4BIT(15111222),B8_4BIT(26122332),B8_4BIT(31666111),
  B8_4BIT(11666166),B8_4BIT(61333316),B8_4BIT(66111110),B8_4BIT(01000010),B8_4BIT(01111111),B8_4BIT(11111111),B8_4BIT(11144444),B8_4BIT(11111114),B8_4BIT(41111441),B8_4BIT(11111441),B8_4BIT(11111441),B8_4BIT(11441144),B8_4BIT(11111111),B8_4BIT(11441144),B8_4BIT(11144444),B8_4BIT(11111111),B8_4BIT(14414144),B8_4BIT(11444111),B8_4BIT(14411111),B8_4BIT(14444411),B8_4BIT(11444111),B8_4BIT(44111111),B8_4BIT(11111111),B8_4BIT(11111115),B8_4BIT(51555515),B8_4BIT(51111116),B8_4BIT(66133332),B8_4BIT(31666111),
  B8_4BIT(17777777),B8_4BIT(77777777),B8_4BIT(77711001),B8_4BIT(01100110),B8_4BIT(10011111),B8_4BIT(11111111),B8_4BIT(11144114),B8_4BIT(41114444),B8_4BIT(41111441),B8_4BIT(11111441),B8_4BIT(11111441),B8_4BIT(11444444),B8_4BIT(11111111),B8_4BIT(11441144),B8_4BIT(11114411),B8_4BIT(11111111),B8_4BIT(14411144),B8_4BIT(11144111),B8_4BIT(14411111),B8_4BIT(14411441),B8_4BIT(11144111),B8_4BIT(14444111),B8_4BIT(11111111),B8_4BIT(11111551),B8_4BIT(51155115),B8_4BIT(15511777),B8_4BIT(77777777),B8_4BIT(77777771),
  B8_4BIT(11333323),B8_4BIT(23232333),B8_4BIT(33311110),B8_4BIT(00000000),B8_4BIT(01111111),B8_4BIT(11111111),B8_4BIT(11144114),B8_4BIT(41144114),B8_4BIT(41111441),B8_4BIT(11111441),B8_4BIT(11111441),B8_4BIT(11441111),B8_4BIT(11111111),B8_4BIT(11441144),B8_4BIT(11114411),B8_4BIT(11111111),B8_4BIT(14411144),B8_4BIT(11144111),B8_4BIT(14411111),B8_4BIT(14411441),B8_4BIT(11144111),B8_4BIT(11114411),B8_4BIT(11111111),B8_4BIT(11111115),B8_4BIT(55555555),B8_4BIT(51111133),B8_4BIT(33232323),B8_4BIT(23333331),
  B8_4BIT(11133333),B8_4BIT(33333333),B8_4BIT(33111101),B8_4BIT(10000001),B8_4BIT(10111111),B8_4BIT(11111111),B8_4BIT(11144444),B8_4BIT(11114444),B8_4BIT(41111144),B8_4BIT(41111144),B8_4BIT(41114444),B8_4BIT(11144441),B8_4BIT(11111111),B8_4BIT(11144441),B8_4BIT(11114411),B8_4BIT(11111111),B8_4BIT(14411144),B8_4BIT(11444411),B8_4BIT(11444411),B8_4BIT(14411441),B8_4BIT(11444411),B8_4BIT(44444111),B8_4BIT(11111111),B8_4BIT(11111151),B8_4BIT(15555551),B8_4BIT(15111113),B8_4BIT(33333333),B8_4BIT(33333311),
  B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88889888),B8_4BIT(88888888) };
const struct CRGB SpriteopenCols[15] = { CRGB(255,186,0), CRGB(51,51,51), CRGB(179,179,179), CRGB(186,63,208), CRGB(255,255,255), CRGB(128,128,128), CRGB(115,99,86), CRGB(40,171,227), CRGB(39,171,229), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0) };
cSprite Spriteopen(224, 8, SpriteopenData, 1, _4BIT, SpriteopenCols);

cLEDSprites MainSprites(&mainBoardUp);
cLEDSprites EnemySprites(&enemyBoardUp);

Board::Board(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  this->main = new int*[rows];
  this->enemy = new int*[rows];
  this->cursorX = 0;
  this->cursorY = 0;

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

// Print the matrix on the serial monitor
void Board::serialPrint(int **matrix) {
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
        Serial.print(matrix[row][col]);
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

// Print the matrix on the LED matrix
void Board::print() {
  // Board::serialPrint(main);
  // Board::serialPrint(enemy);
  Board::initMainBoard();
  Board::initEnemyBoard();
  Board::illuminate('m', main);
  Board::illuminate('e', enemy);
}

void Board::initMainBoard() {
  FastLED.addLeds<CHIPSET, PIN_MATRIX_1, COLOR_ORDER>(mainBoardUp[0], mainBoardUp.Size());
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear(true);
  MainSprites.AddSprite(&MainSpriteBoard);
}

void Board::initEnemyBoard() {
  FastLED.addLeds<CHIPSET, PIN_MATRIX_2, COLOR_ORDER>(enemyBoardUp[0], enemyBoardUp.Size());
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear(true);
  EnemySprites.AddSprite(&EnemySpriteBoard);
  //EnemySprites.AddSprite(&Spriteopen);
  //Board::scroller();
}


// LED banner test
void Board::scroller() {
  FastLED.clear();
  Spriteopen.SetPositionFrameMotionOptions(0/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 1/*XRate*/, 0/*YChange*/, 1/*YRate*/, SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);

  for(int i = 0; i < 224; i++){
    FastLED.clear();
    EnemySprites.UpdateSprites();
    EnemySprites.RenderSprites();
    FastLED.show();
    delay(50);
  }  
}

// Fill the board with the colors
void Board::illuminate(char id, int **matrix) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int value = matrix[i][j];
      if (value == 0) {
        if (id == 'm') {
          MainSpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Blue;
        } else if (id == 'e') {
          EnemySpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Blue;
        }
      } else if (value == 1) {
        if (id == 'm') {
          MainSpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Green;
        } else if (id == 'e') {
          EnemySpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Green;
        }
      } else if (value == 2) {
        if (id == 'm') {
          MainSpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::White;
        } else if (id == 'e') {
          EnemySpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::White;
        }
      } else if (value == 3) {
        if (id == 'm') {
          MainSpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Red;
        } else if (id == 'e') {
          EnemySpriteBoardCols[SHAPE_WIDTH * i + j] = CRGB::Red;
        }
      }
    }
  }

  MainSprites.UpdateSprites();
  MainSprites.RenderSprites();
  EnemySprites.UpdateSprites();
  EnemySprites.RenderSprites();
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

void Board::setCursor(char id, int x, int y, int length, int orientation) {
  static int x_t = x;
  static int y_t = y;
  static int orientation_t = orientation;

  // Validates if the line can be displayed, if not, it will be displayed in the last position
  if (!(x >= 0 && x <= SHAPE_WIDTH - length) && orientation_t == Horizontal) {
    x = SHAPE_WIDTH - length + 1;
  }
  if (!(y >= 0 && y <= SHAPE_HEIGHT - length) && orientation_t == Vertical) {
    y = SHAPE_HEIGHT - length + 1;
  }

  // Update the global variables
  cursorX = x;
  cursorY = y;

  // Backup the current colors of the board
  if (colors.size() == 0) {
    colors.reserve(SHAPE_WIDTH * SHAPE_HEIGHT); // reserve memory for all pixels

    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= cols; j++) {
        colors.push_back(Board::getPixel(id, i, j));
      }
    }
  }

  // If the cursor has moved, or the orientation has changed
  if (x != x_t || y != y_t || orientation != orientation_t) {
    // Restore the previous colors
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int index = i * cols + j;
        Board::setPixel(id, i + 1, j + 1, colors[index]);
      }
    }

    // Update the variables
    x_t = x;
    y_t = y;
    cursorX = x;
    cursorY = y;
    orientation_t = orientation;
  }

  // Display the cursor
  if (orientation_t == Horizontal) {
    Board::setHorizontalLine(id, x_t, y_t, length, Red);
  } else if (orientation_t == Vertical) {
    Board::setVerticalLine(id, x_t, y_t, length, Red);
  }

  Board::print();
}

int Board::getCursorX() {
  return cursorX;
}

int Board::getCursorY() {
  return cursorY;
}

// id = 'm' for main board, 'e' for enemy board
int Board::getPixel(char id, int x, int y) {
  return id == 'm' ? main[y - 1][x - 1] : enemy[y - 1][x - 1];
}

void Board::setPixel(char id, int x, int y, int value) {
  id == 'm' ? main[y - 1][x - 1] = value : enemy[y - 1][x - 1] = value;
}

void Board::setHorizontalLine(char id, int x, int y, int length, int color) {
  for (int i = 0; i < length; i++) {
    int x_t = x + i;
    if (x_t >= 0 && x_t <= SHAPE_WIDTH) {
      Board::setPixel(id, x_t, y, color);
    }
  }
}

void Board::setVerticalLine(char id, int x, int y, int length, int color) {
  for (int i = 0; i < length; i++) {
    int y_t = y + i;
    if (y_t >= 0 && y_t <= SHAPE_HEIGHT) {
      Board::setPixel(id, x, y_t, color);
    }
  }
}
