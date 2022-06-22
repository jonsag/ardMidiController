// POTENTIOMETERS
void potentiometers()
{

  for (int i = 0; i < NPots; i++)
  { // Loops through all the potentiometers

    potCState[i] = analogRead(potPin[i]); // reads the pins from arduino

    midiCState[i] = map(potCState[i], 0, 1023, 0, 127); // Maps the reading of the potCState to a value usable in midi

    potVar = abs(potCState[i] - potPState[i]); // Calculates the absolute value between the difference between the current and previous state of the pot

    if (potVar > varThreshold)
    {                      // Opens the gate if the potentiometer variation is greater than the threshold
      PTime[i] = millis(); // Stores the previous time
    }

    timer[i] = millis() - PTime[i]; // Resets the timer 11000 - 11000 = 0ms

    if (timer[i] < TIMEOUT)
    { // If the timer is less than the maximum allowed time it means that the potentiometer is still moving
      potMoving = true;
    }
    else
    {
      potMoving = false;
    }

    if (potMoving == true)
    { // If the potentiometer is still moving, send the change control
      if (midiPState[i] != midiCState[i])
      {

        // Sends  MIDI CC
        // Use if using with ATmega32U4 (micro, pro micro, leonardo...)
        controlChange(midiCh, cc + i, midiCState[i]); //  (channel, CC number,  CC value)
        MidiUSB.flush();

        potPState[i] = potCState[i]; // Stores the current reading of the potentiometer to compare with the next
        midiPState[i] = midiCState[i];
      }
    }
  }
}
