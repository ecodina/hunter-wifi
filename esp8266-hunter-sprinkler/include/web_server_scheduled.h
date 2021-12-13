#ifndef WEB_SERVER_SCHEDULED_H
#define WEB_SERVER_SCHEDULED_H

#include <ESPAsyncWebServer.h>

void startZone(byte num, byte time, String webhook);
void startProgram(byte num, String webhook);
void stopZone(byte num, String webhook);

#endif