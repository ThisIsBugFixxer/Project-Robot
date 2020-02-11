#include <Wire.h>
//#include <I2Cdev.h>
#include <MPU6050.h>


MPU6050 mpu;
MPU6050 mpu2;
int16_t ax, ay, az, gx, gy, gz;
int16_t ax2, ay2, az2, gx2, gy2, gz2;

int vx, vy,vx2,vy2;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  mpu2.initialize();
  if (!mpu.testConnection()) {
    while (1);
    }
  if (!mpu2.testConnection()) {
    while (1);
    }  
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  mpu2.getMotion6(&ax2, &ay2, &az2, &gx2, &gy2, &gz2);

  vx = (gx+300)/200;  // "+300" because the x axis of gyroscope give values about -350 while it's not moving. Change this value if you get something different using the TEST code, chacking if there are values far from zero.
  vy = -(gz-100)/200; // same here about "-100"
  vx2 = (gx+300)/200;  // "+300" because the x axis of gyroscope give values about -350 while it's not moving. Change this value if you get something different using the TEST code, chacking if there are values far from zero.
  vy2 = -(gz-100)/200; // same here about "-100"
  
//   Mouse.move(vx, vy);
//   Serial.println("Vx");Serial.print(vx); Serial.print("\t\t\tVy:");Serial.print(vy);
    Serial.println("vx : " + vx);
    Serial.print("\t vx2 : " + vx2);
  
  delay(20);
}