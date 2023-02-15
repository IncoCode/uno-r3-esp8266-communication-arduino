#include "WiFi_Service.h"
#include <ESP8266WebServer.h>
#include "ATMegaHandler.h"

char* ssid = "Home";
char* password = "21111827Derzhko";

WiFi_Service wifi;
ESP8266WebServer server(80);
ATMegaHandler handler;

const String html_page = "<!DOCTYPE html>"
                         "<html>"
                         "  <head>"
                         "    <meta name='viewport' content='width=device-width, initial-scale=1.0' />"
                         "  </head>"
                         "  <body>"
                         "    <a href='/led_state?state=1'>turn LED on</a>"
                         "    <a href='/led_state?state=0'>turn LED off</a>"
                         "  </body>"
                         "</html>";

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println('\n');

  connectToWiFi();
  setupWebServer();
}

void loop() {
  server.handleClient();
}

void setupWebServer() {
  server.on("/", []() {
    server.send(200, "text/html", html_page);
  });

  server.on("/led_state", []() {
    HTTPMethod method = server.method();
    switch (method) {
      case HTTP_GET:
        server.send(200, "text/plain", String(handler.getState()));
        break;

      case HTTP_POST:
        handler.setState(server.arg("state").equals("1"));
        server.send(200, "text/plain", "ok");
        break;

      default:
        server.send(404, "text/plain", "Not found");
        break;
    }
  });

  server.begin();
}

void connectToWiFi() {
  wifi.connect(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println(" ...");

  int i = 0;
  while (!wifi.isConnected()) {
    delay(1000);
    Serial.print(++i);
    Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(wifi.getLocalIP());
}
