#include "MPU6050.h"
#include <Servo.h>

MPU6050 accelgyroIC1(0x68); 
MPU6050 accelgyroIC2(0x69);

Servo servo;
Servo servo2;
Servo servo3; 

int16_t ax1, ay1, az1;
int16_t gx1, gy1, gz1;

int16_t ax2, ay2, az2;
int16_t gx2, gy2, gz2;

int16_t ax3;


int accelIC3;
int analogX1 = A0;


void setup() {

Wire.begin();

servo.attach(9);
servo2.attach(8);


Serial.println("Initializing I2C devices...");

accelgyroIC1.initialize();
accelgyroIC2.initialize();

Serial.begin(9600);


// verify connection
Serial.println("Testing device connections...");
Serial.println(accelgyroIC1.testConnection() ? "MPU6050 #1 connection successful" : "MPU6050 connection failed");
Serial.println(accelgyroIC2.testConnection() ? "MPU6050 #2 connection successful" : "MPU6050 connection failed");


}

void loop() {
// read raw accel/gyro measurements from device

accelgyroIC1.getMotion6(&ax1, &ay1, &az1, &gx1, &gy1, &gz1);

accelgyroIC2.getMotion6(&ax2, &ay2, &az2, &gx2, &gy2, &gz2);

accelIC3 = analogRead(analogX1); 


ax1 = map (ax1, -17000, 17000, 0, 180) ;
ax2 = map (ax2, -17000, 17000, 0, 180) ;
ax3 = map (ax3, -17000, 17000, 0, 180) ; // this may be needed to be modified.

// display tab-separated accel/gyro x/y/z values

Serial.print("MPU1:\t");
Serial.print(ax1); Serial.print("\t");
servo.write(ax1);


// display tab-separated accel/gyro x/y/z values
Serial.print("MPU2:\t");
Serial.print(ax2); Serial.print("\t");
servo2.write(ax2);


// display tab-separated accel/gyro x/y/z values
Serial.print("ADX335:\t");
Serial.print(ax3); Serial.print("\n");
servo2.write(ax3);


delay(200);
}
