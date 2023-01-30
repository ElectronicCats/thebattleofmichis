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
  player1.createShip(5, 8, 8, 8);
  player1.createShip(1, 6, 2, 6);

  player1.hit(1, 6);
  Serial.println("Destroyer hits: " + String(player1.getShip(1).getHits()));
  player1.hit(2, 6);
  Serial.println("Destroyer hits: " + String(player1.getShip(2).getHits()));
  Serial.println("Sunken ships: " + String(player1.getSunkenShips()));

  player1.hit(5, 8);
  player1.hit(6, 8);
  player1.hit(7, 8);
  player1.hit(8, 8);
  Serial.println("Sunken ships: " + String(player1.getSunkenShips()));

  player1.printBoard();

  player1.placeShip(player1.getShip(0));
  player1.placeShip(player1.getShip(1));

  player1.printBoard();
}