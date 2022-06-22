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

                    // Sends the MIDI note ON accordingly to the chosen board

                    MIDI.sendNoteOn(note + i, 127, midiCh); // note, velocity, channel
                }
                else
                {

                    // Sends the MIDI note OFF accordingly to the chosen board

                    MIDI.sendNoteOn(note + i, 0, midiCh); // note, velocity, channel
                }
                buttonPState[i] = buttonCState[i];
            }
        }
    }
}
