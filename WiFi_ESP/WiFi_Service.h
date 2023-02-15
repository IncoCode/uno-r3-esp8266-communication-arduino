#ifndef WiFi_Service_h
#define WiFi_Service_h

#include <Arduino.h>
#include <ESP8266WiFi.h>

class WiFi_Service {
private:

public:
  WiFi_Service();
  void connect(char* ssid, char* password);
  void disconnect();
  bool isConnected();
  IPAddress getLocalIP();
};

#endif