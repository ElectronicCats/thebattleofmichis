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

void Player::setSubmarine(int startX, int startY, int endX, int endY) {
  Player::submarine.create(startX, startY, endX, endY);
}

Ship Player::getSubmarine() {
  return Player::submarine;
}

void Player::setCruiser(int startX, int startY, int endX, int endY) {
  Player::cruiser.create(startX, startY, endX, endY);
}

Ship Player::getCruiser() {
  return Player::cruiser;
}

void Player::setBattleship(int startX, int startY, int endX, int endY) {
  Player::battleship.create(startX, startY, endX, endY);
}

Ship Player::getBattleship() {
  return Player::battleship;
}

void Player::setAircraftCarrier(int startX, int startY, int endX, int endY) {
  Player::aircraftCarrier.create(startX, startY, endX, endY);
}

Ship Player::getAircraftCarrier() {
  return Player::aircraftCarrier;
}