#include "Ship.h"

void Ship::create(int startX, int startY, int endX, int endY) {
  this->startX = startX;
  this->startY = startY;
  this->endX = endX;
  this->endY = endY;
}

void Ship::setStart(int x, int y) {
  startX = x;
  startY = y;
}

void Ship::setEnd(int x, int y) {
  endX = x;
  endY = y;
}

int Ship::getStartX() {
  return startX;
}

int Ship::getStartY() {
  return startY;
}

int Ship::getEndX() {
  return endX;
}

int Ship::getEndY() {
  return endY;
}

int Ship::getSize() {
  int sizeX = abs(endX - startX) + 1;
  int sizeY = abs(endY - startY) + 1;
  return sizeX * sizeY;
}