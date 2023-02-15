#include "ATMegaHandler.h"
#include "helpers.h"

ATMegaHandler::ATMegaHandler() {}

bool ATMegaHandler::getState() {
  Serial.write(GET_STATE_COMMAND);

  String str;
  Response r;
  do {
    delay(10);
    str = Serial.readStringUntil('\r');
    r = parseResponse(str, ';');
  } while (!Serial.available() || r.op != STATE_RESPONSE);

  return strcmp(r.argumets[0], "1") == 0;
}

void ATMegaHandler::setState(bool state) {
  char buffer[sizeof(SET_STATE_COMMAND)];
  sprintf(buffer, SET_STATE_COMMAND, state ? 1 : 0);
  Serial.write(buffer);
}