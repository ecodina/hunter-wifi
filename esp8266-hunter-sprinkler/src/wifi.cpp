#include <wifi.h>
#include <mqtt.h>


void setup_wifi() {
  WiFi.hostname(HOSTNAME);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void reconnect() {
  // Loop until we're reconnected to the MQTT server 
  int retries = 0;
  while (!client.connected()) {
    if(retries < 50) {
      mqtt_connect();
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