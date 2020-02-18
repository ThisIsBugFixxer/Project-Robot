#include <Wire.h>



int x =0;

int slaveAddress = 9;

const int buttonPin = 2; // the number of the pushbutton pin

int buttonState = 0; // variable for reading the pushbutton status

void setup()

{

pinMode( buttonPin, INPUT ); // initialize the pushbutton pin as an input

Wire.begin(); // join i2c bus (address optional for master)

Serial.begin( 9600 ); // start serial for output

}

void loop()

{

// read the state of the pushbutton value:

buttonState = digitalRead( buttonPin );

// check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//
//if ( buttonState == HIGH )
//
//{
//
//x = 1;
//
//}
//
//else
//
//{
//
//x = 0;
//
//}

for (x=0;x<=100;x++){

Wire.beginTransmission( slaveAddress ); // transmit to device #9

Wire.write(x); // sends x
Serial.println(x);

Wire.endTransmission(); // stop transmitting

delay(200);

}}
