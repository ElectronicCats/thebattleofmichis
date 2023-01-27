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
  player1.setDestroyer(2, 2, 3, 2);
  player1.setSubmarine(3, 3, 3, 5);
  player1.hit(2, 2);
  Serial.println("Sunken ships: " + String(player1.getSunkenShips()));
  player1.hit(3, 2);
  Serial.println("Sunken ships: " + String(player1.getSunkenShips()));

  player1.printBoard();

  player1.placeShip(player1.getDestroyer());
  player1.placeShip(player1.getSubmarine());

  player1.printBoard();
}