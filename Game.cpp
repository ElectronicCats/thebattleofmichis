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
  player1.createShip("battleship", 5, 9, 9, 9);
  player1.createShip("destroyer", 1, 6, 2, 6);
  player1.createShip("submarine", 8, 2, 8, 4);

  player1.hit(1, 6);
  Serial.println("Sunken ships: " + String(player1.getSunkenShips()));
  Serial.println("Destroyer sunken: " + String(player1.getDestroyer().isSunken()));
  player1.hit(2, 6);
  Serial.println("Sunken ships: " + String(player1.getSunkenShips()));
  Serial.println("Destroyer hits: " + String(player1.getDestroyer().getHits()));
  Serial.println("Destroyer sunken: " + String(player1.getDestroyer().isSunken()));

  player1.hit(5, 9);
  player1.hit(6, 9);
  player1.hit(7, 9);
  player1.hit(8, 9);
  player1.hit(9, 9);
  Serial.println("Sunken ships: " + String(player1.getSunkenShips()));

  player1.printBoard();

  player1.placeShip(player1.getDestroyer());
  player1.placeShip(player1.getSubmarine());
  player1.placeShip(player1.getBattleship());

  player1.printBoard();
}