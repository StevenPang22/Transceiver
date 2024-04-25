#ifndef SIMPLE_TRANSCEIVER_H
#define SIMPLE_TRANSCEIVER_H

#include <Arduino.h>

class SimpleTranseiver {
    public:
        SimpleTranseiver();
        void begin(int TxOrRx); // 1 = RX, 2 = TX
        int txOrRx;
        void send(String message);
        String receive();
        void run();
};

#endif