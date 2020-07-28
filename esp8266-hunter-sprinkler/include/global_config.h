/**
 * Header file that includes default parameters for all parts of the program
 */

#ifndef GLOBAL_CONFIG_H
#define GLOBAL_CONFIG_H

#define SERIAL_SPEED 9600

// WIFi
#define DHCP_NAME  "WateringSystem"
#define SSID_AP    "WateringSystemAP"   // SSID of the AP created to configure WiFi
#define PWD_AP     ""                   // Password of the AP created to configure WiFi
#define TIMEOUT_AP 10                   // (seconds) time during the AP will be visible if credentials
                                        // were already stored. Each time the ESP8266 boots, it will
                                        // pause during this time.

#endif