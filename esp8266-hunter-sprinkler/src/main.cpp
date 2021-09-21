/**
 * First version: July 2020 - Eloi Codina Torras
 */
#include <wifi.h>
#include <FS.h>
#include <ESP8266mDNS.h>

#include <web_server.h>
#include <global_config.h>

AsyncWebServer server = AsyncWebServer(80);
bool wifiDisconnected = false;

void setup() {
    Serial.begin(SERIAL_SPEED);

    setupWifi();
    setupWebServer();

  /*  if (!SPIFFS.begin()) {
      Serial.println("Error mounting the filesystem.");
    } else {
      Serial.println("Filesystem is now ready.");
    }
    */

}

void loop() {
    wifiDisconnected = checkWifiConnection(wifiDisconnected);
    MDNS.update();
}
