#include <Wire.h>

TwoWire I2Cone = TwoWire(0);
TwoWire I2Ctwo = TwoWire(1);

void setup() {
  I2Cone.begin(21,22,100000); // SDA pin 21, SCL pin 22, 100kHz frequency
  I2Ctwo.begin(16,17,400000); // SDA pin 16, SCL pin 17, 400kHz frequency
}

void loop() {
  I2Cone.beginTransmission(0x38);
  I2Cone.write(0x00 | 0x80);
  I2Cone.write(0x03);
  I2Cone.endTransmission();

  I2Ctwo.beginTransmission(0x42);
  I2Ctwo.write(140);
  I2Ctwo.endTransmission();
  I2Ctwo.requestFrom(0x42,1);
  if (I2Ctwo.available() == 1) {
    byte value = I2Ctwo.read();
  }
}
