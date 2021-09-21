/**
 * This file includes sets up the web server to serve teh API and webpage
 * to esily control the Hunter Irrigation System.
 * 
 * First version: July 2020 - Eloi Codina Torras
 */
#include <FS.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h>

#include <global_config.h>
#include <web_server.h>
#include <web_server_api.h>


/**
 * Configure the paths and start the server.
 */
void setupWebServer() {
    if (!MDNS.begin(device_hostname.c_str())) {
        Serial.println("Error setting up MDNS responder!");
        while (1) {
            delay(1000);
        }
    }
    Serial.println("mDNS responder started");
    setupAPIRoutes();
    server.begin();
    MDNS.addService("http", "tcp", 80);
}

/**
 * Set up all the API routes
 */
void setupAPIRoutes() {
    server.on("/api/start/zone", HTTP_GET, startZoneRequest);
    
    server.on("/api/start/program", HTTP_GET, startProgramRequest);

    server.on("/api/stop/zone", HTTP_GET, stopZoneRequest);

    server.on("/api/start", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(400, "text/plain", "What should I start?");
    });
    
    server.on("/api", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(403, "text/plain", "This is the API root");
    });
}
