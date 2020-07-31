#ifndef WEB_SERVER_SCHEDULED_H
#define WEB_SERVER_SHCEDULED_H

void startZone(byte num, byte time, String webhook);
void startProgram(byte num, String webhook);
void stopZone(byte num, String webhook);

#endif