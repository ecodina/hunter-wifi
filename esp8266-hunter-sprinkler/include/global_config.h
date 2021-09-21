/**
 * Header file that includes default parameters for all parts of the program
 */

#ifndef GLOBAL_CONFIG_H
#define GLOBAL_CONFIG_H

#define SERIAL_SPEED 9600
#define REM_PIN 16
#include <Arduino.h>

// WIFi
extern const String device_hostname;
#define SSID_AP    "WateringSystemAP"   // SSID of the AP created to configure WiFi
#define PWD_AP     ""                   // Password of the AP created to configure WiFi

//MQTT
extern const char* mqtt_server;
extern const int mqtt_port; //default is 1883
extern const char *mqtt_user;
extern const char *mqtt_pass;

#endif
