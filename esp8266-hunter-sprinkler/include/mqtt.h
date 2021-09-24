#ifndef MQTT_H
#define MQTT_H

#include <global_config.h>
#include <PubSubClient.h>

extern String TopicCheckIn;
extern String TopicCommands;
extern String TopicStatus;
extern PubSubClient client;
extern WiFiClient espClient;

void mqtt_connect();
void mqttPublishResult(const char *toSend);
void mqtt_subscribe_topics ();
void callback(char* topic, byte* payload, unsigned int length);

#endif