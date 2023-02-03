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

const uint8_t SpriteBoardUData[] = {
  0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
  0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,
  0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,
  0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,
  0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,
  0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,
  0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
  0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,0x40
  };

const uint8_t SpriteBoardDData[] = {
  0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
  0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,
  0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,
  0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,
  0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,
  0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,
  0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
  0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,0x40
  };  
  
struct CRGB SpriteBoardUCols[64];
struct CRGB SpriteBoardDCols[64]; 

cSprite SpriteBoardU(8, 8, SpriteBoardUData, 1, _8BIT, SpriteBoardUCols);
cSprite SpriteBoardD(8, 8, SpriteBoardDData, 1, _8BIT, SpriteBoardDCols);

cLEDSprites Sprites(&leds);

uint8_t x,y,a,b;

void setup()
{
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.setBrightness(16);
  FastLED.clear(true);
  delay(500);
  FastLED.showColor(CRGB::Blue);
  delay(1000);
  FastLED.show();

  SpriteBoardU.SetPositionFrameMotionOptions(0/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 0/*XRate*/, 0/*YChange*/, 0/*YRate*/, SPRITE_DETECT_EDGE | SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);
  SpriteBoardD.SetPositionFrameMotionOptions(8/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 0/*XRate*/, 0/*YChange*/, 0/*YRate*/, SPRITE_DETECT_EDGE | SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);
  
  Sprites.AddSprite(&SpriteBoardU);
  Sprites.AddSprite(&SpriteBoardD);

  x = 0;
  y = 0;
  a = 0;
  b = 0;
}

void loop()
{
  FastLED.clear();
  
  if(x == 0 && y == 0)SpriteBoardUCols[SHAPE_WIDTH * SHAPE_WIDTH -1] = CRGB::Black;
  
  SpriteBoardUCols[SHAPE_WIDTH * y + x] = CRGB::Blue;
  
  SpriteBoardUCols[SHAPE_WIDTH * y + x - 1] = CRGB::Black;
  
  x++;
  if(x == SHAPE_WIDTH){y++;x = 0;}
  if(y == SHAPE_HEIGHT){
    x = 0;
    y = 0;  
  }

  if(a == 0 && b == 0)SpriteBoardDCols[SHAPE_WIDTH * SHAPE_WIDTH -1] = CRGB::Black;
  
  SpriteBoardDCols[SHAPE_WIDTH * b + a] = CRGB::Blue;
  
  SpriteBoardDCols[SHAPE_WIDTH * b + a - 1] = CRGB::Black;
  
  a++;
  if(a == SHAPE_WIDTH){b++;a = 0;}
  if(b == SHAPE_HEIGHT){
    a = 0;
    b = 0;  
  }
  
  Sprites.UpdateSprites();
  Sprites.RenderSprites();
  FastLED.show();
  delay(50);
}
