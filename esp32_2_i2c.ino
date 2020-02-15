#include <Wire.>
#include "MPU6050.h"
#include <Servo.h>

#define SCL_2 32
#define SDA_2 33

MPU6050 mpu1;
MPU6050 mpu2;
MPU6050 mpu3;
MPU6050 mpu4;

Servo servo;
Servo servo2;

int16_t ax1, ay1, az1;
int16_t gx1, gy1, gz1;

int16_t ax2, ay2, az2;
int16_t gx2, gy2, gz2;

int16_t ax3, ay3, az3;
int16_t gx3, gy3, gz3;

int16_t ax4, ay4, az4;
int16_t gx4, gy4, gz4;


void setup(){

    wire.begin();
    wire1.begin(SCL_2,SDA_2);


    mpu1.begin(0x68);
    mpu2.begin(0x69);
    mpu3.begin(0x68, &wire1);
    mpu4.begin(0x69, &wire1);

    // verify connection
Serial.println("Testing device connections...");
Serial.println(mpu1.testConnection() ? "MPU6050 #1 connection successful" : "MPU6050 connection failed");
Serial.println(mpu2.testConnection() ? "MPU6050 #2 connection successful" : "MPU6050 connection failed");

Serial.println(mpu3.testConnection() ? "MPU6050 #3 connection successful" : "MPU6050 connection failed");
Serial.println(mpu4.testConnection() ? "MPU6050 #4 connection successful" : "MPU6050 connection failed");

delay(2000);


}

void loop(){

}