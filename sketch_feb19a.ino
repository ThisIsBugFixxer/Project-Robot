#include <MPU6050.h>

#include "WiFi.h"
#include "ESPAsyncWebServer.h"

#include <Wire.h>

#include <dummy.h>  //for esp32

#define SDA1 5
#define SCL1 4



TwoWire I2Cone = TwoWire(0);
TwoWire I2Ctwo = TwoWire(1);

const int MPU_addr=0x68;

// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "0123456789";

/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/

int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

int x;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);


void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  
  Serial.begin(115200);
  
  I2Cone.begin(SDA1,SCL1,400000); // SDA pin 21, SCL pin 22 TTGO TQ
  
  I2Cone.beginTransmission(MPU_addr);
  I2Cone.write(0x6B); // PWR_MGMT_1 register
  I2Cone.write(0); // set to zero (wakes up the MPU-6050)
  I2Cone.endTransmission(true);


  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);


  
  // Start server
  server.begin();
}

String readval1() {
  
  I2Cone.beginTransmission(MPU_addr);
  I2Cone.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
  I2Cone.endTransmission(false);
  I2Cone.requestFrom(MPU_addr,14,true); // request a total of 14 registers

  AcX=I2Cone.read()<<8|I2Cone.read();

  x = map (AcX, -17000, 17000, 0, 180) ;
  
  return String(x);
  //return String(1.8 * bme.readTemperature() + 32);

  I2Cone.endTransmission(true);
  delay(100);
}



 
void loop(){

    server.on("/AccVal1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readval1().c_str());
  });

 
}
