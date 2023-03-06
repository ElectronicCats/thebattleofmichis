#include <FastLED.h>

#include <LEDMatrix.h>
#include <LEDSprites.h>

// Change the next 6 defines to match your matrix type and size

#define LED_PIN        4
#define COLOR_ORDER    RGB
#define CHIPSET        WS2812B

#define MATRIX_WIDTH   -8
#define MATRIX_HEIGHT  8
#define MATRIX_TYPE    VERTICAL_ZIGZAG_MATRIX

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;

#define SHAPE_WIDTH    224
#define SHAPE_HEIGHT   8


const uint8_t SpriteopenData[] = {
  B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00000001),B8_4BIT(11200000),B8_4BIT(00000000),B8_4BIT(00333000),B8_4BIT(00333000),B8_4BIT(00000000),B8_4BIT(44444000),B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00044000),B8_4BIT(44000000),B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00000500),B8_4BIT(00005000),B8_4BIT(00000000),B8_4BIT(10000011),B8_4BIT(12100100),B8_4BIT(00000000),B8_4BIT(00000000),
  B8_4BIT(00000000),B8_4BIT(00000001),B8_4BIT(00010002),B8_4BIT(22200010),B8_4BIT(00000000),B8_4BIT(03000300),B8_4BIT(03000300),B8_4BIT(00000000),B8_4BIT(44004400),B8_4BIT(00000000),B8_4BIT(44000004),B8_4BIT(40004440),B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00004440),B8_4BIT(00044404),B8_4BIT(44004400),B8_4BIT(00000044),B8_4BIT(00000044),B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(00000550),B8_4BIT(00055000),B8_4BIT(00000000),B8_4BIT(01000022),B8_4BIT(22206611),B8_4BIT(10000000),B8_4BIT(00000000),
  B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(16001601),B8_4BIT(12106100),B8_4BIT(00000000),B8_4BIT(30030030),B8_4BIT(30000030),B8_4BIT(00000000),B8_4BIT(44004400),B8_4BIT(44440044),B8_4BIT(44440444),B8_4BIT(44400440),B8_4BIT(00444400),B8_4BIT(00004444),B8_4BIT(00044000),B8_4BIT(00044444),B8_4BIT(44000000),B8_4BIT(04444044),B8_4BIT(00000000),B8_4BIT(00044444),B8_4BIT(00000000),B8_4BIT(00050555),B8_4BIT(55555050),B8_4BIT(00000001),B8_4BIT(11160112),B8_4BIT(21206660),B8_4BIT(00000000),B8_4BIT(00000000),
  B8_4BIT(00000000),B8_4BIT(00000006),B8_4BIT(66066602),B8_4BIT(22206660),B8_4BIT(00000000),B8_4BIT(30333003),B8_4BIT(00333030),B8_4BIT(00000000),B8_4BIT(44444000),B8_4BIT(00044000),B8_4BIT(44000004),B8_4BIT(40000440),B8_4BIT(04400440),B8_4BIT(00044004),B8_4BIT(40444440),B8_4BIT(00044040),B8_4BIT(44044400),B8_4BIT(44000044),B8_4BIT(44400444),B8_4BIT(00440000),B8_4BIT(00000000),B8_4BIT(00005505),B8_4BIT(55505500),B8_4BIT(00000000),B8_4BIT(06660222),B8_4BIT(21206660),B8_4BIT(00000000),B8_4BIT(00000000),
  B8_4BIT(00000000),B8_4BIT(00000077),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(00000000),B8_4BIT(30030030),B8_4BIT(30000030),B8_4BIT(00000000),B8_4BIT(44004400),B8_4BIT(44444000),B8_4BIT(44000004),B8_4BIT(40000440),B8_4BIT(04444440),B8_4BIT(00044004),B8_4BIT(40044000),B8_4BIT(00044000),B8_4BIT(44004400),B8_4BIT(44000044),B8_4BIT(00440044),B8_4BIT(00044440),B8_4BIT(00000000),B8_4BIT(00550500),B8_4BIT(55005055),B8_4BIT(00000007),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(70000000),B8_4BIT(00000000),
  B8_4BIT(00000000),B8_4BIT(00000002),B8_4BIT(22212121),B8_4BIT(21222222),B8_4BIT(00000000),B8_4BIT(03000300),B8_4BIT(03000300),B8_4BIT(00000000),B8_4BIT(44004404),B8_4BIT(40044000),B8_4BIT(44000004),B8_4BIT(40000440),B8_4BIT(04400000),B8_4BIT(00044004),B8_4BIT(40044000),B8_4BIT(00044000),B8_4BIT(44004400),B8_4BIT(44000044),B8_4BIT(00440044),B8_4BIT(00000044),B8_4BIT(00000000),B8_4BIT(00005555),B8_4BIT(55555500),B8_4BIT(00000000),B8_4BIT(22221212),B8_4BIT(12122222),B8_4BIT(20000000),B8_4BIT(00000000),
  B8_4BIT(00000000),B8_4BIT(00000000),B8_4BIT(22222222),B8_4BIT(22222220),B8_4BIT(00000000),B8_4BIT(00333000),B8_4BIT(00333000),B8_4BIT(00000000),B8_4BIT(44444000),B8_4BIT(44444000),B8_4BIT(04440000),B8_4BIT(44404444),B8_4BIT(00444400),B8_4BIT(00004444),B8_4BIT(00044000),B8_4BIT(00044000),B8_4BIT(44044440),B8_4BIT(04444044),B8_4BIT(00440444),B8_4BIT(40444440),B8_4BIT(00000000),B8_4BIT(00050055),B8_4BIT(55550050),B8_4BIT(00000000),B8_4BIT(02222222),B8_4BIT(22222222),B8_4BIT(00000000),B8_4BIT(00000000),
  B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888898),B8_4BIT(88888888),B8_4BIT(88888888),B8_4BIT(88888888) };
