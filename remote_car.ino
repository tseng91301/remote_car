#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

#include "bottom_func.h"
#include "motors.h"
#include "page.h"
#include "wifi_remote.h"
Car car(D1,D2,D3,D4);
void setup(){
    Serial.begin(115200);
    // Connecting WiFi
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    
    // Starting WEB-server 
    server.on ( "/", HTTP_handleRoot );
    server.onNotFound ( HTTP_handleRoot );
    server.begin();   
}
void loop(){
    server.handleClient();
    String command = server.arg("State");
    handle_command(command,car);
    car.motor_turn();

}