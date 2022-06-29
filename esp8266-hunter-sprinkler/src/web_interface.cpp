#include <web_interface.h>
#include "LittleFS.h"

WebInterface interface =
{
  "<head>\
<script type=\"text/javascript\">\
function submitzoneform() {\
document.getElementById(\"zoneControl\").action = \"api/start/zone/\"+document.getElementById(\"zone\").value+\"?time=\"+document.getElementById(\"time\").value;\
return true;\
}\
</script>\
<link rel=\"stylesheet\" href=\"https://unpkg.com/purecss@2.1.0/build/pure-min.css\" integrity=\"sha384-yHIFVG6ClnONEA5yB5DJXfW2/KC173DIQrYoZMEtBvGzmf0PKiGyNEqe9N6BNDBH\" crossorigin=\"anonymous\">\
<link rel=\"stylesheet\" href=\"https://unpkg.com/purecss@1.0.1/build/base-min.css\">\
<meta name='viewport' content='width=device-width, initial-scale=1.0'>\
</head>",
  "<body> \
<form method=\"get\" id=\"zoneControl\" class='pure-form-stacked'>\
<fieldset>\
<legend>Run Single Zone</legend>\
<input type=\"text\" id=\"zone\" onchange=\"submitzoneform()\"/ placeholder='Zone'><br/>\
<input type=\"text\" id=\"time\" onchange=\"submitzoneform()\" placeholder='Run Time'>\
<button type=\"submit\" class='pure-button pure-button-primary'>Submit</button>\
</fieldset>\
</form>\
</body>",
  ""
};
WebInterface runProgramInterface = 
{
  "<head>\
<script type=\"text/javascript\">\
  function submitprogramform(selected) {\
    document.getElementById(\"programControl\").action = \"api/start/program/\"+selected;\
    return true;\
  }\
</script>\
<link rel=\"stylesheet\" href=\"https://unpkg.com/purecss@1.0.1/build/base-min.css\">\
<link rel=\"stylesheet\" href=\"https://unpkg.com/purecss@2.1.0/build/pure-min.css\" integrity=\"sha384-yHIFVG6ClnONEA5yB5DJXfW2/KC173DIQrYoZMEtBvGzmf0PKiGyNEqe9N6BNDBH\" crossorigin=\"anonymous\">\
<meta name='viewport' content='width=device-width, initial-scale=1.0'>\
</head>",
  "<body>\
<form method='get' id='programControl' class='pure-form-stacked' action='api/start/program/1'>\
<fieldset>\
<legend>Run Program</legend>\
<select id='program-select' onchange=\"submitprogramform(this.options[this.selectedIndex].value)\">\
<option value='1'>A</option>\
<option value='2'>B</option>\
<option value='3'>C</option>\
</select>\
<button type=\"submit\" class='pure-button pure-button-primary'>Submit</button>"
};

void handleHomePage(AsyncWebServerRequest *request)
{
  request->send(LittleFS,"/index.html",String());
}

void handleRunZone(AsyncWebServerRequest *request)
{
  request->send(LittleFS,"/runzone.html",String());
}

void handleRunProgram(AsyncWebServerRequest *request)
{
  request->send(LittleFS,"/runprogram.html",String());
}