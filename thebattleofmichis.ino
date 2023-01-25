#include "Game.h"

Game game;

void setup() {
  Serial.begin(115200);
}

void loop() {
  game.start();
}