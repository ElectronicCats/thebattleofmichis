#include <FastLED.h>

#include <LEDMatrix.h>
#include <LEDSprites.h>

// Change the next 6 defines to match your matrix type and size

#define LED_PIN        4
#define COLOR_ORDER    RGB
#define CHIPSET        WS2812B

#define MATRIX_WIDTH   16
#define MATRIX_HEIGHT  -8
#define MATRIX_TYPE    HORIZONTAL_MATRIX

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;


#define SHAPE_WIDTH    8
#define SHAPE_HEIGHT   8

const uint8_t SpriteBoardData[] = {
  0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,
  0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,
  0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,
  0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,0x40,
  0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50,
  0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,0x60,
  0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70,
  0x71,0x72,0x73,0x74,0x75,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F };
  
struct CRGB SpriteBoardCols[128]; 

cSprite SpriteBoard(16, 8, SpriteBoardData, 1, _8BIT, SpriteBoardCols);

cLEDSprites Sprites(&leds);

uint8_t x,y;

int mapa[64] = {56, 55, 40, 39, 24, 23,  8,  7,
                 57, 54, 41, 38, 25, 22,  9,  6,
                 58, 53, 42, 37, 26, 21, 10,  5,
                 59, 52, 43, 36, 27, 20, 11,  4,
                 60, 51, 44, 35, 28, 19, 12,  3,
                 61, 50, 45, 34, 29, 18, 13,  2,
                 62, 49, 46, 33, 30, 17, 14,  1,
                 63, 48, 47, 32, 31, 16, 15,  0};

void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.setBrightness(128);
  FastLED.clear(true);
  delay(500);
  FastLED.showColor(CRGB::Blue);
  delay(1000);
  FastLED.show();

  SpriteBoard.SetPositionFrameMotionOptions(0/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 0/*XRate*/, 0/*YChange*/, 0/*YRate*/, SPRITE_DETECT_EDGE | SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);
  Sprites.AddSprite(&SpriteBoard);

  x = 0;
  y = 0;
}

int map_led(int pos_a) {
  return mapa[pos_a];
}


void loop()
{
  FastLED.clear();

  //if(x == 0 && y == 0)SpriteBoardCols[map_led(SHAPE_WIDTH * SHAPE_WIDTH -1)] = CRGB::Black; 
  SpriteBoardCols[map_led(SHAPE_WIDTH * y + x)] = CRGB::Blue;
  if(x == 0 && y == 0)
    SpriteBoardCols[map_led(SHAPE_WIDTH * SHAPE_WIDTH -1)] = CRGB::Black;
  else
    SpriteBoardCols[map_led(SHAPE_WIDTH * y + x -1)] = CRGB::Black;
    
  x++;
  if(x == SHAPE_WIDTH){y++;x = 0;}
  if(y == SHAPE_HEIGHT){
    x = 0;
    y = 0;  
  }
  
  Sprites.UpdateSprites();
  Sprites.RenderSprites();
  FastLED.show();
  delay(100);
}
