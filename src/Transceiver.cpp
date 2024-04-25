#include "Transceiver.h"

Transceiver::Transceiver() {
}

void Transceiver::begin(int recieverOrTransmitter) {
    radio.begin(9, 10);
    this->receiverOrTransmitter = recieverOrTransmitter;
    if (recieverOrTransmitter == 0) { //receiver
        radio.begin();
        radio.openReadingPipe(0, rAddress);
        radio.setPALevel(RF24_PA_MAX);
        radio.startListening();
    } else { //transmitter
        radio.begin();
        radio.openWritingPipe(tAddress);
        radio.setPALevel(RF24_PA_MAX);
        radio.stopListening();
    }
}

void Transceiver::send(String message) {
    const char text[] = "Hello World";
    radio.write(&text, sizeof(text));
}

String Transceiver::receive() {
    char text[32] = "";
    if (radio.available()) {
        radio.read(&text, sizeof(text));
    }
    return String(text);
}