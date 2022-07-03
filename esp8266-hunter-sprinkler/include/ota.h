#ifndef OTA_H
#define OTA_H

#include <ESPAsyncWebServer.h>

void handleUpdate(AsyncWebServerRequest *request);
void handleWebInterface(AsyncWebServerRequest *request);
void handleDoUpdate(AsyncWebServerRequest *request, const String& filename, size_t index, uint8_t *data, size_t len, bool final);
void printProgress(size_t prg, size_t sz);

#endif