const struct CRGB SpriteopenCols[15] = { CRGB(51,51,51), CRGB(179,179,179), CRGB(247,255,232), CRGB(186,63,208), CRGB(255,255,255), CRGB(128,128,128), CRGB(115,99,86), CRGB(40,171,227), CRGB(39,171,229), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0) };
cSprite Spriteopen(224, 8, SpriteopenData, 1, _4BIT, SpriteopenCols);

const uint8_t SpriteyouwinData[] = {
  B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11222311),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11441144),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(14411144),B8_4BIT(11444411),B8_4BIT(14411441),B8_4BIT(11144111),B8_4BIT(11111111),B8_4BIT(11111121),B8_4BIT(11112223),B8_4BIT(21121111),B8_4BIT(11111111),B8_4BIT(11111111),
  B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11211121),B8_4BIT(11333311),B8_4BIT(12111111),B8_4BIT(11111111),B8_4BIT(11441144),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(14411144),B8_4BIT(11144111),B8_4BIT(14441441),B8_4BIT(11144111),B8_4BIT(11111111),B8_4BIT(11111112),B8_4BIT(11113333),B8_4BIT(31552221),B8_4BIT(11111111),B8_4BIT(11111111),
  B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11125112),B8_4BIT(51223215),B8_4BIT(21111111),B8_4BIT(11111111),B8_4BIT(11441144),B8_4BIT(11144441),B8_4BIT(11441144),B8_4BIT(11111111),B8_4BIT(14411144),B8_4BIT(11144111),B8_4BIT(14444441),B8_4BIT(11144111),B8_4BIT(11111111),B8_4BIT(11111222),B8_4BIT(25122332),B8_4BIT(31555111),B8_4BIT(11111111),B8_4BIT(11111111),
  B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11555155),B8_4BIT(51333315),B8_4BIT(55111111),B8_4BIT(11111111),B8_4BIT(11144441),B8_4BIT(11441144),B8_4BIT(11441144),B8_4BIT(11111111),B8_4BIT(14414144),B8_4BIT(11144111),B8_4BIT(14444441),B8_4BIT(11144111),B8_4BIT(11111111),B8_4BIT(11111115),B8_4BIT(55133332),B8_4BIT(31555111),B8_4BIT(11111111),B8_4BIT(11111111),
  B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(16666666),B8_4BIT(66666666),B8_4BIT(66611111),B8_4BIT(11111111),B8_4BIT(11114411),B8_4BIT(11441144),B8_4BIT(11441144),B8_4BIT(11111111),B8_4BIT(14444444),B8_4BIT(11144111),B8_4BIT(14414441),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111666),B8_4BIT(66666666),B8_4BIT(66666661),B8_4BIT(11111111),B8_4BIT(11111111),
  B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11333323),B8_4BIT(23232333),B8_4BIT(33311111),B8_4BIT(11111111),B8_4BIT(11114411),B8_4BIT(11441144),B8_4BIT(11441144),B8_4BIT(11111111),B8_4BIT(14441444),B8_4BIT(11144111),B8_4BIT(14411441),B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11111133),B8_4BIT(33232323),B8_4BIT(23333331),B8_4BIT(11111111),B8_4BIT(11111111),
  B8_4BIT(11111111),B8_4BIT(11111111),B8_4BIT(11133333),B8_4BIT(33333333),B8_4BIT(33111111),B8_4BIT(11111111),B8_4BIT(11114411),B8_4BIT(11144441),B8_4BIT(11144444),B8_4BIT(11111111),B8_4BIT(14411144),B8_4BIT(11444411),B8_4BIT(14411441),B8_4BIT(11144111),B8_4BIT(11111111),B8_4BIT(11111113),B8_4BIT(33333333),B8_4BIT(33333311),B8_4BIT(11111111),B8_4BIT(11111111),
  B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77778777),B8_4BIT(77777777),B8_4BIT(77777777),B8_4BIT(77777777) };
const struct CRGB SpriteyouwinCols[15] = { CRGB(0,18,255), CRGB(51,51,51), CRGB(179,179,179), CRGB(252,255,0), CRGB(128,128,128), CRGB(115,99,86), CRGB(40,171,227), CRGB(39,171,229), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0) };
cSprite Spriteyouwin(160, 8, SpriteyouwinData, 1, _4BIT, SpriteyouwinCols);

