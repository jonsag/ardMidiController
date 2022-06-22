// BUTTONS
void buttons()
{

  for (int i = 0; i < NButtons; i++)
  {

    buttonCState[i] = digitalRead(buttonPin[i]); // read pins from arduino

    if ((millis() - lastDebounceTime[i]) > debounceDelay)
    {

      if (buttonPState[i] != buttonCState[i])
      {
        lastDebounceTime[i] = millis();

        if (buttonCState[i] == LOW)
        {

          // Sends the MIDI note ON

          // use if using with ATmega32U4 (micro, pro micro, leonardo...)
          noteOn(midiCh, note + i, 127); // channel, note, velocity
          MidiUSB.flush();
        }
        else
        {

          // Sends the MIDI note OFF accordingly to the chosen board

          // use if using with ATmega32U4 (micro, pro micro, leonardo...)
          noteOn(midiCh, note + i, 0); // channel, note, velocity
          MidiUSB.flush();
        }
        buttonPState[i] = buttonCState[i];
      }
    }
  }
}
