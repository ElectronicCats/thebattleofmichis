#include <FastLED.h>

#include <LEDMatrix.h>
#include <LEDSprites.h>

// Change the next 6 defines to match your matrix type and size

#define LED_PIN        4
#define COLOR_ORDER    RGB
#define CHIPSET        WS2812B

#define MATRIX_WIDTH   8
#define MATRIX_HEIGHT  8
#define MATRIX_TYPE    VERTICAL_ZIGZAG_MATRIX

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;

#define SHAPE_WIDTH    74
#define SHAPE_HEIGHT   8

const uint8_t SpritesqData[] = {
  B8_5BIT(00000001),B8_5BIT(01002200),B8_5BIT(00000000),B8_5BIT(03400000),B8_5BIT(00000000),B8_5BIT(00500500),B8_5BIT(00000005),B8_5BIT(06660500),B8_5BIT(00000000),B8_5BIT(00000000),
  B8_5BIT(00000071),B8_5BIT(11078700),B8_5BIT(00000000),B8_5BIT(33340000),B8_5BIT(00000055),B8_5BIT(00950900),B8_5BIT(000000AA),B8_5BIT(BA6CC900),B8_5BIT(00000000),B8_5BIT(00000000),
  B8_5BIT(00000085),B8_5BIT(15188700),B8_5BIT(00000000),B8_5BIT(53540000),B8_5BIT(00000055),B8_5BIT(666DEE00),B8_5BIT(0000005A),B8_5BIT(9B59CC00),B8_5BIT(00000000),B8_5BIT(00000000),
  B8_5BIT(00000081),B8_5BIT(11117800),B8_5BIT(00000030),B8_5BIT(0FFC0300),B8_5BIT(00000056),B8_5BIT(69D5E500),B8_5BIT(000000AA),B8_5BIT(BB5ABC00),B8_5BIT(00000000),B8_5BIT(00000000),
  B8_5BIT(00000018),B8_5BIT(GG281800),B8_5BIT(00000003),B8_5BIT(6GG63000),B8_5BIT(0000009C),B8_5BIT(C9DDHE00),B8_5BIT(00000056),B8_5BIT(6G5AAB00),B8_5BIT(00000000),B8_5BIT(00000000),
  B8_5BIT(00000088),B8_5BIT(GG218800),B8_5BIT(00000000),B8_5BIT(GGGGC400),B8_5BIT(0000009C),B8_5BIT(CI6GG000),B8_5BIT(0000000G),B8_5BIT(GG659900),B8_5BIT(00000000),B8_5BIT(00000000),
  B8_5BIT(00000001),B8_5BIT(2GG12200),B8_5BIT(00000000),B8_5BIT(3663C400),B8_5BIT(00000009),B8_5BIT(IEGG6E00),B8_5BIT(000000AA),B8_5BIT(6CCAB900),B8_5BIT(00000000),B8_5BIT(00000000),
  B8_5BIT(00000001),B8_5BIT(10017000),B8_5BIT(00000000),B8_5BIT(30003000),B8_5BIT(00000000),B8_5BIT(DE00E000),B8_5BIT(000000AB),B8_5BIT(000AB000),B8_5BIT(00000000),B8_5BIT(00000000) };
const struct CRGB SpritesqCols[31] = { CRGB(247,97,0), CRGB(192,57,0), CRGB(95,205,228), CRGB(44,133,129), CRGB(255,255,255), CRGB(188,120,22), CRGB(137,41,0), CRGB(5,59,37), CRGB(149,179,239), CRGB(55,100,224), CRGB(9,56,184), CRGB(110,61,14), CRGB(31,26,177), CRGB(60,55,208), CRGB(17,83,94), CRGB(255,204,17),
   CRGB(220,40,40), CRGB(102,120,208), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0) };
cSprite Spritesq(74, 8, SpritesqData, 1, _5BIT, SpritesqCols);


cLEDSprites Sprites(&leds);



void setup()
{
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.setBrightness(8);
  FastLED.clear(true);
  delay(500);
  FastLED.showColor(CRGB::Blue);
  delay(1000);
  FastLED.show();

  //Spritesq.SetPositionFrameMotionOptions(0/*X*/, -8/*Y*/, 0/*Frame*/, 0/*FrameRate*/, 0/*XChange*/, 1/*XRate*/, 1/*YChange*/, 1/*YRate*/, SPRITE_DETECT_EDGE | SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);
  Sprites.AddSprite(&Spritesq);
}

int y_pos = -8;
int y_change = 1;
void loop()
{

  FastLED.clear();
    {
      int y_pos = 16;
      int y_change = -1;
      FastLED.clear();
      Spritesq.SetPositionFrameMotionOptions(16/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 1/*XRate*/, 0/*YChange*/, 1/*YRate*/, SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);
  
      for(int i=0;i<SHAPE_WIDTH + 8;i++){
        y_pos+=y_change;
        FastLED.clear();
        if(y_pos == 16)
        {
        y_change = -y_change;
        Spritesq.SetPositionFrameMotionOptions(16/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 1/*XRate*/, 0/*YChange*/, 1/*YRate*/, SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);  
        }
        
        if(y_pos == -7 || y_pos == -23 || y_pos == -39 || y_pos == -55){
          delay(2000);
        }
        
        Sprites.UpdateSprites();
        Sprites.RenderSprites();
        FastLED.show();
        delay(50);
      }

      FastLED.clear(true);
    }
  delay(1000);
}
