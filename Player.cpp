#include "Player.h"
#define rows 10
#define cols 10

Player::Player() : playerBoard(rows, cols) {
  sunkenShips = 0;
}

int** Player::board() {
  return playerBoard.get;
}

void Player::printBoard() {
  playerBoard.serialPrint();
}

void Player::placeShip(Ship ship) {
  playerBoard.placeShip(ship);
}

// Add a ship to the stack
void Player::addShip(Ship ship) {
  this->ships.push_back(ship);
}

void Player::hit(int x, int y) {
  for (auto ship : ships) {
    ship.isHit(x, y);
  }
}

void Player::setDestroyer(int startX, int startY, int endX, int endY) {
  Player::destroyer.create(startX, startY, endX, endY);
  Player::addShip(Player::destroyer);
}

Ship Player::getDestroyer() {
  return Player::destroyer;
}

int Player::getDestroyerSize() {
  return Player::destroyer.getSize();
}

bool Player::isDestroyerSunken() {
  return Player::destroyer.isSunken();
}

void Player::setSubmarine(int startX, int startY, int endX, int endY) {
  Player::submarine.create(startX, startY, endX, endY);
  Player::addShip(Player::submarine);
}

Ship Player::getSubmarine() {
  return Player::submarine;
}

void Player::setCruiser(int startX, int startY, int endX, int endY) {
  Player::cruiser.create(startX, startY, endX, endY);
  Player::addShip(Player::cruiser);
}

Ship Player::getCruiser() {
  return Player::cruiser;
}

void Player::setBattleship(int startX, int startY, int endX, int endY) {
  Player::battleship.create(startX, startY, endX, endY);
  Player::addShip(Player::battleship);
}

Ship Player::getBattleship() {
  return Player::battleship;
}

void Player::setAircraftCarrier(int startX, int startY, int endX, int endY) {
  Player::aircraftCarrier.create(startX, startY, endX, endY);
  Player::addShip(Player::aircraftCarrier);
}

Ship Player::getAircraftCarrier() {
  return Player::aircraftCarrier;
}