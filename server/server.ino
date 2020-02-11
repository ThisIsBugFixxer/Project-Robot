#include <ESP8266WiFi.h>

IPAddress local_IP(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

WiFiServer server(80);

int ledPin = 13;            

void setup(){

    Serial.begin(9600);

    
    Serial.print("Setting soft-AP configuration ... ");
    Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

    Serial.print("Setting soft-AP ... ");
    Serial.println(WiFi.softAP("Robot Network","password01",1,false,1) ? "Ready" : "Failed!"); // change the wifi soft ap  argument false to true to hide it.

    Serial.println("IP Address is :   " ); Serial.print(WiFi.softAPIP());

    server.begin();

    pinMode(ledPin, OUTPUT);

}

void loop(){

    WiFiClient client = server.available();
    if (client) {
    if (client.connected()) {
    digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
      String request = client.readStringUntil('\r');    // receives the message from the client
      Serial.print("From client: "); Serial.println(request);
      client.flush();
      client.println("Hi client! No, I am listening.\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();                // tarminates the connection with the client
  }

}
