#include <wifi.h>
#include <ESP_WiFiManager.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <global_config.h>  


void setupWifi() {
    ESP_WiFiManager wifiManager(DHCP_NAME);
    wifiManager.setMinimumSignalQuality(-1);

    // These variables stores the network parameters
    String ssidWiFi = wifiManager.WiFi_SSID();
    String pwdWiFi = wifiManager.WiFi_Pass();
    
    // These variables store the AP parameters to configure WiFi
    String ssidAP = SSID_AP;
    const char* pwdAP = PWD_AP;

    if (ssidWiFi != "") {
        wifiManager.setConfigPortalTimeout(TIMEOUT_AP);
    }  

    // Start the access point and block loop until configured
    wifiManager.startConfigPortal((const char *) ssidAP.c_str(), pwdAP);

    // WiFi had already been configured before and nothing has changed on the ConfigPortal
    unsigned long startedAt = millis();
    while ( (WiFi.status() != WL_CONNECTED) && (millis() - startedAt < WIFI_CONNECT_TIMEOUT ) ) {
        WiFi.mode(WIFI_STA);
        WiFi.persistent(true);

        // Try to connect to a WiFi network
        WiFi.begin(ssidWiFi.c_str(), pwdWiFi.c_str());

        // Check if WiFi is connected
        int i = 0;
        while ((!WiFi.status() || WiFi.status() >= WL_DISCONNECTED) && i++ < WHILE_LOOP_STEPS) {
        delay(WHILE_LOOP_DELAY);
        }
    }

}