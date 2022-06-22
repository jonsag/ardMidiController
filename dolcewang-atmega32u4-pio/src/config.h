// LIBRARY
#include "MIDIUSB.h"

// BUTTONS
const int NButtons = 4;                       //***  total number of buttons
const int buttonPin[NButtons] = {2, 3, 5, 7}; //*** define Digital Pins connected from Buttons to Arduino; (ie {10, 16, 14, 15, 6, 7, 8, 9, 2, 3, 4, 5}; 12 buttons)

int buttonCState[NButtons] = {}; // stores the button current value
int buttonPState[NButtons] = {}; // stores the button previous value

// debounce
unsigned long lastDebounceTime[NButtons] = {0}; // the last time the output pin was toggled
unsigned long debounceDelay = 50;               //** the debounce time; increase if the output flickers

// POTENTIOMETERS
const int NPots = 8;                                        //*** total number of pots (knobs and faders)
const int potPin[NPots] = {A9, A8, A7, A6, A3, A2, A1, A0}; //*** define Analog Pins connected from Pots to Arduino; Leave nothing in the array if 0 pots {}
int potCState[NPots] = {0};                                 // Current state of the pot; delete 0 if 0 pots
int potPState[NPots] = {0};                                 // Previous state of the pot; delete 0 if 0 pots
int potVar = 0;                                             // Difference between the current and previous state of the pot

int midiCState[NPots] = {0}; // Current state of the midi value; delete 0 if 0 pots
int midiPState[NPots] = {0}; // Previous state of the midi value; delete 0 if 0 pots

const int TIMEOUT = 300;          //* Amount of time the potentiometer will be read after it exceeds the varThreshold
const int varThreshold = 10;      //* Threshold for the potentiometer signal variation
boolean potMoving = true;         // If the potentiometer is moving
unsigned long PTime[NPots] = {0}; // Previously stored time; delete 0 if 0 pots
unsigned long timer[NPots] = {0}; // Stores the time that has elapsed since the timer was reset; delete 0 if 0 pots

// MIDI Assignments
byte midiCh = 1; //* MIDI channel to be used
byte note = 36;  //* Lowest note to be used; 36 = C2; 60 = Middle C
byte cc = 1;     //* Lowest MIDI CC to be used
