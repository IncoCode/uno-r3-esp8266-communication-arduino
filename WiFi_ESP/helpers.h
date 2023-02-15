#ifndef Helpers_h
#define Helpers_h

#include <Arduino.h>

struct Response {
  String op;
  char** argumets;
};

int countCharacter(String str, char c);
Response parseResponse(String s, char delimiter);

#endif