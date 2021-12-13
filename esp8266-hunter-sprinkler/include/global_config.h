#ifndef GLOBAL_CONFIG_H
#define GLOBAL_CONFIG_H

#define SERIAL_SPEED 9600
#define REM_PIN 16

#define SSID_AP    "WateringSystemAP"   // SSID of the AP created to configure WiFi
#define PWD_AP     ""                   // Password of the AP created to configure WiFi
#define HOSTNAME "X-CORE"

extern bool shouldSaveConfig;
void saveConfigCallback ();

#endif
