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
  Serial.println("Destroyer size: " + String(player1.getDestroyerSize()));

  player1.printBoard();

  player1.placeShip(player1.getDestroyer());
  player1.placeShip(player1.getSubmarine());

  player1.printBoard();
}