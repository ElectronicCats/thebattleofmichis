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

const uint8_t SpritesetupData[] = {
  B8_3BIT(00000000),B8_3BIT(00000000),B8_3BIT(00000000),B8_3BIT(00010000),B8_3BIT(00000000),B8_3BIT(00002200),B8_3BIT(22200222),B8_3BIT(00202002),B8_3BIT(22000002),B8_3BIT(02000220),B8_3BIT(02020022),B8_3BIT(20000002),B8_3BIT(20020200),B8_3BIT(22002220),B8_3BIT(02200000),B8_3BIT(00000000),B8_3BIT(00000000),B8_3BIT(10000000),B8_3BIT(00000000),B8_3BIT(00000000),
  B8_3BIT(00000000),B8_3BIT(00000000),B8_3BIT(00000000),B8_3BIT(11110000),B8_3BIT(00000000),B8_3BIT(00020200),B8_3BIT(20000020),B8_3BIT(00202002),B8_3BIT(02000002),B8_3BIT(02002020),B8_3BIT(02020020),B8_3BIT(20000020),B8_3BIT(20020200),B8_3BIT(02002020),B8_3BIT(20200000),B8_3BIT(00000000),B8_3BIT(00000111),B8_3BIT(11044000),B8_3BIT(00000000),B8_3BIT(00000000),
  B8_3BIT(00000000),B8_3BIT(00000000),B8_3BIT(00400040),B8_3BIT(00100400),B8_3BIT(00000000),B8_3BIT(00020000),B8_3BIT(20000020),B8_3BIT(00202002),B8_3BIT(02000002),B8_3BIT(02002020),B8_3BIT(02020020),B8_3BIT(20000020),B8_3BIT(00020200),B8_3BIT(02002020),B8_3BIT(20000000),B8_3BIT(00000000),B8_3BIT(00400011),B8_3BIT(01004000),B8_3BIT(00000000),B8_3BIT(00000000),
  B8_3BIT(00000000),B8_3BIT(00000000),B8_3BIT(44404440),B8_3BIT(11110444),B8_3BIT(00000000),B8_3BIT(00002200),B8_3BIT(22000020),B8_3BIT(00202002),B8_3BIT(22000000),B8_3BIT(22002020),B8_3BIT(02020022),B8_3BIT(20000002),B8_3BIT(20022200),B8_3BIT(02002220),B8_3BIT(02200000),B8_3BIT(00000000),B8_3BIT(44401111),B8_3BIT(01044400),B8_3BIT(00000000),B8_3BIT(00000000),
  B8_3BIT(00000000),B8_3BIT(00000005),B8_3BIT(55555555),B8_3BIT(55555555),B8_3BIT(50000000),B8_3BIT(00000200),B8_3BIT(20000020),B8_3BIT(00202002),B8_3BIT(00000000),B8_3BIT(20002020),B8_3BIT(02020022),B8_3BIT(00000000),B8_3BIT(20020200),B8_3BIT(02002000),B8_3BIT(00200000),B8_3BIT(00000055),B8_3BIT(55555555),B8_3BIT(55555555),B8_3BIT(00000000),B8_3BIT(00000000),
  B8_3BIT(00000000),B8_3BIT(00000000),B8_3BIT(11110101),B8_3BIT(01011111),B8_3BIT(10000000),B8_3BIT(00020200),B8_3BIT(20000020),B8_3BIT(00202002),B8_3BIT(00000000),B8_3BIT(20002020),B8_3BIT(02020020),B8_3BIT(20000020),B8_3BIT(20020200),B8_3BIT(02002000),B8_3BIT(20200000),B8_3BIT(00000001),B8_3BIT(11101010),B8_3BIT(10111111),B8_3BIT(00000000),B8_3BIT(00000000),
  B8_3BIT(00000000),B8_3BIT(00000000),B8_3BIT(01111111),B8_3BIT(11111111),B8_3BIT(00000000),B8_3BIT(00002200),B8_3BIT(22200020),B8_3BIT(00022002),B8_3BIT(00000000),B8_3BIT(20000220),B8_3BIT(00220020),B8_3BIT(20000002),B8_3BIT(20020200),B8_3BIT(22002000),B8_3BIT(02200000),B8_3BIT(00000000),B8_3BIT(11111111),B8_3BIT(11111110),B8_3BIT(00000000),B8_3BIT(00000000),
  B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333),B8_3BIT(33333333) };
const struct CRGB SpritesetupCols[7] = { CRGB(255,255,255), CRGB(254,255,0), CRGB(0,169,255), CRGB(170,170,170), CRGB(85,85,85), CRGB(0,0,0), CRGB(0,0,0) };
cSprite Spritesetup(160, 8, SpritesetupData, 1, _3BIT, SpritesetupCols);

cLEDSprites MainSprites(&mainBoardUp);
cLEDSprites EnemySprites(&enemyBoardUp);

Board::Board(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  this->main = new int*[rows];
  this->enemy = new int*[rows];
  this->cursorX = 0;
  this->cursorY = 0;

  // Create the main board
  for (int row = 0; row < rows; row++) {
    main[row] = new int[cols];
  }

  // Create the enemy board
  for (int row = 0; row < rows; row++) {
    enemy[row] = new int[cols];
  }

  Board::clear('m');
}

