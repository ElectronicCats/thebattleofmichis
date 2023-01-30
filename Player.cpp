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
    if (ship.isHit(x, y)) {
      Player::isShipSunken(ship);
    }
    Serial.println("Ship: " + String(ship.getName()));
  }
}

bool Player::isShipSunken(Ship ship) {
  if (ship.isSunken()) {
    this->sunkenShips++;
    return true;
  } else {
    return false;
  }
}

int Player::getSunkenShips() {
  return this->sunkenShips;
}

bool Player::createShip(String name, int startX, int startY, int endX, int endY) {
  if (name == "destroyer") {
    Player::destroyer.create(name, startX, startY, endX, endY);
    Player::addShip(Player::destroyer);
  } else if (name == "submarine") {
    Player::submarine.create(name, startX, startY, endX, endY);
    Player::addShip(Player::submarine);
  } else if (name == "cruiser") {
    Player::cruiser.create(name, startX, startY, endX, endY);
    Player::addShip(Player::cruiser);  
  } else if (name == "battleship") {
    Player::battleship.create(name, startX, startY, endX, endY);
    Player::addShip(Player::battleship);
  } else if (name == "aircraftCarrier") {
    Player::aircraftCarrier.create(name, startX, startY, endX, endY);
    Player::addShip(Player::aircraftCarrier);  
  }
  return true;  
}

void Player::setDestroyer(String name, int startX, int startY, int endX, int endY) {
  Player::destroyer.create(name, startX, startY, endX, endY);
  Player::addShip(Player::destroyer);
}

Ship Player::getDestroyer() {
  return Player::destroyer;
}

void Player::setSubmarine(String name, int startX, int startY, int endX, int endY) {
  Player::submarine.create(name, startX, startY, endX, endY);
  Player::addShip(Player::submarine);
}

Ship Player::getSubmarine() {
  return Player::submarine;
}

Ship Player::getCruiser() {
  return Player::cruiser;
}

void Player::setBattleship(String name, int startX, int startY, int endX, int endY) {
  Player::battleship.create(name, startX, startY, endX, endY);
  Player::addShip(Player::battleship);
}

Ship Player::getBattleship() {
  return Player::battleship;
}

void Player::setAircraftCarrier(String name, int startX, int startY, int endX, int endY) {
  Player::aircraftCarrier.create(name, startX, startY, endX, endY);
  Player::addShip(Player::aircraftCarrier);
}

Ship Player::getAircraftCarrier() {
  return Player::aircraftCarrier;
}