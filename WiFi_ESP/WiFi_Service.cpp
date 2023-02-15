#include "WiFi_Service.h"
#include <ESP8266WiFi.h>

WiFi_Service::WiFi_Service() {
}

void WiFi_Service::connect(char* ssid, char* password) {
  WiFi.begin(ssid, password);
}

void WiFi_Service::disconnect() {
  WiFi.disconnect();
}

bool WiFi_Service::isConnected() {
  return WiFi.status() == WL_CONNECTED;
}

IPAddress WiFi_Service::getLocalIP() {
  return WiFi.localIP();
}