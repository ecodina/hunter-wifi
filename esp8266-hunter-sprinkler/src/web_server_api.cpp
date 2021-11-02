/**
 * This file includes all the functions that are called by the webserver to serve API paths.
 * It makes it easier to control the actions to be performed to the Hunter Irrigation System.
 * 
 * First version: July 2020 - Eloi Codina Torras
 */
#include <Schedule.h>

#include <web_server_scheduled.h>
#include <web_server_api.h>

/**
 * Extract the latest parameter on the URL given the request and the base path.
 * It has to be done with this "hack" as REGEX doesnt't work properly on the
 * ESP8266 currently.
 * 
 * Example:
 * AsyncWebServerRequest request </api/start/zone/3>
 * int id = getIdFromURL(request, "/api/start/zone/");
 * Serial.println(id);
 *  --> 3
 * 
 * @param request request made by the client
 * @param root base path of the URL.
 */
int getIdFromURL(AsyncWebServerRequest *request, String root) {
    String string_id = request->url();
    string_id.replace(root, "");
    int id = string_id.toInt();
    return id;
}

/**
 * Function to be called when the client makes a request to
 * /api/start/zone
 * It checks that all the parameters have been passed and schedules a function to
 * be run at the next loop to start the zone with the HunterRoam library.
 * 
 * @param request request made by the client
 */
void startZoneRequest(AsyncWebServerRequest *request) {
    if (!(request->hasParam("time"))) {
        request ->send_P(400, "text/plain", "Please include parameter 'time'.");
    } else {
        byte num = getIdFromURL(request, "/api/start/zone/");
        byte time = request->getParam("time")->value().toInt();

        String result;
        String toReturn;
        if (!(request->hasParam("result"))) {
            result = "";
            toReturn = "\"As you have not specified a 'result' argument, the result of the operation can't be send to you.\"";
        } else {
            result = (String)request->getParam("result")->value();
            toReturn = "\"After the action, the result will be sent to the webhook url you have specified.\"";
        }

        schedule_function([num, time, result](){
          startZone(num, time, result);
        });

        request->send_P(200, "application/json", ((String)"{\"status\": \"Request received and processed correctly.\"," + 
                                                   (String)"\"result\": " + toReturn + "}").c_str());
     }
}

/**
 * Function to be called when the client makes a request to
 * /api/start/program
 * It checks that all the parameters have been passed and schedules a function to
 * be run at the next loop to start the program with the HunterRoam library.
 * 
 * @param request request made by the client
 */
void startProgramRequest(AsyncWebServerRequest *request) {

    String result;
    String toReturn;
    if (!(request->hasParam("result"))) {
        result = "";
        toReturn = "\"As you have not specified a 'result' argument, the result of the operation can't be send to you.\"";
    } else {
        result = request->getParam("result")->value();
        toReturn = "\"After the action, the result will be sent to the webhook url you have specified.\"";
    }

    byte num = getIdFromURL(request, "/api/start/program/");
    schedule_function([num, result](){
        startProgram(num, result);
    });

    request->send_P(200, "application/json", ((String)"{\"status\": \"Request received and processed correctly.\"," + 
                                                   (String)"\"result\": " + toReturn + "}").c_str());
     
}

/**
 * Function to be called when the client makes a request to
 * /api/stop/zone
 * It checks that all the parameters have been passed and schedules a function to
 * be run at the next loop to stop the zone with the HunterRoam library.
 * 
 * @param request request made by the client
 */
void stopZoneRequest(AsyncWebServerRequest *request) {

    String result;
    String toReturn;
    if (!(request->hasParam("result"))) {
        result = "";
        toReturn = "\"As you have not specified a 'result' argument, the result of the operation can't be send to you.\"";
    } else {
        result = request->getParam("result")->value();
        toReturn = "\"After the action, the result will be sent to the webhook url you have specified.\"";
    }

    byte num = getIdFromURL(request, "/api/stop/zone/");
    schedule_function([num, result](){
        stopZone(num, result);
    });

    request->send_P(200, "application/json", ((String)"{\"status\": \"Request received and processed correctly.\"," + 
                                                   (String)"\"result\": " + toReturn + "}").c_str());     
}