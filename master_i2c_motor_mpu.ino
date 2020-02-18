// Chapter 7 - Communications
// I2C Master
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C
#include <Wire.h>

#include "MPU6050.h"


MPU6050 accelgyroIC1(0x68); 
MPU6050 accelgyroIC2(0x69);



int16_t ax1, ay1, az1;
int16_t gx1, gy1, gz1;

int16_t ax2, ay2, az2;
int16_t gx2, gy2, gz2;

int x = 0;
int y = 0;

void setup() {
  // Start the I2C Bus as Master
  Wire.begin(); 
  accelgyroIC1.initialize();
  accelgyroIC2.initialize();
  Serial.println(accelgyroIC1.testConnection() ? "MPU6050 #1 connection successful" : "MPU6050 connection failed");
  Serial.println(accelgyroIC2.testConnection() ? "MPU6050 #2 connection successful" : "MPU6050 connection failed");
  Serial.begin(9600);
  delay(2000);
}

void loop() {

  
accelgyroIC1.getMotion6(&ax1, &ay1, &az1, &gx1, &gy1, &gz1);
accelgyroIC2.getMotion6(&ax2, &ay2, &az2, &gx2, &gy2, &gz2);

x = map (ax1, -17000, 17000, 0, 180) ;

y = map (ax2, -17000, 17000, 0, 180) ;

Wire.beginTransmission(9); // transmit to device #9
Wire.write(x);
Wire.write(y);
Serial.println(x);
Wire.endTransmission(); 

delay(200);
  
 
}
