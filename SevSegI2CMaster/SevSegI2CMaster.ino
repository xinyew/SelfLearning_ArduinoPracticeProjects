// Chapter 7 - Communications
// I2C Master
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C
#include <Wire.h>
#include "Nicla_System.h"


// // Define custom color values for red, green, and blue components
// int red = 234;
// int green = 72;
// int blue = 122;

int x = 0;

void setup() {
  // Start the I2C Bus as Master
  nicla::begin();
  nicla::leds.begin();
  Wire.begin(); 
  Serial.begin(115200);
  Serial.println("Master!");

}

void loop() {
  Wire.beginTransmission(96); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  Serial.print("Sending: ");
  Serial.println(x);
 
  x++; // Increment x
  if (x > 9) x = 0; // `reset x once it gets 6

  // Set the LED to the custom color, wait for 1000 milliseconds
  nicla::leds.setColor(red);
  delay(500);

  // Turn off the LED and wait, wait for 1000 milliseconds
  nicla::leds.setColor(off);
  delay(500);
}

