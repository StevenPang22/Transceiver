#include <Arduino.h>
#include "IMU.h"
#include <SPI.h>

IMU::IMU() {
    gyroPitch = 0;
    gyroRoll = 0;
    gyroYaw = 0;
    pinMode(CS1, OUTPUT);
}

void IMU::begin() {
    // Initialize the IMU
    pinMode(CS1, OUTPUT);
    pinMode(MISO, INPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);

    SPI1.setCS(CS1);
    SPI1.setMISO(MISO1);
    SPI1.setMOSI(MOSI1);
    SPI1.setSCK(SCK1);
    delay(20);

    SPI1.begin();
    SPI1.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE3));
    digitalWrite(CS1, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    Serial.begin(9600);

    delay(500);

    Serial.println("HERE");
    int integ = sendSPI(1, 0x0F, 0);
    Serial.println(integ, BIN);

    //to send: 01110100
    Serial.println("Sending ");
    sendSPI(0, 0x11, 116);
    Serial.println("Sent ");
    delay(100);



}

int IMU::twosComplement(int i){
  if (i > 32767){
    i = i - 65536;
  }
  return i;
}

u_int16_t IMU::sendSPI(int readWrite, u_int16_t address, u_int16_t data) {
  digitalWrite(10, LOW);
  u_int16_t bit = readWrite << 15;
  bit += (address << 8);
  bit += data;
  u_int16_t i = SPI1.transfer16(bit);
  digitalWrite(10, HIGH);
  return i;
}

u_int16_t IMU::read(u_int8_t address) {
  u_int16_t i = sendSPI(1, address, 0);
  return i;
}

double IMU::readPitch(){
  u_int8_t low = read(0x22);
  u_int8_t high = read(0x23);
  int i = (high << 8) + low;
  i = twosComplement(i);
  double x = i / 200.0;
  gyroPitch = x;
  return x;
}

double IMU::readRoll(){
  u_int8_t low = read(0x24);
  u_int8_t high = read(0x25);
  int i = (high << 8) + low;
  i = twosComplement(i);
  double x = i / 200.0;
  gyroRoll = x;
  return x;
}

double IMU::readYaw(){
  u_int8_t low = read(0x26);
  u_int8_t high = read(0x27);
  int i = (high << 8) + low;
  i = twosComplement(i);
  double x = i / 200.0;
  gyroYaw = x;
  return x;
}

String IMU::readAll(){
  String s = "";
  s += String(readRoll()) + ",";
  s += String(readPitch()) + ",";
  s += String(readYaw());
  return s;
}
