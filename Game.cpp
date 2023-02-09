#include "Game.h"

Game::Game() {

}

void Game::start() {
  Game::setup();

  for(;;) {
    // Logic game goes here
    delay(10000);
  }
}

void Game::setup() {
  // Created
  Serial.println("Ship 1 created: " + String(player1.createShip(5, 8, 8, 8)));
  // Created
  Serial.println("Ship 2 created: " + String(player1.createShip(1, 6, 2, 6)));
  // Not created
  Serial.println("Ship 3 created: " + String(player1.createShip(1, 6, 2, 6)));
  // Not created
  Serial.println("Ship 4 created: " + String(player1.createShip(5, 8, 5, 9)));
  player1.printBoard();
  delay(5000);

  player1.placeShip(player1.getShip(0));
  player1.placeShip(player1.getShip(1));
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