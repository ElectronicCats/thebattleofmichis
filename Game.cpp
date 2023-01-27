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
  player1.setDestroyer(2, 2, 4, 2);

  player1.printBoard();
  player1.placeShip(player1.getDestroyer());
  player1.printBoard();
}