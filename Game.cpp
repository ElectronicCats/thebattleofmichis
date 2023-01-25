#include "Game.h"

Game::Game() {

}

void Game::start() {
  for(;;) {
    Game::printBoard();
    delay(10000);
  }
}

void Game::printBoard() {
  player.printBoard();
}