#include <Servo.h>

Servo servo;

const int xout = A5;




int out1 = 0;       

int sout1 = 0;   



void setup(){
    
    Serial.begin(9600);
    servo.attach(9);
}


void loop() {

  analogReference(EXTERNAL);

  out1 = analogRead(xout);           

  sout1 = map(out1, 0, 1023, 0, 255); 

  delay(2);                    


  Serial.print("\tX = " );                      

  Serial.print(out1); 
  servo.write(sout1);    


  delay(200);                    

}
