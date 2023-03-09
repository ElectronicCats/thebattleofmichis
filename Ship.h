#include "Arduino.h"

class Ship {
  private:
    int startX, startY, endX, endY;
    int hits;

  public:
    void create(int startX, int startY, int endX, int endY);
    int getStartX();
    int getStartY();
    int getEndX();
    int getEndY();
    int getSize();
    bool isHit(int x, int y);
    void increaseHits();
    int getHits();
    bool isSunken();
};
