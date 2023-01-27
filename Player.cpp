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