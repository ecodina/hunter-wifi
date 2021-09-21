/**
 * This file includes all the functions that are scheduled to run after returning a response to the client.
 * The client asks to do some action with the Hunter Irrigation System and these functions contain the
 * necessary logic to perform it and send the result to a webhook.
 * 
 * First version: July 2020 - Eloi Codina Torras
 */

#include <HunterRoam.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <global_config.h>
#include <web_server_scheduled.h>

HunterRoam smartPort(REM_PIN);
HTTPClient http;
WiFiClient wifi;

/**
 * Send the result of the action performed on the Hunter Irrigation System to a 
 * webhook given by the client when it made the petition.
 * 
 * @param toSend information that will be sent. Probably JSON formatted
 * @param webhook url where the information will be sent
 */
void sendResult(String toSend, String webhook) {
    http.begin(wifi, webhook);
    http.addHeader("Content-Type", "application/json"); 
    http.POST(toSend);
    http.end();
}

/**
 * Start a zone and send the result of the action to the webhook given by the client.
 * 
 * @param num zone number
 * @param time irrigation minutes
 * @param webhook url where the result will be sent
 */
void startZone(byte num, byte time, String webhook) {
    
    byte result = smartPort.startZone(num, time);

    String toSend = "{";
    toSend = toSend + "\"action\": \"Start zone " + (String)num + " for " + (String)time + " minutes.\",";
    toSend = toSend + "\"action_num\": 1,";
    toSend = toSend + "\"zone\": " + (String)num + ",";
    toSend = toSend + "\"result\": \"" + smartPort.errorHint(result) + "\",";
    toSend = toSend + "\"result_num\": " + (String)result;
    toSend = toSend + "}";
    
    sendResult(toSend, webhook);    
}

/**
 * Stop a zone and send the result of the action to the webhook given by the client.
 * 
 * @param num zone number
 * @param webhook url where the result will be sent
 */
void stopZone(byte num, String webhook) {
    byte result = smartPort.stopZone(num);

    String toSend = "{";
    toSend = toSend + "\"action\": \"Stop zone " + (String)num + ".\",";
    toSend = toSend + "\"action_num\": 2,";
    toSend = toSend + "\"zone\": \"" + (String)num + "\",";
    toSend = toSend + "\"result\": \"" + smartPort.errorHint(result) + "\",";
    toSend = toSend + "\"result_num\": " + (String)result;
    toSend = toSend + "}";
    
    sendResult(toSend, webhook);    
}

/**
 * Start a program and send the result of the action to the webhook given by the client.
 * 
 * @param num program number
 * @param webhook url where the result will be sent
 */
void startProgram(byte num, String webhook) {
    byte result = smartPort.startProgram(num);

    String toSend = "{";
    toSend = toSend + "\"action\": \"Start program " + (String)num + ".\",";
    toSend = toSend + "\"action_num\": 3,";
    toSend = toSend + "\"program\": " + (String)num + ",";
    toSend = toSend + "\"result\": \"" + smartPort.errorHint(result) + "\",";
    toSend = toSend + "\"result_num\": " + (String)result;
    toSend = toSend + "}";
    
    sendResult(toSend, webhook);    
}
