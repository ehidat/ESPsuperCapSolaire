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
        <script>
        	
            async function getRSSI() {
                const request = await fetch('/refreshRSSI', {
                    method: 'GET'
                })

                const status = request.status
                const ok = request.ok

                const json = await request.json()
                console.log("json",json)
                
                const element = document.getElementById("target")
                element.innerHTML = json
            }

        </script>
    </head>
    <body>
        <button type="button" onclick="getRSSI()">Actualiser RSSI</button>
        <div id="target" />
    </body>
</html>
)=====";

void handleRoot(){
    serveurWeb.send(200, "text/html", index_html);
}

void refreshRssi(){
    String rssiString = String(WiFi.RSSI());
    serveurWeb.send(200, "application/json", rssiString);
}