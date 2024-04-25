#ifndef RECEIVER_H
#define RECEIVER_H

#include "Transceiver.h"
#include "IMU.h"

class Receiver : public Transceiver {
    public:
        Receiver();
        void begin();
        String receive();
    private:
        Transceiver* transceiver;
};

#endif