const uint8_t SpriteyouloseData[] = {
  B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111110),B8_3BIT(01110111),B8_3BIT(11111211),B8_3BIT(11113311),B8_3BIT(33111111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11331111),B8_3BIT(11333311),B8_3BIT(11333311),B8_3BIT(13333331),B8_3BIT(11131111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111111),
  B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11101110),B8_3BIT(00000111),B8_3BIT(11113231),B8_3BIT(11113311),B8_3BIT(33111111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11331111),B8_3BIT(13311331),B8_3BIT(13311331),B8_3BIT(13311111),B8_3BIT(11111111),B8_3BIT(11111011),B8_3BIT(31111111),B8_3BIT(12111111),B8_3BIT(11111111),B8_3BIT(11111111),
  B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11113231),B8_3BIT(11011100),B8_3BIT(00000101),B8_3BIT(11112221),B8_3BIT(11113311),B8_3BIT(33111333),B8_3BIT(31113311),B8_3BIT(33111111),B8_3BIT(11331111),B8_3BIT(13311331),B8_3BIT(13311111),B8_3BIT(13311111),B8_3BIT(11111111),B8_3BIT(11111003),B8_3BIT(31111111),B8_3BIT(23211111),B8_3BIT(11111111),B8_3BIT(11111111),
  B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11112221),B8_3BIT(11011110),B8_3BIT(03003011),B8_3BIT(11113231),B8_3BIT(11111333),B8_3BIT(31113311),B8_3BIT(33113311),B8_3BIT(33111111),B8_3BIT(11331111),B8_3BIT(13311331),B8_3BIT(11333311),B8_3BIT(13333111),B8_3BIT(11111113),B8_3BIT(11111202),B8_3BIT(31301111),B8_3BIT(12111111),B8_3BIT(11111111),B8_3BIT(11111111),
  B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11113231),B8_3BIT(11011100),B8_3BIT(00000101),B8_3BIT(11111211),B8_3BIT(11111133),B8_3BIT(11113311),B8_3BIT(33113311),B8_3BIT(33111111),B8_3BIT(11331111),B8_3BIT(13311331),B8_3BIT(11111331),B8_3BIT(13311111),B8_3BIT(11111112),B8_3BIT(11111023),B8_3BIT(01131111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111111),
  B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11101110),B8_3BIT(02221111),B8_3BIT(11111111),B8_3BIT(11111133),B8_3BIT(11113311),B8_3BIT(33113311),B8_3BIT(33111111),B8_3BIT(11331111),B8_3BIT(13311331),B8_3BIT(13311331),B8_3BIT(13311111),B8_3BIT(11111322),B8_3BIT(23111132),B8_3BIT(20301111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111111),
  B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11110000),B8_3BIT(00201111),B8_3BIT(11211111),B8_3BIT(11111133),B8_3BIT(11111333),B8_3BIT(31111333),B8_3BIT(33111111),B8_3BIT(11333333),B8_3BIT(11333311),B8_3BIT(11333311),B8_3BIT(13333331),B8_3BIT(11111112),B8_3BIT(11111122),B8_3BIT(22011111),B8_3BIT(11111111),B8_3BIT(11111111),B8_3BIT(11111111),
  B8_3BIT(44444444),B8_3BIT(44444444),B8_3BIT(44441111),B8_3BIT(31110000),B8_3BIT(20002111),B8_3BIT(12321114),B8_3BIT(44444444),B8_3BIT(44444444),B8_3BIT(44444444),B8_3BIT(44444444),B8_3BIT(44444444),B8_3BIT(44444444),B8_3BIT(44444444),B8_3BIT(44444444),B8_3BIT(44441113),B8_3BIT(11111102),B8_3BIT(10311111),B8_3BIT(11314444),B8_3BIT(44444444),B8_3BIT(44444444) };
const struct CRGB SpriteyouloseCols[7] = { CRGB(53,65,82), CRGB(255,255,255), CRGB(255,255,0), CRGB(0,255,255), CRGB(0,0,0), CRGB(0,0,0), CRGB(0,0,0) };
cSprite Spriteyoulose(160, 8, SpriteyouloseData, 1, _3BIT, SpriteyouloseCols);




cLEDSprites Sprites(&leds);



void setup()
{
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.setBrightness(8);
  Sprites.AddSprite(&Spriteopen);
  //Sprites.AddSprite(&Spriteyoulose);
  //Sprites.AddSprite(&Spriteyouwin);
}

void loop()
{


  FastLED.clear();
  Spriteopen.SetPositionFrameMotionOptions(0/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 1/*XRate*/, 0/*YChange*/, 1/*YRate*/, SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);

  for(int i = 0; i < SHAPE_WIDTH; i++){
    FastLED.clear();
    Sprites.UpdateSprites();
    Sprites.RenderSprites();
    FastLED.show();
    delay(50);
  }  

}
