#include "HardwareSerial.h"
#include "WString.h"
#include "Arduino.h"

#include "helpers.h"

int countCharacter(String str, char c) {
  int count = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str.charAt(i) == c) {
      count++;
    }
  }

  return count;
}

Response parseResponse(String s, char delimiter) {
  int arraySize = countCharacter(s, delimiter);

  char** p = new char*[arraySize];
  int arrIndex = 0;

  int firstDelimiterIndex = s.indexOf(delimiter);
  String operation = s.substring(0, firstDelimiterIndex);
  bool isNoArguments = arraySize == 1;
  if (isNoArguments) {
    return { operation, NULL };
  }

  String argsStr = String(s.substring((firstDelimiterIndex + 1)));
  do {
    int delimiterIndex = argsStr.indexOf(delimiter);
    if (delimiterIndex < 0) break;

    String arg = argsStr.substring(0, delimiterIndex);

    p[arrIndex] = new char[arg.length() + 1];
    arg.toCharArray(p[arrIndex], arg.length() + 1);

    argsStr = argsStr.substring(delimiterIndex + 1);
    arrIndex++;
  } while (argsStr.indexOf(delimiter) > -1);

  return { operation, p };
}