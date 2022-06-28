#include <web_interface.h>

WebInterface interface =
{
  "<head>\
    <script type=\"text/javascript\">\
      function submitform() {\
        document.getElementById(\"zoneControl\").action = \"api/start/zone/\"+document.getElementById(\"zone\").value+\"?time=\"+document.getElementById(\"time\").value;\
        return true;\
      }\
    </script>\
    <link rel=\"stylesheet\" href=\"https://unpkg.com/purecss@2.1.0/build/pure-min.css\" integrity=\"sha384-yHIFVG6ClnONEA5yB5DJXfW2/KC173DIQrYoZMEtBvGzmf0PKiGyNEqe9N6BNDBH\" crossorigin=\"anonymous\">\
  </head>",
  "<body> \
    <form method=\"get\" id=\"zoneControl\" class='pure-form-stacked'>\
    <fieldset>\
    <legend>Run Single Zone</legend>\
    <input type=\"text\" id=\"zone\" onchange=\"submitform()\"/ placeholder='Zone'><br/>\
    <input type=\"text\" id=\"time\" onchange=\"submitform()\" placeholder='Run Time'>\
    <button type=\"submit\" class='pure-button pure-button-primary'>Submit</button>\
    </fieldset>\
    </form>\
  </body>",
  ""
};

// currently at /control
void handleWebInterface(AsyncWebServerRequest *request)
{
  String html = "<p>Nifty Web Interface will be finished Tomorrow</p>";
  request->send(200, "text/html", interface.header + interface.body + interface.footer);
}