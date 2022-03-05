#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "serveur.h"

ESP8266WebServer serveurWeb(80);

const char index_html[] PROGMEM = R"=====(
  <!doctype html>
<html lang="fr">
    <head>
        <meta charset="utf-8">
        <title>Serveur test</title>
    </head>
    <body>
        <a href="/refreshRSSI">
            <button>Actualiser RSSI</button>
        </a>
    </body>
</html>
)=====";

void handleRoot(){
    serveurWeb.send(200, "text/html", index_html);
}

void refreshRssi(){
    String rssiString = String(WiFi.RSSI());
}