#include "Transmitter.h"

Transmitter::Transmitter() {
    Serial.println("HERE1");
    // imu.begin();
    begin();
}

void Transmitter::begin() {
    transceiver.begin(1);
}

void Transmitter::send(String message){
    // transceiver.send(imu.readAll());
}