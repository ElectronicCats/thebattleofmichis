#include "Player.h"

Player::Player() : board(ROWS, COLS), button(BUTTON_PIN) {
  sunkenShips = 0;
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  this->button.setDebounceTime(DEBOUNCE_DELAY);
}

void Player::loop() {
  this->joystick.loop();
  this->button.loop();
}

void Player::printBoard() {
  board.print();
}

/**
  * Takes an object of type Ship and and change the values
  * of the coordinates from zero to one on the board
  */
void Player::placeShip(Ship ship) {
  board.placeShip(ship);
}

// Add a ship to the list of ships
void Player::addShip(Ship ship) {
  this->ships.push_back(ship);
}

bool Player::hit(int x, int y) {
  bool isHit = false;

  for (auto &ship : ships) {
    if (ship.isHit(x, y)) {
      Player::isShipSunken(ship);
      this->board.setPixel('e', x, y, 3);
      isHit = true;
    } else {
      if (this->board.getPixel('m', x, y) != Board::Green) {
        this->board.setPixel('e', x, y, 2);
      }
    }
  }

  return isHit;
}

/**
 * Increase the number of suken ships if the ship
 * is suken
 */
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
  if (!Player::isValidShipCoordinates(startX, startY, endX, endY)) {
    return false;
  }

  Ship ship;
  ship.create(startX, startY, endX, endY);
  Player::addShip(ship);
  return true;  
}

bool Player::isValidShipCoordinates(int startX, int startY, int endX, int endY) {
  // ship instead of &ship because it generates a copy of the ship and
  // the isHit method won't increase the number of hits on the original ship
  for (auto ship : this->ships) {
    for (int i = startX; i <= endX; i++) {
      for (int j = startY; j <= endY; j++) {
        if (ship.isHit(i, j)) {
          return false;
        }
      }
    }
  }
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

void Player::setCursor(char id, int x, int y, int length, int orientation) {
  static int x_t = x;
  static int y_t = y;
  static unsigned long lastTime = 0;

  if (millis() - lastTime >= MOVE_DELAY) {
    lastTime = millis();

    // LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3, CENTER = 4
    switch (this->joystick.getDirection()) {
      case 0:
        if (x_t > 1) x_t--;
        break;
      case 1:
        if (x_t < 8) x_t++;
        break;
      case 2:
        if (y_t > 1) y_t--;
        break;
      case 3:
        if (y_t < 8) y_t++;
        break;
    }
    // Update the cursor position
    this->board.setCursor(id, x_t, y_t, length, orientation);
  }
}

int Player::getCursorX() {
  return this->board.getCursorX();
}

int Player::getCursorY() {
  return this->board.getCursorY();
}

void Player::resetColors() {
  this->board.resetColors();
}
