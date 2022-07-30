/**
 * Connect to WiFi or setup a captive portal to configure WiFi parameters.
 *
 * First version: July 2020 - Eloi Codina Torras
 */

#include <DNSServer.h>

#include <global_config.h>
#include <mqtt.h>
#include <web_server.h>
#include <wifi.h>

MQTT setup_wifi() {
  DNSServer dns;
  MQTT MqttSettings;
  char MQTT_SERVER[40] = {0};
  char MQTT_PORT[6] = "1883";
  char MQTT_USER[100] = {0};
  char MQTT_PASSWORD[100] = {0};
  WiFi.persistent(true);
  AsyncWiFiManagerParameter custom_mqtt_enable("enable", "Enable MQTT (1/0)", 0,
                                               1);
  AsyncWiFiManagerParameter custom_mqtt_server("server", "MQTT server",
                                               MQTT_SERVER, 40);
  AsyncWiFiManagerParameter custom_mqtt_port("port", "MQTT port", MQTT_PORT, 5);
  AsyncWiFiManagerParameter custom_mqtt_username("username", "MQTT username",
                                                 MQTT_USER, 100);
  AsyncWiFiManagerParameter custom_mqtt_password("password", "MQTT password",
                                                 MQTT_PASSWORD, 100);
  AsyncWiFiManager wifiManager(&server, &dns);
  wifiManager.setSaveConfigCallback(saveConfigCallback);
  wifiManager.addParameter(&custom_mqtt_enable);
  wifiManager.addParameter(&custom_mqtt_server);
  wifiManager.addParameter(&custom_mqtt_port);
  wifiManager.addParameter(&custom_mqtt_username);
  wifiManager.addParameter(&custom_mqtt_password);
  // wifiManager.resetSettings();
  wifiManager.autoConnect(SSID_AP, PWD_AP);
  MqttSettings.server = custom_mqtt_server.getValue();
  String port_number = custom_mqtt_port.getValue();
  MqttSettings.port = port_number.toInt();
  MqttSettings.username = custom_mqtt_username.getValue();
  MqttSettings.password = custom_mqtt_password.getValue();
  String en = custom_mqtt_enable.getValue();
  MqttSettings.enable = (bool)en.toInt();
  return MqttSettings;
}

/*
 * Checks, every 5 seconds, if WiFi is still active.
 * The first time it detects WiFi is not active, it returns "true".
 * If the next time this function is called (so nextTimeShouldReboot == true),
 * WiFi is still not active, it restarts ESP8266.
 *
 * @param nextTimeShouldReboot should be true if the last time WiFi connection
 * was checked, it was disconnected.
 */

bool checkWifiConnection(bool nextTimeShouldReboot) {
  delay(5000);
  if (WiFi.status() != WL_CONNECTED) {
    if (!nextTimeShouldReboot) {
      return true;
    }
    ESP.restart();
  }
  return false;
}