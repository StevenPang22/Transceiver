#include "Receiver.h"

Receiver::Receiver() {
    begin();
    transceiver = new Transceiver();
}

void Receiver::begin() {
    transceiver->begin(0);
}

String Receiver::receive() {
    return transceiver->receive();
}