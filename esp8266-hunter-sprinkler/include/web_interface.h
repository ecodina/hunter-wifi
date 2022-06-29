#ifndef WEB_INTERFACE_H
#define WEB_INTERFACE_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>

struct WebInterface
{
    public:
        String header;
        String body;
        String footer;
};

void handleHomePage(AsyncWebServerRequest *request);
void handleRunZone(AsyncWebServerRequest *request);
void handleRunProgram(AsyncWebServerRequest *request);

#endif