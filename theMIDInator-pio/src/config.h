
// KEYPAD //

#include <Keypad.h>

#define ROWS 4 // four rows
#define COLS 3
// three columns
char keys[ROWS][COLS] = { // keypad keys, 1-9, 0, S for star (asterisk) and P for pound (square)
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'S', '0', 'P'}};

byte rowPins[ROWS] = {43, 41, 39, 35}; // keypad row pinouts
byte colPins[COLS] = {33, 31, 37};     // keypad column pinouts

/*
From example:
Keypad Pin 3    Arduino digital 2
Keypad Pin 1    Arduino digital 3
Keypad Pin 5    Arduino digital 4

Keypad Pin 2    Arduino digital 5
Keypad Pin 7    Arduino digital 6
Keypad Pin 4    Arduino digital 7
Keypad Pin 4    Arduino digital 8

byte rowPins[ROWS] = {5, 6, 7, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 4}; //connect to the column pinouts of the keypad
*/

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int midC = 60; // MIDI note value for middle C on a standard keyboard

#define transposePin1 22 // pins for the switch controlling transposing
#define transposePin2 23

int transpose = 0; // if = 0 no transposing
int transposeLeft = 0;
int transposeRight = 0;
int oldTransposeLeft = 0;
int oldTransposeRight = 0;
unsigned long transposeTimer = 0; // for debouncing

// ROTARY ENCODER //

#define ENCODER_DO_NOT_USE_INTERRUPTS
#include <Encoder.h>

Encoder myEnc1(26, 27);
Encoder myEnc2(24, 25);
long position1 = -999;
long position2 = -999;
int encVals[12] = {64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64}; // set initial value of encoder to mid range of 0-127

// ROTARY SWITCH //

#define rotSwitch1 30 // rotary switch pins
#define rotSwitch2 32
#define rotSwitch3 34
#define rotSwitch4 36
#define rotSwitch5 38
#define rotSwitch6 40

int cVal = 1;

// POTENTIOMETERS //

#define pot1 A0 // potentiometer pins
#define pot2 A1
#define pot3 A2
#define slidePot A3

int potVal1 = 0;
int potVal2 = 0;
int potVal3 = 0;
int slidePotVal = 0;

int lastPotVal1 = 0;
int lastPotVal2 = 0;
int lastPotVal3 = 0;
int lastSlidePotVal = 0;

// JOYSTICK //

#define joyX A5 // joystick pins
#define joyY A4

#define Xswitch 52 // axis switch pins
#define Yswitch 50

int joyXval = 0;
int joyYval = 0;
int lastJoyXval = 0;
int lastJoyYval = 0;