// Print the matrix on the serial monitor
void Board::serialPrint(int **matrix) {
  Serial.print("  |");
  for (int i = 1; i <= cols; i++) {
      Serial.print(" ");
      Serial.print(i);
      Serial.print(" |");
  }
  Serial.println("\n  --------------------------------------");

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
void Board::print(int state) {
  static unsigned long lastTime = millis();
  if (millis() - lastTime > 3000) {
    lastTime = millis();
    Board::serialPrint(main);
  }
  // Board::serialPrint(enemy);

  FastLED.addLeds<CHIPSET, PIN_MATRIX_1, COLOR_ORDER>(mainBoardUp[0], mainBoardUp.Size());
  FastLED.addLeds<CHIPSET, PIN_MATRIX_2, COLOR_ORDER>(enemyBoardUp[0], enemyBoardUp.Size());
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  
  MainSprites.AddSprite(&MainSpriteBoard);

  if(state)
    EnemySprites.AddSprite(&EnemySpriteBoard);
  
  Board::illuminate('m', main);
  Board::illuminate('e', enemy);
}

// LED banner test
void Board::scroller(int id) {
  static int counter = 0;
  static unsigned long lastTime = millis();

  if (millis() - lastTime > 100) {
    // Serial.println("Counter: " + String(counter));
    lastTime = millis();
    counter++;
 
    Board::print(0);    
    
    if (counter > 105) {
      counter = 0;
    }
  }

  if (counter == 0) {

    if(id == 1){
      EnemySprites.AddSprite(&Spriteopen);
      EnemySprites.ChangePriority(&Spriteopen, SPR_FRONT);
      Spriteopen.SetPositionFrameMotionOptions(0/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 1/*XRate*/, 0/*YChange*/, 1/*YRate*/, SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);
    }
    else if(id == 2) {
         EnemySprites.AddSprite(&Spritesetup);
         EnemySprites.ChangePriority(&Spritesetup, SPR_FRONT);
         Spritesetup.SetPositionFrameMotionOptions(0/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 1/*XRate*/, 0/*YChange*/, 1/*YRate*/, SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);
    }
    else if(id == 3) {
         EnemySprites.AddSprite(&Spriteyouwin);
         EnemySprites.ChangePriority(&Spriteyouwin, SPR_FRONT);
         Spriteyouwin.SetPositionFrameMotionOptions(0/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 1/*XRate*/, 0/*YChange*/, 1/*YRate*/, SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);
    }
    else if(id == 4) {
         EnemySprites.AddSprite(&Spriteyoulose);
         EnemySprites.ChangePriority(&Spriteyoulose, SPR_FRONT);
         Spriteyoulose.SetPositionFrameMotionOptions(0/*X*/, 0/*Y*/, 0/*Frame*/, 0/*FrameRate*/, -1/*XChange*/, 1/*XRate*/, 0/*YChange*/, 1/*YRate*/, SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN);
    }
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
  FastLED.clear();
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
      main[row][col] = Green;
    }
  }
}

void Board::setCursor(char id, int x, int y, int length, int orientation, int color) {
  static int x_t = x;
  static int y_t = y;
  static int orientation_t = orientation;
  // TODO: init the enemy colors vector

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
  if (mainColors.size() == 0) {
    mainColors.reserve(SHAPE_WIDTH * SHAPE_HEIGHT); // reserve memory for all pixels

    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= cols; j++) {
        mainColors.push_back(Board::getPixel(id, i, j));
      }
    }
  }

  // If the cursor has moved, or the orientation has changed
  if (x != x_t || y != y_t || orientation != orientation_t) {
    // Restore the previous colors
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int index = i * cols + j;
        Board::setPixel(id, i + 1, j + 1, mainColors[index]);
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
    Board::setHorizontalLine(id, x_t, y_t, length, color);
  } else if (orientation_t == Vertical) {
    Board::setVerticalLine(id, x_t, y_t, length, color);
  }

  Board::print(1);
}

void Board::clear(char id) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      Board::setPixel(id, i + 1, j + 1, Blue);
    }
  }
  id == 'm' ? mainColors.clear() : enemyColors.clear();

  // Fill the main board with 0
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      main[row][col] = 0;
    }
  }

  // Fill the enemy board with 0
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      enemy[row][col] = 0;
    }
  }
}

int Board::getCursorX() {
  return cursorX;
}

int Board::getCursorY() {
  return cursorY;
}

void Board::resetEnemyColors() {
  enemyColors.clear();
}

void Board::resetMainColors() {
  mainColors.clear();
}

// id = 'm' for main board, 'e' for enemy board
int Board::getPixel(char id, int x, int y) {
  return id == 'm' ? main[y - 1][x - 1] : enemy[y - 1][x - 1];
}

void Board::setPixel(char id, int x, int y, int value) {
  int index = x * cols + y;
  id == 'm' ? main[y - 1][x - 1] = value : enemy[y - 1][x - 1] = value;
  // id == 'm' ? mainColors[index] = value : enemyColors[index] = value;
}

int Board::getColor(char id, int x, int y) {
  int index = x * cols + y;
  return id == 'm' ? mainColors[index] : enemyColors[index];
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
