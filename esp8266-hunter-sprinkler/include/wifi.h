#ifndef WIFI_H
#define WIFI_H

#include <ESP8266WiFi.h>
#include <ESPAsyncWiFiManager.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>

#include <global_config.h>

MQTT setup_wifi();
bool checkWifiConnection(bool nextTimeShouldReboot);

#endif
