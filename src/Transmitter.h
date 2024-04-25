#ifndef TRANSMITER_H
#define TRANSMITTER_H

#include "Transceiver.h"
// #include "IMU.h"

class Transmitter : public Transceiver {
    public:
        Transmitter();
        void begin();
        void send(String message);
    private:
        Transceiver transceiver;
        // IMU imu;
};

#endif