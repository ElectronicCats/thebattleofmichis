#include "Arduino.h"

class Ship {
  private:
    int startX, startY, endX, endY;
    int hits;
    String name;

  public:
    void create(String name, int startX, int startY, int endX, int endY);
    String getName();
    int getStartX();
    int getStartY();
    int getEndX();
    int getEndY();
    int getSize();
    bool isHit(int x, int y);
    int getHits();
    bool isSunken();
};