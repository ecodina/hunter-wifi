#include "LittleFS.h"
#include <web_interface.h>

void handleHomePage(AsyncWebServerRequest *request) {
  request->send(LittleFS, "/index.html", String());
}

void handleRunZone(AsyncWebServerRequest *request) {
  request->send(LittleFS, "/runzone.html", String());
}

void handleRunProgram(AsyncWebServerRequest *request) {
  request->send(LittleFS, "/runprogram.html", String());
}