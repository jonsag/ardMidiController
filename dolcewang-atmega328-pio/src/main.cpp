#include <Arduino.h>

/*
  Based on Sketch built by Gustavo Silveira (aka Music Nerd)
  Modified by Dolce Wang

  This code is only for Arduinos that use ATmega328 (like Uno, Mega, Nano, Beetle...)

*/

// Change values with //***

#include <config.h>
#include <buttons.h>
#include <potentiometers.h>

// SETUP
void setup()
{

  Serial.begin(115200); //**  Baud Rate 31250 for MIDI class compliant jack | 115200 for Hairless MIDI

  // Buttons
  // Initialize buttons with pull up resistors
  for (int i = 0; i < NButtons; i++)
  {
    pinMode(buttonPin[i], INPUT_PULLUP);
  }
}

// LOOP
void loop()
{

  buttons();
  potentiometers();
}
