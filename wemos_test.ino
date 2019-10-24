#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

#include <Wire.h> 


const char* ssid = "SSID";
const char* password = "PASS_SSID";

  
void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");

  //show your IP
  Serial.println(WiFi.localIP());

  delay(1500);
  
}

void loop(){
  // Check WiFi Status
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  //Object of class HTTPClient
    http.begin("YOUR URL");
    int httpCode = http.GET();

    //Check the returning code  
    String pay = http.getString();
    Serial.println(pay);

    //Close connection
    http.end();   
  }

  delay(500);
 
}
