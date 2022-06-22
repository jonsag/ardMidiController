// LIBRARIES
#include <MIDI.h> // by Francois Best
MIDI_CREATE_DEFAULT_INSTANCE();

// BUTTONS
const int NButtons = 4;                       //***  total number of push buttons
const int buttonPin[NButtons] = {2, 3, 5, 7}; //*** define digital pins connected from button to Arduino; (ie {10, 16, 14, 15, 6, 7, 8, 9, 2, 3, 4, 5}; 12 buttons)
                                              //** Button NOTE will go up chromatically.  ie. if button is digi pin 2, C; Pin 3, C#; Pin 3, D; etc

int buttonCState[NButtons] = {}; // stores the button current value
int buttonPState[NButtons] = {}; // stores the button previous value

// debounce
unsigned long lastDebounceTime[NButtons] = {0}; // the last time the output pin was toggled
unsigned long debounceDelay = 50;               //* the debounce time; increase if the output flickers

// POTENTIOMETERS
const int NPots = 6;                                //*** total numbers of pots (slide & rotary)
const int potPin[NPots] = {A5, A4, A3, A2, A1, A0}; //*** Analog pins of each pot connected straight to the Arduino i.e 4 pots, {A3, A2, A1, A0};
                                                    // have nothing in the array if 0 pots {}

int potCState[NPots] = {0}; // Current state of the pot; delete 0 if 0 pots
int potPState[NPots] = {0}; // Previous state of the pot; delete 0 if 0 pots
int potVar = 0;             // Difference between the current and previous state of the pot

int midiCState[NPots] = {0}; // Current state of the midi value; delete 0 if 0 pots
int midiPState[NPots] = {0}; // Previous state of the midi value; delete 0 if 0 pots

const int TIMEOUT = 300;          //** Amount of time the potentiometer will be read after it exceeds the varThreshold
const int varThreshold = 10;      //** Threshold for the potentiometer signal variation
boolean potMoving = true;         // If the potentiometer is moving
unsigned long PTime[NPots] = {0}; // Previously stored time; delete 0 if 0 pots
unsigned long timer[NPots] = {0}; // Stores the time that has elapsed since the timer was reset; delete 0 if 0 pots

// MIDI
byte midiCh = 1; //** MIDI channel to be used; You can add more if you need to reorganize or have a billion buttons/pots
byte note = 36;  //** First note to be used for digital buttons, then go up chromatically in scale according to the sequence in your "buttonPin" array
                 // you can look up on a Midi Note chart; 36=C2; 60=Middle C
byte cc = 1;     //** First MIDI CC to be used for pots on Analog Pins in order of the "potPin" array; then goes up by 1
