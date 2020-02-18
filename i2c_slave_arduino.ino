#include <Wire.h>

 // <-- remove spaces

int LED = 13;

int x = 0;

void setup()

{

// Define the LED pin as Output

pinMode (LED_BUILTIN, OUTPUT);
Serial.begin(9600);

// Start the I2C Bus as Slave on address 9

Wire.begin(9);

// Attach a function to trigger when something is received.

Wire.onReceive(receiveEvent);

}

void receiveEvent( int bytes )

{

x = Wire.read(); // read one character from the I2C


Wire.endTransmission(); // stop transmitting

}

void loop()

{

  Serial.println(x);

if (x % 2 == 0) {

digitalWrite(LED_BUILTIN, HIGH);

delay(200);

}

if (x % 2 != 0) {

digitalWrite(LED_BUILTIN, LOW);

delay(200);

}

}
