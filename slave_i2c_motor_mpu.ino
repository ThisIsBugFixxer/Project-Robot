// I2C SLAVE 

#include <Wire.h>

#include <dummy.h>  //for esp32

#include <Servo.h>





int LED = 13;
int x = 0;
int y = 0;

Servo s;
Servo s2;

void setup() {
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
//  Wire.begin(0x09); 
//  // Attach a function to trigger when something is received.
//  Wire.onReceive(receiveEvent);
//  

  s.attach(8);
  
  s2.attach(9);
  Serial.begin(9600);

  Wire.begin(); // SDA pin 21, SCL pin 22 TTGO TQ
  
 // Wire.begin(SDA2,SCL2,400000);

}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void loop() {
  //If value received is 0 blink LED for 200 ms
  
    // Start the I2C Bus as Slave on address 9
  Wire.begin(0x09); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  s.write(x);
//  Serial.println("x= " ); Serial.print(x); Serial.println("\n");
  Wire.endTransmission();
  
  delay(100);
  
//  Wire.begin(0x04);
//  
//  Wire.onReceive(receiveEvent);
//
//  s2.write(y);
//  Serial.println("y= " ); Serial.print(y); Serial.println("\n");
//  Wire.endTransmission();
//
//  delay(100);
  

  


}
