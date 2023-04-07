#include "Player.h"
#include <esp_now.h>
#include <esp_wifi.h>
#include <WiFi.h>

#define DEBUG
#define RESPONSE_DELAY 50 // miliseconds

// Config variables
const int SHIP_COLOR = Color::Green;
const int SHIP_SUNKEN_COLOR = Color::Red;
const int CURSOR_COLOR = Color::Yellow;
const int HIT_COLOR = Color::Orange;
const int OCEAN_COLOR = Color::Blue;                                          

Player player;
int Vertical = Board::Vertical, Horizontal = Board::Horizontal;

// The boards can stablish communication if they have the same MAC address
uint8_t newMacAddress[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};

// Define variables to store incoming data
uint8_t incoming_x;
uint8_t incoming_y;
bool incoming_request = false;
bool incoming_response = false;
bool incoming_isHit = false;
bool hasTurn = true;
bool winner = false;

typedef struct message {
    bool request;
    bool response;
    uint8_t x;
    uint8_t y;
    bool isHit;
    bool hasTurn;
    bool winner;
} message;

// Create a message called outgoing
message outgoing;

// Create a message to hold incoming
message incoming;

esp_now_peer_info_t peerInfo;

// Variable to store if sending data was successful
bool success;

void setup() {
  Serial.begin(115200);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Show original MAC address
  Serial.println("[OLD] ESP32 Board MAC Address:  " + String(WiFi.macAddress()));

  // Set new MAC address for player 1
  esp_wifi_set_mac(WIFI_IF_STA, &newMacAddress[0]);
  Serial.println("[NEW] ESP32 Board MAC Address:  " + String(WiFi.macAddress()));

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the request of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, newMacAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  startup(); // Shows a banner with the title of the game
  // chooseFirstPlayer();
  setupShips(); // Player places ships
  sendHits();
  endBanner(); // Shows a banner with "You lose" or "You win"
}

void sendHits() {
  winner = false; // There is no winner when the game starts
  for(;;) {
    const int center = 4;
    const int cursorLength = 1;
    static unsigned long lastTime = millis();
    player.loop();

    // The player has lost the game
    if (player.getSunkenShips() == player.getShipsList().size()) {
      #ifdef DEBUG
        Serial.println("You lose");
      #endif

      resetGameVariables(true);

      outgoing.winner = true; // Tells the other player to end the game
      esp_err_t result = esp_now_send(newMacAddress, (uint8_t *) &outgoing, sizeof(outgoing));
      break;
    }

    // The player has won the game
    if (winner) {
      #ifdef DEBUG
        Serial.println("You win");
      #endif

      resetGameVariables(false);
      break;
    }

    if (millis() - lastTime >= 3000) {
      lastTime = millis();
      #ifdef DEBUG
        Serial.println("Number of ships: " + String(player.getShipsList().size()));
        Serial.println("Sunken ships: " + String(player.getSunkenShips()));
        Serial.println("Has turn: " + String(hasTurn ? "true" : "false"));
      #endif
    }

    if (hasTurn) {
      player.setCursor('e', center, center, cursorLength, Horizontal, CURSOR_COLOR);
    } else {
      player.setCursor('e', center, center, cursorLength, Horizontal, Board::Blue);
    }

    // Send a hit to the other player
    if (player.button.isPressed() && hasTurn) {
      // TODO: init the enemy colors in the set cursor method
      int currentColor = player.getColor('e', player.getCursorX(), player.getCursorY());
      int red = Board::Red;
      int condition = currentColor == red;
      Serial.println("Current color: " + String(currentColor));
      Serial.println("Red: " + String(red));
      Serial.println("Condition: " + String(condition));

      // if (player.getColor('e', player.getCursorX(), player.getCursorY()) != Board::Red) {
      //   continue;
      // }

      hasTurn = false;

      outgoing.x = player.getCursorX();
      outgoing.y = player.getCursorY();
      outgoing.request = true;
      outgoing.response = false;
      outgoing.isHit = false;
      outgoing.hasTurn = true; // Give turn to the other player
      outgoing.winner = false;

      esp_err_t result = esp_now_send(newMacAddress, (uint8_t *) &outgoing, sizeof(outgoing));
    }

    if (player.button.isPressed() && player.joystick.button.isPressed())
      ESP.restart();

    // Hit recieved
    if (incoming_request) {
      printIncomingData();
      incoming_request = false;
      delay(RESPONSE_DELAY);

      // Return the coordinates of the hit and if it was a hit
      outgoing.x = incoming_x;
      outgoing.y = incoming_y;
      outgoing.request = false;
      outgoing.response = true;
      outgoing.isHit = player.hit(incoming_x, incoming_y);
      outgoing.hasTurn = false;
      outgoing.winner = false;
      esp_err_t result = esp_now_send(newMacAddress, (uint8_t *) &outgoing, sizeof(outgoing));
      Serial.println("Sent response");
    }

    // Response of a hit
    if (incoming_response) {
      incoming_response = false;
      Serial.println("\nFrom response");
      Serial.println("Is hit: " + String(incoming_isHit));
      Serial.println("Hit on x: " + String(incoming_x) + ", y: " + String(incoming_y));
      // Set the hit
      if (incoming_isHit) {
        Serial.println("Set red");
        player.setColor('e', incoming_x, incoming_y, Board::Red);
      } else {
        Serial.println("Set white");
        player.setColor('e', incoming_x, incoming_y, Board::White);
      }
      player.resetMainColors();
      player.resetEnemyColors();
    }
  }
}

