#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "serveur.h"

const char* ssid = "Bbox-74CB3A7E"; 
const char* password = "H7fyyMSS79khtSvzRW";
extern ESP8266WebServer serveurWeb;


void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(3000);
    ESP.restart();
  }

  ArduinoOTA.setHostname("espCapSol"); // on donne une petit nom a notre module
  ArduinoOTA.begin();

  serveurWeb.on("/refreshRSSI", refreshRssi);
  serveurWeb.on("/", handleRoot);
  serveurWeb.begin();
}

void loop() {
  /*Serial.println("Adresse IP : " + WiFi.localIP().toString());
  String rssiString = String(WiFi.RSSI());
  Serial.println("Puissance signal : " + rssiString);*/
  serveurWeb.handleClient();
  delay(1000);

  ArduinoOTA.handle();
}

