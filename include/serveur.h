#ifndef SERVEUR_H
#define SERVEUR_H
#include <Arduino.h>
//#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

extern ESP8266WebServer serveurWeb;
void handleRoot();
void refreshRssi();

#endif