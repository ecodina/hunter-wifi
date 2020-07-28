#include <ESPAsyncTCP.h>
#include <FS.h>
#include <web_server.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

void setupWebServer() {
    
    server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "prova");
  });

  server.begin();
  
}
