#include <Wire.h>
#include <dummy.h>

int x=0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(9);
   Wire.onReceive(something);
  Serial.begin(9600);
}

//void receiveEvent( int bytes){
//
//  x = Wire.read();
//}
void something(int b) {

}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(x);
}
