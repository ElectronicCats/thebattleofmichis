#include "Player.h"
#include <esp_now.h>
#include <esp_wifi.h>
#include <WiFi.h>

Player player;
int Vertical = Board::Vertical, Horizontal = Board::Horizontal;

// The boards can stablish communication if they have the same MAC address
uint8_t newMacAddress[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};

// Define variables to be sent
uint8_t x;
uint8_t y;
uint8_t color;

// Define variables to store incoming data
uint8_t incoming_x;
uint8_t incoming_y;
uint8_t incoming_color;

typedef struct struct_message {
    uint8_t x;
    uint8_t y;
    uint8_t color;
} struct_message;

// Create a struct_message called outgoing
struct_message outgoing;

// Create a struct_message to hold incoming
struct_message incoming;

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
  // get the status of Trasnmitted packet
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

  setupShips();
}

void loop() {
  player.loop();
  player.setCursor('e', 4, 4, 1, Horizontal);

  if (player.button.isPressed()) {
    outgoing.x = player.getCursorX();
    outgoing.y = player.getCursorY();
    outgoing.color = 255;

    // Send message via ESP-NOW
    esp_err_t result = esp_now_send(newMacAddress, (uint8_t *) &outgoing, sizeof(outgoing));

    Serial.println("x: " + String(player.getCursorX()) + " y: " + String(player.getCursorY()));
    Serial.println("Is hit: " + String(player.hit(player.getCursorX(), player.getCursorY())));

    // updateDisplay();
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

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  success = !status;
  Serial.println("\r\nLast Packet Send Status:\t" + String(success));
}

// Callback when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&incoming, incomingData, sizeof(incoming));
  Serial.print("Bytes received: ");
  Serial.println(len);
  incoming_x = incoming.x;
  incoming_y = incoming.y;
  incoming_color = incoming.color;
}

void updateDisplay(){
  // Display Readings in Serial Monitor
  Serial.println("INCOMING ");
  Serial.println("x: " + String(incoming_x));
  Serial.println("y: " + String(incoming_y));
  Serial.println("color: " + String(incoming_color));
}
