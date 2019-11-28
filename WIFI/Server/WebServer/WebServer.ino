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

//SSID and Password of your WiFi router
const char* ssid = "redwifi2";
const char* password = "66778866";

ESP8266WebServer server(80); //Server on port 80

String STATE = "";
String SP = "";
String TEMP = "";
String Status = "";
bool reading = false;

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String r = MAIN_page; //Read HTML contents
 server.send(200, "text/html", r); //Send web page
}

void handleSP() {
 String value = server.arg("value"); 
 Serial.println("SP="+value);
 server.send(200, "text/plane", value); //Send web page
}

void handleDATA() {
  while (reading) {}
  server.send(200, "text/plane", Status); //Send web page
}

void handleSTART() {
  String value = server.arg("value"); 
  if (value.equals("1")) {
    Serial.println("START");
  }
  else {
    Serial.println("STOP");
  }
}

//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  //Onboard LED port Direction output
  pinMode(LED,OUTPUT); 
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/send", handleSP);   // handles new set point
  server.on("/read", handleDATA);
  server.on("/start", handleSTART);
  

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
  if (Serial.available()) {
    serialEvent();
  }
}

void serialEvent() {
  reading = true;
  Status = Serial.readString();
  reading = false;
}
