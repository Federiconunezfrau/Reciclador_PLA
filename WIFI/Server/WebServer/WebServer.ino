/*
 * ESP8266 NodeMCU AJAX Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h" //Our HTML webpage contents with javascripts

#define LED 2  //On board LED
#define TIME_INTERVAL 1000
//SSID and Password of your WiFi router
const char* ssid = "Ema";
const char* password = "perrosiberiano";

ESP8266WebServer server(80); //Server on port 80

String STATE = "";
String SP = "";
String TEMP = "";
String Status = "";
bool reading = false;
unsigned long previousMillis = 0; 

//===============================================================
// RUTINAS DE MANEJO DE GET REQUESTS
//===============================================================
//PAGINA PRINCIPAL
void handleRoot() {                                                           
 String r = MAIN_page; //Read HTML contents
 server.send(200, "text/html", r); //Send web page
}

//SET SP
void handleSP() {
 String value = server.arg("value"); 
 Serial.print("?SSP"+value);
 Serial.print("\n");
 server.send(200, "text/plane", value); //Send web page
}

//ENVIO DE STATUS 
void handleDATA() {
  while (reading) {}
  server.send(200, "text/plane", Status); //Send web page
}

//CONTROL DE START/STOP
void handleSTART() {
  String value = server.arg("value"); 
  if (value.equals("1")) {
    Serial.print("?SST001");
    Serial.print("\n");
  }
  else {
    Serial.print("?SST000");
    Serial.print("\n");
  }
}

//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router

  //Onboard LED port Direction output
  pinMode(LED, OUTPUT); 
  digitalWrite(LED, HIGH);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/sp", handleSP);   // handles new set point
  server.on("/read", handleDATA);
  server.on("/start", handleSTART);
  
  digitalWrite(LED, LOW);
  server.begin();                  //Start server
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
  
  if (Serial.available()) {
    serialEvent();
  }
  
  if (millis() - previousMillis >= 1000) {
    // save the last time you blinked the LED
    previousMillis = millis();
    if (WiFi.status() != WL_CONNECTED) {
      Serial.print("0.0.0.0");  //IP address assigned to your ESP
      Serial.print("\n");  //IP address assigned to your ESP
      digitalWrite(LED, HIGH);
    }
    else {
      Serial.print(WiFi.localIP().toString());  //IP address assigned to your ESP
      Serial.print("\n");  //IP address assigned to your ESP
      digitalWrite(LED, LOW);
    }
  }
  
}

void serialEvent() {
  //char c;
  reading = true;
  Status = Serial.readString();
  reading = false;
}
