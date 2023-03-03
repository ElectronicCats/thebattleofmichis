#include "Game.h"

Game::Game() {

}

void Game::start() {
  Game::setup();
  unsigned long time = millis();
  static unsigned long lastTime = time;
  int counter = 0;

  for(;;) {
    // Logic game goes here
    player1.joystick.loop();

    player1.setCursor('e', 2, 6);

    if (player1.joystick.button.isPressed()) {
      counter++;
    }

    if (millis() - lastTime >= 200) {
      lastTime = millis();
      Serial.println("Counter: " + String(counter));
      player1.joystick.printDirection();
    }
  }
}

void Game::setup() {
  // Created
  Serial.println("Ship 1 created: " + String(player1.createShip(5, 8, 8, 8)));
  // Created
  Serial.println("Ship 2 created: " + String(player1.createShip(1, 6, 2, 6)));
  Serial.println("Ship 3 created: " + String(player1.createShip(8, 1, 8, 2)));
  delay(5000);

  player1.placeShip(player1.getShip(0));
  player1.placeShip(player1.getShip(1));
  player1.placeShip(player1.getShip(2));
  player1.printBoard();
  delay(1000);

  player1.hit(5, 8);
  player1.printBoard();
  delay(1000);
  player1.hit(3, 6);
  player1.printBoard();
  delay(1000);
  player1.hit(6, 8);
  player1.printBoard();
  delay(1000);
  player1.hit(7, 8);
  player1.printBoard();
  delay(1000);
  player1.hit(8, 8);
  player1.printBoard();
}
