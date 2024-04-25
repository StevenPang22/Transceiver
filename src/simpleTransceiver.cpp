#include "simpleTransceiver.h"

SimpleTranseiver::SimpleTranseiver() {
    txOrRx = 0;
}

void SimpleTranseiver::begin(int TxOrRx) {
    txOrRx = TxOrRx;
    Serial1.begin(115200);
    Serial.begin(115200);

    if (txOrRx == 1) {
        delay(5000);
        Serial1.print("AT+ADDRESS=2\r\n");
        delay(100);
        Serial1.print("AT+NETWORKID=3\r\n");
        delay(100);
        Serial1.print("AT+MODE=\r\n");
    }
    else if (txOrRx == 2) {
        delay(500);
        Serial1.print("AT+ADDRESS=2\r\n");
        delay(100);
        Serial1.print("AT+NETWORKID=3\r\n");
        delay(100);
    }
    else {
        Serial.println("Invalid argument. Please use 1 for RX and 2 for TX");
    }
}

void SimpleTranseiver::send(String message) {
    Serial1.print("AT+SEND=2,");
    Serial1.print(message);
    Serial1.print("\r\n");
}

String SimpleTranseiver::receive() {
    if (Serial1.available()) {
        return Serial1.readString();
    }
    return "";
}

void SimpleTranseiver::run() {
    if (txOrRx == 1) {
        send("Hello");
    }
    else if (txOrRx == 2) {
        Serial.println(receive());
    }
}