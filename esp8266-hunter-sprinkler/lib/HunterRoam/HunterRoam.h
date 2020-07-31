#pragma once

#ifndef HunterRoam_h
#define HunterRoam_h

#include <vector>
#include <Arduino.h>

#define START_INTERVAL 900
#define SHORT_INTERVAL 208
#define LONG_INTERVAL 1875

#define HUNTER_PIN 16 // D0

class HunterRoam {
    public:
        HunterRoam(int pin);
        byte stopZone(byte zone);
        byte startZone(byte zone, byte time);
        byte startProgram(byte num);
        String errorHint(byte error);
    
    private:
        int _pin;
        void hunterBitfield(std::vector <byte> &bits, byte pos, byte val, byte len);
        void writeBus(std::vector<byte> buffer, bool extrabit);
        void sendLow(void);
        void sendHigh(void);
};

#endif
