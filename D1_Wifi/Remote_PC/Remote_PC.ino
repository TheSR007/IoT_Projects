#include "thingProperties.h"
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFi.h>

// Setup All the Variables and Dashboard in Arduino IoT Cloud and then Continue in the Cloud IDE or Download and then continue in Local IDE
#define RELAY_PIN D4
unsigned int WoLPort = 9;
uint8_t packetBytes[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
const uint8_t wolMacAddress[6] = {0xD8, 0xBB, 0xC1, 0x91, 0x0E, 0x73};
const char* ipAddress = "192.168.0.2"; // usually Broadcast Address but I fixed my PC's IP

void setup() {
  // Initialize pin
  pinMode(RELAY_PIN, OUTPUT);
  // Initialize serial and wait for port to open:
  Serial.begin(115200);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
    ArduinoCloud.update();

    if(refresh){
      refresh = false;
      isOnline = checkDesktopStatus();
    }

    if(sendWoLPacket){
      sendWoLPacket = false;
      digitalWrite(RELAY_PIN,HIGH);  //power button on for 1 sec
      delay(1000);
      digitalWrite(RELAY_PIN,LOW);
    }

    delay(100);
    yield();
}


bool checkDesktopStatus() {
    WiFiClient client;
    
    client.setTimeout(500); // 500 ms timeout for TCP connection

    // Trying to connect to the PC's IP on TCP port 135 (it just works for me xD)
    if (client.connect(ipAddress, 135)) {
        client.stop(); // Connection successful, close it
        return true;   // PC is online
    }
    
    return false; // Connection failed, PC is offline
}
