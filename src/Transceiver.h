#ifndef TRANSCEIVER_H
#define TRANSCEIVER_H

#define MOSI_ 11
#define MISO_ 12
#define SCK_ 13
#define CE 9
#define CSN 10

#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>


class Transceiver {
    public:
        Transceiver();
        void begin(int recieverOrTransmitter); //0 - receiver, 1 - transmitter
        void send(String message);
        String receive();
    private:
        RF24 radio;
        const byte tAddress[6] = "00001";
        const byte rAddress[6] = "00001";
        int receiverOrTransmitter; //0 - receiver, 1 - transmitter
};


#endif