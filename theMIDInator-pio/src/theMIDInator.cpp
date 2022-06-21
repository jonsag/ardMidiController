#include <Arduino.h>

// THE MIDINATOR //

// Author: Daniel Jansson // Switch & Lever // switchandlever.com

// This code is a companion to the YouTube video on how to build a MIDI controller (called
// The MIDInator) linked below:

// https://youtu.be/JZ5yPdoPooU

// The MIDInator uses an Arduino MEGA 2560, connected to a keypad, a few potentiometers, rotary
// encoders, switches and a joystick to send MIDI messages over USB serial to a Serial to
// MIDI bridge software running on the computer.

// COMPONENT LIST

// 1x   Arduino MEGA 2560
// 3x   10kOhm (B10K) linear rotary potentiometer
// 1x   10kOhm (B10K) linear slide potentiometer
// 1x   ALPS 6 position rotary switch (SRBM160700)
// 2x   ALPHA 12 step rotary encoder (RE130F-41-175F-12P)
// 1x   phone keypad from old Ericsson Diavox
// 2x   generic slide toggle switches
// 1x   generic (ON)-OFF-(ON) toggle switch
// 1x   remote control joystick (2 potentiometers)

// The libraries used in this sketch can be found at:

// Keypad.h :: https://github.com/Chris--A/Keypad
// Encoder.h :: https://github.com/PaulStoffregen/Encoder

// Please refer to the documentation for the individual libraries on their respective
// operation and function.

// This code is licensed under a GNU General Public License and may be freely modified
// and redistributed under the same license terms.
// https://www.gnu.org/licenses/gpl-3.0.en.html

#include <config.h>

#include <MIDImessage.h>
#include <readEncoder.h>
#include <readJoystick.h>
#include <readKeyPad.h>
#include <readPots.h>
#include <readRotSwitch.h>

void setup()
{

  Serial.begin(9600); // enable serial communication

  pinMode(transposePin1, INPUT_PULLUP); // activate the input pullup resistor on all buttons/switches
  pinMode(transposePin2, INPUT_PULLUP); // means you won't need external resistors to read the buttons
  pinMode(rotSwitch1, INPUT_PULLUP);
  pinMode(rotSwitch2, INPUT_PULLUP);
  pinMode(rotSwitch3, INPUT_PULLUP);
  pinMode(rotSwitch4, INPUT_PULLUP);
  pinMode(rotSwitch5, INPUT_PULLUP);
  pinMode(rotSwitch6, INPUT_PULLUP);
  pinMode(Xswitch, INPUT_PULLUP);
  pinMode(Yswitch, INPUT_PULLUP);
}

void loop()
{

  readRotSwitch(); // read rotary switch
  readEncoder();   // read rotary encoder
  readKeyPad();    // read keypad + transpose switch
  readPots();      // read potentiometers
  readJoystick();  // read joystick + on/off switches
}
