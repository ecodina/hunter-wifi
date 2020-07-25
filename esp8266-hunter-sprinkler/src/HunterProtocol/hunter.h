#include <vector>

#include <Arduino.h>

using namespace std;

// This makes inverting the signal easy
#define HUNTER_ONE HIGH
#define HUNTER_ZERO LOW

#define START_INTERVAL 900
#define SHORT_INTERVAL 208
#define LONG_INTERVAL 1875

#define HUNTER_PIN 16 // D0
//#define ENABLE_PIN 14 // D7 - not used
//#define LED_PIN 2 // LED on D1 mini

void HunterStop(byte zone);
void HunterStart(byte zone, byte time);
void HunterProgram(byte num);
void HunterBitfield(vector <byte>& bits, byte pos, byte val, byte len);
void HunterWrite(vector<byte> buffer, bool extrabit);
void HunterLow(void);
void HunterHigh(void);
