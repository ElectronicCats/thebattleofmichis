#include "Arduino.h"

class Ship {
  private:
    int startX, startY, endX, endY;
    int hits;

  public:
    //Ship(int startX, int startY, int endX, int endY);
    void create(int startX, int startY, int endX, int endY);
    void setStart(int x, int y);
    void setEnd(int x, int y);
    int getStartX();
    int getStartY();
    int getEndX();
    int getEndY();
    int getSize();
    bool isHit(int x, int y);
    int getHits();
    bool isSunken();
};