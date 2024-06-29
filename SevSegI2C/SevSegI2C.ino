#include "SevSeg.h"
#include <Wire.h>
#include "Nicla_System.h"

SevSeg sevseg;
int x = 0;

void setup(){
    nicla::begin();
    nicla::leds.begin();
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {8, 6, 10,11,0, 7, 9, 5};
    //                    A- B- C  D  E  F- G- DP
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
    Serial.begin(9600);
    // Start the I2C Bus as Slave on address 9
    Wire.begin(96); 
    // Attach a function to trigger when something is received.
    Wire.onReceive(receiveEvent);
    // Serial.println("Slave!");  
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
  Serial.print("Nicla Received: ");
  Serial.println(x);
  sevseg.setNumber(x, x%2);
  sevseg.refreshDisplay(); 
}

void loop(){
    for(int i = 0; i < 10; i++){
        if (i%2 == 0) {
          nicla::leds.setColor(green);
        } else {
          nicla::leds.setColor(red);
        }
        delay(1000);
      }       
}