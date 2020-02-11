// controlling the servo with mpu6050, test 1.


#include <Wire.h>

#include <MPU6050.h>

#include <Servo.h>   

Servo sg90;
Servo sg902; 
         

int servo_pin = 9;
int servo_pin2 = 8;

MPU6050 sensor ;
MPU6050 sensor2;

int16_t ax, ay, az ;

int16_t gx, gy, gz ;

int16_t ax2, ay2, az2;

int16_t gx2, gy2, gz2;

void setup ( )

{ 

sg90.attach ( servo_pin );

sg902.attach (servo_pin2);

Wire.begin ( );

Serial.begin  (9600); 

Serial.println  ( "Initializing the sensor" ); 

sensor.initialize ( );
sensor2.initialize(); 

Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 
Serial.println (sensor2.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 

delay (1000); 

Serial.println ( "Taking Values from the sensor" );

delay (1000);

//sg90.write(0);

}




void loop ( ) 

{ 

sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);
sensor2.getMotion6 (&ax2, &ay2, &az2, &gx2, &gy2, &gz2);

ax = map (ax, -17000, 17000, 0, 180) ;
ax2 = map (ax, -17000, 17000, 0, 180) ;

//Serial.println (ax);

sg90.write (ax); 
sg902.write (ax2);

Serial.println("Motor 1 : " );
Serial.print(sg90.read()); // get the last position of servo 
Serial.println("\n Motor2: ") ;
Serial.println(sg902.read());

delay (200);

}


        
