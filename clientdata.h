#include <ESP8266WiFi.h>


const char* host = "192.168.4.22";
const uint16_t port = 3000;

IPAddress FIXEDIP(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);



 WiFiClient client;

void connect_setup() {
  // put your setup code here, to run once:

  
  WiFi.begin("Robot Network","password01");
  WiFi.config(FIXEDIP,gateway,subnet);




  WiFi.mode(WIFI_STA);

  while (WiFi.status() != WL_CONNECTED){
      Serial.print(".");
      delay(500);


  }

  
  Serial.println("connected to : " + WiFi.localIP());

  WiFi.setAutoConnect(true);


  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    Serial.println("wait 5 sec...");
    delay(5000);
    return;


}


void SendData(int data) {
  /*
  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;

  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    Serial.println("wait 5 sec...");
    delay(5000);
    return;
  }
*/

  // This will send the request to the server
  //client.println("hello from ESP8266");
  client.println(data);

  //read back one line from server
  Serial.println("receiving from remote server");
  String line = client.readStringUntil('\r');
  Serial.println(line);
/*
  Serial.println("closing connection");
  client.stop();

  Serial.println("wait 5 sec...");
  */
  delay(500);
}
