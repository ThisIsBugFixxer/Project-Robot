//0 degree calibration of servo motors

#include <Servo.h>

Servo servo;
Servo servo2; 
// can add more servos 

void setup(){

    servo.attach(9); // pins to which servo 1 is attached to 
    servo2.attach(8);

}

void loop(){

    servo.write(0);
    servo2.write(0);

    delay(10000);

    servo.write(180);
    servo2.write(180);

    delay(10000);

    servo.write(0);
    servo2.write(0);

    delay(10000);
    

}