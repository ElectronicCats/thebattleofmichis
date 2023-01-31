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
  for (auto &ship : ships) {
    if (ship.isHit(x, y)) {
      Player::isShipSunken(ship);
      this->playerBoard.setPixel(x, y, 3);
    } else {
      if (this->playerBoard.getPixel(x, y) != 3) {
        this->playerBoard.setPixel(x, y, 2);
      }
    }
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

bool Player::createShip(int startX, int startY, int endX, int endY) {
  Ship ship;
  ship.create(startX, startY, endX, endY);
  Player::addShip(ship);
  return true;  
}

Ship Player::getShip(int arrayPosition) {
  if (arrayPosition < 0 || arrayPosition >= this->ships.size()) {
    Ship ship;
    ship.create(0, 0, 0, 0);
    return ship;
  }
  return this->ships[arrayPosition];
}

std::vector<Ship> Player::getShipsList() {
  return ships;
}