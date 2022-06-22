#include <Arduino.h>

/*
  Based on Sketch built by Gustavo Silveira (aka Music Nerd)
  Modified by Dolce Wang

  This code is only for Arduinos that use ATmega32u4 (like Micro, Pro Micro, Leonardo...)
  Remember to also assign the correct board in the IDE (like Tools / Boards / Sparkfun AVR / Pro Micro...)

*/

// Change any fields with //**

#include <config.h>
#include <modules.h>
#include <buttons.h>
#include <potentiometers.h>

// SETUP
void setup()
{

  // Baud Rate
  // 31250 for MIDI class compliant | 115200 for Hairless MIDI

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
