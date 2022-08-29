#include <Arduino.h>

#include <global_config.h>

bool shouldSaveConfig = false;

// callback notifying us of the need to save config
void saveConfigCallback() {
  Serial.println("Should save config");
  shouldSaveConfig = true;
}