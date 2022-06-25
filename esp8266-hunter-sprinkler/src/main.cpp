/**
 * First version: July 2020 - Eloi Codina Torras
 */
#include <ESP8266mDNS.h>
#include "LittleFS.h"
#include <ArduinoJson.h>

#include <wifi.h>
#include <mqtt.h>
#include <web_server.h>

AsyncWebServer server = AsyncWebServer(80);
bool wifiDisconnected = false;
bool enableMQTT = true;
MQTT MqttSettings;
MQTT from_wifi_manager;

void setup() {
  Serial.begin(SERIAL_SPEED);
// WiFi.mode(WIFI_STA);
  Serial.println("mounting FS...");
  if (LittleFS.begin()) {
    Serial.println("mounted file system");
    if (LittleFS.exists("/config.json")) {
      //file exists, reading and loading
      Serial.println("reading config file");
      File configFile = LittleFS.open("/config.json", "r");
      if (configFile) {
        Serial.println("opened config file");
        DynamicJsonDocument doc(1024);
        DeserializationError error = deserializeJson(doc, configFile);
        serializeJson(doc, Serial);
        if (error) {
          Serial.print(F("\ndeserializeJson() failed: "));
          Serial.println(error.c_str());
          Serial.println("failed to load json config");
        } else {
          Serial.println("\njson successfully parsed");
          MqttSettings.server = doc["mqtt_server"].as<String>();
          MqttSettings.port = doc["mqtt_port"];
          MqttSettings.username = doc["mqtt_username"].as<String>();
          MqttSettings.password = doc["mqtt_password"].as<String>();
          MqttSettings.enable = doc["mqtt_enable"].as<bool>();
        }
      }
    }
   } else {
     Serial.println("failed to mount FS");
   }
   // this is here just to make sure that if wifimanager is
   // skipped when config is saved, MQTT still works, otherwise empty data would override
   // what we learned from config file saved on disk
   from_wifi_manager = setup_wifi();
   if (from_wifi_manager.server != "" ){
     MqttSettings = from_wifi_manager;
   }
   setup_WebServer();
   if (shouldSaveConfig) {
     Serial.println("saving config");
     DynamicJsonDocument doc(1024);
     doc["mqtt_server"] =  MqttSettings.server;
     doc["mqtt_port"] = MqttSettings.port;
     doc["mqtt_username"] = MqttSettings.username;
     doc["mqtt_password"] = MqttSettings.password;
     doc["mqtt_enable"] = MqttSettings.enable;
     File configFile = LittleFS.open("/config.json", "w");
     if (!configFile) {
       Serial.println("failed to open config file for writing");
     }
     serializeJson(doc, Serial);
     serializeJsonPretty(doc, configFile);
     configFile.close();
     //end save
   }
   if (MqttSettings.enable) {
     client.setServer(MqttSettings.server.c_str(), MqttSettings.port);
     client.setCallback(mqtt_callback);
   }
   Serial.print("\nIP address: ");
   Serial.println(WiFi.localIP());
   Serial.printf("%s:%d\n", MqttSettings.server.c_str(), MqttSettings.port);
   Serial.printf("Ready! Open http://%s.local in your browser\n", HOSTNAME);
}

void loop() {
  if (MqttSettings.enable) {
    if (!client.connected()) {
      int retries = 0;
      while (!client.connected()) {
        if(retries < 50) {
          mqtt_connect(MqttSettings.username.c_str(),MqttSettings.password.c_str());
        }
        else {
          retries++;
          // Wait 5 seconds before retrying
          delay(5000);
        }
        if(retries >= 50) {
        ESP.restart();
        }
      }
    }
  }
  //wifiDisconnected = checkWifiConnection(wifiDisconnected);
  client.loop();
  MDNS.update();
  //timer.run();
}