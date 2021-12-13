#ifndef MQTT_H
#define MQTT_H

#include <global_config.h>
#include <PubSubClient.h>

class MQTT
{
	public:
		String server;
        int port;
        String username;
        String password;
};

extern String TopicCheckIn;
extern String TopicCommands;
extern String TopicStatus;
extern PubSubClient client;
extern WiFiClient espClient;

extern String device_hostname;
extern String TopicCheckIn;
extern String TopicResult;
extern String TopicZone;
extern String TopicProgram;

void mqtt_connect(const char *MQTT_USER, const char *MQTT_PASSWORD);
void mqttPublishResult(const char *toSend);
void mqtt_subscribe_topics ();
void mqtt_callback(char* topic, byte* payload, unsigned int length);

#endif