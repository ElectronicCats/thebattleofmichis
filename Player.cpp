#include "Player.h"
#define rows 10
#define cols 10

Player::Player() : playerBoard(rows, cols) {
  
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

void Player::setDestroyer(int startX, int startY, int endX, int endY) {
  Player::destroyer.create(startX, startY, endX, endY);
}

Ship Player::getDestroyer() {
  return Player::destroyer;
}