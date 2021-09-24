#ifndef WEB_SERVER_API_H
#define WEB_SERVER_API_H

#include <ESPAsyncWebServer.h>

void startZoneRequest(AsyncWebServerRequest *request);
void startProgramRequest(AsyncWebServerRequest *request);
void stopZoneRequest(AsyncWebServerRequest *request);
int getIdFromURL(AsyncWebServerRequest *request, String root);

#endif