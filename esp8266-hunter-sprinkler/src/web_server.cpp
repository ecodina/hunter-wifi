/**
 * This file includes sets up the web server to serve teh API and webpage
 * to esily control the Hunter Irrigation System.
 * 
 * First version: July 2020 - Eloi Codina Torras
 */
#include <FS.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include <web_server.h>
#include <web_server_api.h>


/**
 * Configure the paths and start the server.
 */
void setupWebServer() {

    setupAPIRoutes();

    server.begin();
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