void startup() {
  success = false;
  #ifdef DEBUG
    Serial.println("STARTUP");
  #endif
  for(;;) {
    player.loop();
    player.printScroller(Board::Start);

    // Once is pressed, the program continues with the setup of the ships
    if (player.button.isPressed() || success) {
      FastLED.clear();
      player.resetEnemyColors(); // I tried this to stop the scroller animation but it didn't work
      player.printBoard();
      break;
    }

    if (player.button.isPressed() && player.joystick.button.isPressed())
      ESP.restart();
  }
}

void chooseFirstPlayer() {
  Serial.println("CHOOSING THE FIRST PLAYER");
  for(;;) {
    static unsigned long lastTime = millis();
    static unsigned long lastTime2 = millis();
    
    if (millis() - lastTime >= 1000) {
      lastTime = millis();
      Serial.println("Has turn: " + String(hasTurn));
      Serial.println("Connection succesful: " + String(success));
    }

    // Send a request giving the turn to the other player
    if (millis() - lastTime2 >= 3000 && !hasTurn) {
      lastTime2 = millis();
      Serial.println("Sending the turn");

      outgoing.x = 0;
      outgoing.y = 0;
      outgoing.request = true;
      outgoing.response = false;
      outgoing.isHit = false;
      outgoing.hasTurn = true;

      esp_err_t result = esp_now_send(newMacAddress, (uint8_t *) &outgoing, sizeof(outgoing));
    }

    if (incoming_request) {
      incoming_request = false;
      delay(RESPONSE_DELAY);

      outgoing.x = incoming_x;
      outgoing.y = incoming_y;
      outgoing.request = false;
      outgoing.response = true;
      outgoing.isHit = false;
      outgoing.hasTurn = false;
      success = true;
      esp_err_t result = esp_now_send(newMacAddress, (uint8_t *) &outgoing, sizeof(outgoing));
      Serial.println("Sent response");
    }

    if (incoming_response || hasTurn) {
      Serial.println("OUT OF CHOOSE FIRST PLAYER");
      incoming_response = false;
      success = false;
      break;
    }
  }
}

void setupShips() {
  Serial.println("PLACING SHIPS");
  printIncomingData();
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
    player.setCursor('m', center, center, length, orientation, Board::Red);

    // Toggle orientation
    if (player.joystick.button.isPressed()) {
      orientation = orientation == Vertical ? Horizontal : Vertical;
    }

    if (player.button.isPressed() && player.joystick.button.isPressed())
      ESP.restart();

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
        player.resetMainColors();
        break;
      }
    }
  }
}

void endBanner() {
  #ifdef DEBUG
    Serial.println("END GAME");
  #endif
  resetBoard();
  for(;;) {
    player.loop();
    if (winner) {
      player.printScroller(Board::Win);
    } else {
      player.printScroller(Board::Lose);
    }
    
    if (player.button.isPressed() && player.joystick.button.isPressed())
      ESP.restart();
    
    // Once is pressed, the game is restarted
    if (player.button.isPressed()) {
      FastLED.clear();
      player.resetEnemyColors(); // I tried this to stop the scroller animation but it didn't work
      player.printBoard();
      break;
    }
  }
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  success = !status;
  #ifdef DEBUG
    Serial.println("\r\nLast Packet Send Status:\t" + String(success));
  #endif
}

// Callback when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&incoming, incomingData, sizeof(incoming));
  #ifdef DEBUG
    Serial.println("Bytes received: " + String(len));
  #endif
  incoming_x = incoming.x;
  incoming_y = incoming.y;
  incoming_request = incoming.request;
  incoming_response = incoming.response;
  incoming_isHit = incoming.isHit;
  hasTurn = incoming.hasTurn;
  success = true;
  winner = incoming.winner;
}

void printIncomingData() {
  #ifdef DEBUG
    Serial.println("x: " + String(incoming_x));
    Serial.println("y: " + String(incoming_y));
    Serial.println("request: " + String(incoming_request));
    Serial.println("response: " + String(incoming_response));
    Serial.println("isHit: " + String(incoming_isHit));
    Serial.println("hasTurn: " + String(hasTurn));
    Serial.println("success: " + String(success));
  #endif
}

void resetGameVariables(bool turn) {
  player.setSunkenShips(0);
  incoming_x = 0;
  incoming_y = 0;
  incoming_request = false;
  incoming_response = false;
  incoming_isHit = false;
  hasTurn = turn;
  success = false;

  resetBoard();
}

void resetBoard() {
  player.clearBoard('e');
  player.clearBoard('m');
  player.resetMainColors();
  player.resetEnemyColors();
  player.printBoard();
}
