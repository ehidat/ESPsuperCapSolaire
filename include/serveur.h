#ifndef SERVEUR_H
#define SERVEUR_H
#include <Arduino.h>
//#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Bbox-74CB3A7E"; 
const char* password = "H7fyyMSS79khtSvzRW";

extern ESP8266WebServer serveurWeb;
void handleRoot();
void refreshRssi();

#endif