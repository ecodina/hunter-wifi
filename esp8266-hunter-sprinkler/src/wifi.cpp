/**
 * Connect to WiFi or setup a captive portal to configure WiFi parameters.
 * 
 * First version: July 2020 - Eloi Codina Torras
 */

#include <wifi.h>

#include <ESP8266WiFi.h>
#include <ESPAsyncWiFiManager.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>

#include <Arduino.h>
#include <DNSServer.h>

#include <global_config.h>  
#include <web_server.h>

void setupWifi() {
    DNSServer dns;

    AsyncWiFiManager wifiManager(&server, &dns);
    //wifiManager.resetSettings();
    
    wifiManager.autoConnect(SSID_AP, PWD_AP);

}

/*
 * Checks, every 5 seconds, if WiFi is still active.
 * The first time it detects WiFi is not active, it returns "true".
 * If the next time this function is called (so nextTimeShouldReboot == true), WiFi is still not active,
 * it restarts ESP8266.
 * 
 * @param nextTimeShouldReboot should be true if the last time WiFi connection was checked, it was disconnected.
 */
bool checkWifiConnection(bool nextTimeShouldReboot) {
    delay(5000);
    if (WiFi.status() != WL_CONNECTED) {
        if (!nextTimeShouldReboot) {
            return true;
        }
        ESP.restart();
    }
    return false;
}