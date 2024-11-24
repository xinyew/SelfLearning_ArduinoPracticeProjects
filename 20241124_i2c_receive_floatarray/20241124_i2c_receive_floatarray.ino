// Written by Nick Gammon
// May 2012

#include <Wire.h>
#include "data.h"
#include "I2C_Anything.h"

const byte MY_ADDRESS = 42;
int LENGTH = 500;

void setup() {
  Wire.begin(MY_ADDRESS);
  Serial.begin(115200);
  Wire.onReceive(receiveEvent);
}  // end of setup

volatile int i;

void loop() {
  if (i != -1 && i == (LENGTH - 1)) {
    for (int i = 0; i < LENGTH; i++) {
      Serial.printf("data[%3d]: %.10f\n", i, data[i]);
    }
    i = 0;
  }
}  // end of loop

// called by interrupt service routine when incoming data arrives
void receiveEvent(int howMany) {
  if (howMany >= (sizeof i) + (sizeof data[0])) {
    I2C_readAnything(i);
    if (i == -1) {
      double tmp;
      I2C_readAnything(tmp);
      LENGTH = (int)tmp;
      Serial.println(LENGTH);
    } else {
      I2C_readAnything(data[i]);
    }
  }
}