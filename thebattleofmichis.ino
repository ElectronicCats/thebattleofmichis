#include "Player.h"
#include <esp_now.h>
#include <esp_wifi.h>
#include <WiFi.h>

Player player;
int Vertical = Board::Vertical, Horizontal = Board::Horizontal;

typedef struct message {
  uint8_t x;
  uint8_t y;
  uint8_t isHit;
} message;

void setup() {
  Serial.begin(115200);
  setupShips();
}

void loop() {
  player.loop();
  player.setCursor('e', 4, 4, 1, Horizontal);

  if (player.button.isPressed()) {
    Serial.println("x: " + String(player.getCursorX()) + " y: " + String(player.getCursorY()));
    Serial.println("Is hit: " + String(player.hit(player.getCursorX(), player.getCursorY())));
    player.resetColors();
  }
}

void setupShips() {
  placeShip(2); // Destroyer
  placeShip(3); // Submarine
  placeShip(3); // Cruiser
  placeShip(4); // Battleship
  placeShip(5); // Aircraft Carrier
}

void placeShip(int length) {
  int orientation = Horizontal;
  int center = 4;
  int startX, startY, endX, endY;

  for (;;) {
    player.loop();
    player.setCursor('m', center, center, length, orientation);

    // Toggle orientation
    if (player.joystick.button.isPressed()) {
      orientation = orientation == Vertical ? Horizontal : Vertical;
    }

    // Place ship
    if (player.button.isPressed()) {
      if (orientation == Horizontal) {
        startX = player.getCursorX();
        endX = player.getCursorX() + (length - 1);
        startY = endY = player.getCursorY();
      } else {
        startX = endX = player.getCursorX();
        startY = player.getCursorY();
        endY = player.getCursorY() + (length - 1);
      }

      // If the ship can be created, place it on the board
      if (player.createShip(startX, startY, endX, endY)) {
        player.placeShip(player.getShip(player.getShipsList().size() - 1));
        player.printBoard();
        player.resetColors();
        break;
      }
    }
  }
}