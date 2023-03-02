#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH THE MAC Address of your receiver 
//uint8_t broadcastAddress[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
// First MAC: 08:3A:F2:A9:DE:BC
uint8_t broadcastAddress[] = {0x08, 0x3A, 0xF2, 0xA9, 0xDE, 0xBC};
// Second MAC: 40:22:D8:74:25:3C
//uint8_t broadcastAddress[] = {0x40, 0x22, 0xD8, 0x74, 0x25, 0x3C};

// Define variables to be sent
uint8_t x;
uint8_t y;
uint8_t color;

// Define variables to store incoming data
uint8_t incoming_x;
uint8_t incoming_y;
uint8_t incoming_color;

// Variable to store if sending data was successful
String success;

//Structure example to send data
//Must match the receiver structure
typedef struct struct_message {
    uint8_t x_p;
    uint8_t y_p;
    uint8_t color_p;
} struct_message;

// Create a struct_message called outgoing
struct_message outgoing;

// Create a struct_message to hold incoming
struct_message incoming;

esp_now_peer_info_t peerInfo;

// Callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
  if (status ==0){
    success = "Delivery Success :)";
  }
  else{
    success = "Delivery Fail :(";
  }
}

// Callback when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&incoming, incomingData, sizeof(incoming));
  Serial.print("Bytes received: ");
  Serial.println(len);
  incoming_x = incoming.x_p;
  incoming_y = incoming.y_p;
  incoming_color = incoming.color_p;
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(9600);
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Show MAC address
  Serial.print("Dirección MAC: ");
  Serial.println(WiFi.macAddress());

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
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
 
  // Set values to send
  outgoing.x_p = 2;
  outgoing.y_p = 2;
  outgoing.color_p = 127;

  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &outgoing, sizeof(outgoing));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  updateDisplay();
  delay(10000);
}

void updateDisplay(){

  // Display Readings in Serial Monitor
  Serial.println("INCOMING ");
  Serial.print("x: ");
  Serial.print(incoming.x_p);
  Serial.println(", ");
  Serial.print("y: ");
  Serial.print(incoming.y_p);
  Serial.println(", ");
  Serial.print("color: ");
  Serial.print(incoming.color_p);
  Serial.println();
}
