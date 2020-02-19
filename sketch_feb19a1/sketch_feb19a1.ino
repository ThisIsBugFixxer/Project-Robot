/*
 *  This sketch sends random data over UDP on a ESP32 device
 *  
 */
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>

// WiFi network name and password:
const char * networkName = "RobotNet";
const char * networkPswd = "123456789";

IPAddress local_IP(192, 168, 31, 115);
IPAddress gateway(192, 168, 31, 1);
IPAddress subnet(255, 255, 0, 0);

//IP address to send UDP data to:
// either use the ip address of the server or 
// a network broadcast address
const char * udpAddress = "192.168.4.1";
const int udpPort = 3333;

//Are we currently connected?
boolean connected = false;

uint8_t buffer[50];  //length of data

//The udp library class
WiFiUDP udp;

void setup(){
  // Initilize hardware serial:
  Serial.begin(115200);
    if (!WiFi.config(local_IP,gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
  
  //Connect to the WiFi network
  connectToWiFi(networkName, networkPswd);
    udp = WiFiUDP();
  udp.begin(udpPort);
  
}

void loop(){
  //only send data when connected
//  if(connected){
//    //Send a packet
//    udp.beginPacket(udpAddress,udpPort);
//    udp.printf("Seconds since boot: %lu", millis()/1000);
//    udp.endPacket();
//  }

  udp.parsePacket();
  
  if(udp.read(buffer,50)>0){
    Serial.println((char *)buffer);
  }
  //Wait for 1 second
  delay(1000);
}

void connectToWiFi(const char * ssid, const char * pwd){
  Serial.println("Connecting to WiFi network: " + String(ssid));

  // delete old config
  WiFi.disconnect(true);
  //register event handler
  WiFi.onEvent(WiFiEvent);
  
  //Initiate connection
  WiFi.begin(ssid, pwd);

  Serial.println("Waiting for WIFI connection...");
}

//wifi event handler
void WiFiEvent(WiFiEvent_t event){
    switch(event) {
      case SYSTEM_EVENT_STA_GOT_IP:
          //When connected set 
          Serial.print("WiFi connected! IP address: ");
          Serial.println(WiFi.localIP());  
          //initializes the UDP state
          //This initializes the transfer buffer
//          WiFi.config(FIXEDIP);
          udp.begin(WiFi.localIP(),udpPort);
          connected = true;
          break;
      case SYSTEM_EVENT_STA_DISCONNECTED:
          Serial.println("WiFi lost connection");
          connected = false;
          break;
      default: break;
    }
}
