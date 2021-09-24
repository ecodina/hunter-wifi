#include <ESP8266mDNS.h>

#include <wifi.h>
#include <mqtt.h>
#include <web_server.h>

AsyncWebServer server = AsyncWebServer(80);

void setup() {
  Serial.begin(SERIAL_SPEED);
  WiFi.mode(WIFI_STA);
  setup_wifi();
  setup_WebServer();
  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(callback);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.printf("Ready! Open http://%s.local in your browser\n", HOSTNAME);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  MDNS.update();
  //timer.run();
}