/**
 * First version: July 2020 - Eloi Codina Torras
 */
#include <wifi.h>
#include <Arduino.h>
#include <FS.h>

#include <web_server.h>
#include <global_config.h>

AsyncWebServer server = AsyncWebServer(80);

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
}