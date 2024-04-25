#include <Arduino.h>
#include "simpleTransceiver.h"


// Transmitter transmitter;
// Receiver receiver;
// 
SimpleTranseiver receiver;
// SimpleTranseiver transmitter;

void setup() {
  // transmitter.begin(2);
  receiver.begin(1);
  
}

void loop() {
  // transmitter.run();
  receiver.run();
  delay(1);
}
