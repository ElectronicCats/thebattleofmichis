#include "Ship.h"

void Ship::create(String name, int startX, int startY, int endX, int endY) {
  this->startX = startX - 1;
  this->startY = startY - 1;
  this->endX = endX - 1;
  this->endY = endY - 1;
  this->hits = 0;
  this->name = name;
}

String Ship::getName() {
  return this->name;
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

bool Ship::isHit(int x, int y) {
  if (x - 1 >= startX && x - 1 <= endX && y - 1 >= startY && y - 1 <= endY) {
    hits++;
    //Serial.println("Hit true, hits: " + String(this->hits));
    return true;
  } else {
    //Serial.println("Hit false, hits: " + String(this->hits));
    return false;
  }
}

int Ship::getHits() {
  return this->hits;
}

bool Ship::isSunken() {
  return this->hits >= Ship::getSize();
}