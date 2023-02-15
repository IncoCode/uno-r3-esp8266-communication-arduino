#ifndef ATMegaHandler_h
#define ATMegaHandler_h

#include <Arduino.h>

#define GET_STATE_COMMAND "GET_STATE\r\n"
#define SET_STATE_COMMAND "SET_STATE;%d;\r\n"
#define STATE_RESPONSE "STATE"

class ATMegaHandler {
private:

public:
  ATMegaHandler();

  void setState(bool state);
  bool getState();
};

#endif