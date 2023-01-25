#include "Player.h"

Player::Player() : playerBoard(10, 10) {
  
}

int** Player::board() {
  return playerBoard.get;
}

void Player::printBoard() {
  playerBoard.serialPrint();
}