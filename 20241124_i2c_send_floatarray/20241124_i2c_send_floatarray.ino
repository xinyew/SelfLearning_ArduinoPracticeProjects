// Written by Nick Gammon
// May 2012

#include <Wire.h>
#include "data.h"
#include "I2C_Anything.h"

const byte SLAVE_ADDRESS = 42;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}  // end of setup

void loop() {
  if (Serial.available() > 0) {    // Check if data is available to read
    char command = Serial.read();  // Read the incoming byte
    if (command == '\n' || command == '\r') {
      return;  // Do nothing for these characters
    }
    // Serial.println(Serial.available());
    if (command == 's') {  // Check if the command is 's'
      send();              // Call your function
    } else {
      Serial.println("Unknown command. Try 's'.");
    }
  }
}  // end of loop

void send() {
  Wire.beginTransmission(SLAVE_ADDRESS);
  I2C_writeAnything(-1);
  I2C_writeAnything((double)(sizeof(data) / sizeof(data[0])));
  Wire.endTransmission();

  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {

    Wire.beginTransmission(SLAVE_ADDRESS);
    I2C_writeAnything(i);
    I2C_writeAnything(data[i]);
    Wire.endTransmission();

  }
}