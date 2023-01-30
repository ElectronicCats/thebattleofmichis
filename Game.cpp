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

  player1.printBoard();

  player1.placeShip(player1.getDestroyer());
  player1.placeShip(player1.getSubmarine());
  player1.placeShip(player1.getBattleship());

  player1.hit(2, 2);
  Serial.println("Submarine size: " + String(player1.getSubmarine().getSize()));
  Serial.println("Destroyer size: " + String(player1.getDestroyer().getSize()));
  Serial.println("Sunken ships: " + String(player1.getSunkenShips()));
  Serial.println("Destroyer sunken: " + String(player1.getDestroyer().isSunken()));
  player1.hit(3, 2);
  Serial.println("Sunken ships: " + String(player1.getSunkenShips()));
  Serial.println("Destroyer sunken: " + String(player1.getDestroyer().isSunken()));

  player1.printBoard();
}