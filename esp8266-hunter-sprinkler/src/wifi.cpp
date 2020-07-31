/**
 * Connect to WiFi or setup a captive portal to configure WiFi parameters.
 * 
 * First version: July 2020 - Eloi Codina Torras
 */

#include <wifi.h>

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