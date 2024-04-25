#ifndef IMU_H
#define IMU_H

#define MOSI1 26
#define MISO1 1
#define SCK1 27
#define CS1 38

#include <Arduino.h>

class IMU {
    public:
        IMU(); //uses SPI1
        void begin();
        u_int16_t read(u_int8_t address);
        double readPitch();
        double readRoll();
        double readYaw();
        double gyroPitch;
        double gyroRoll;
        double gyroYaw;
        uint16_t sendSPI(int readWrite, uint16_t address, uint16_t value);
        String readAll();

    private:
        int twosComplement(int value);

};

#endif