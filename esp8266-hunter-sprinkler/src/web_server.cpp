/**
 * This file includes sets up the web server to serve teh API and webpage
 * to esily control the Hunter Irrigation System.
 *
 * First version: July 2020 - Eloi Codina Torras
 */
#include <ESPAsyncTCP.h>
#include <ESP8266mDNS.h>

#include <global_config.h>
#include <web_server.h>
#include <web_server_api.h>
#include <web_interface.h>
#include <ota.h>

/**
 * Configure the paths and start the server.
 */
void setup_WebServer()
{
    if (!MDNS.begin(HOSTNAME))
    {
        Serial.println("Error setting up MDNS responder!");
        while (1)
        {
            delay(1000);
        }
    }
    Serial.println("mDNS responder started");
    setup_APIRoutes();
    server.begin();
    MDNS.setHostname(HOSTNAME);
    MDNS.addService("http", "tcp", 80);
}

/**
 * Set up all the API routes
 */
void setup_APIRoutes()
{
    server.on("/api/start/zone", HTTP_GET, startZoneRequest);
    server.on("/api/start/program", HTTP_GET, startProgramRequest);
    server.on("/api/stop/zone", HTTP_GET, stopZoneRequest);
    server.on("/api/start", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send_P(400, "text/plain", "What should I start?"); });
    server.on("/api", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send_P(403, "text/plain", "This is the API root"); });
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->redirect("/update"); });
    server.on("/update", HTTP_GET, [](AsyncWebServerRequest *request)
              { handleUpdate(request); });
    server.on("/control", HTTP_GET, [](AsyncWebServerRequest *request)
              { handleWebInterface(request); });
    server.on(
        "/doUpdate", HTTP_POST,
        [](AsyncWebServerRequest *request) {},
        [](AsyncWebServerRequest *request, const String &filename, size_t index, uint8_t *data,
           size_t len, bool final)
        { handleDoUpdate(request, filename, index, data, len, final); });

    server.onNotFound([](AsyncWebServerRequest *request)
                      { request->send(404); });
}