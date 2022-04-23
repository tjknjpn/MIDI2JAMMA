#include <MIDI.h>

const int HiHatPin = 8;
const int SnarePin = 9;
const int BassPin = 10;
const int HiTomPin = 11;
const int LowTomPin = 12;
const int CymbalPin = 13;

const int HiHatNum[] = {22,26,42,44,46};
const int SnareNum[] = {37,38,40};
const int BassNum[] = {35,36};
const int HiTomNum[] = {48,50};
const int LowTomNum[] = {41,43,45,47};
const int CymbalNum[] = {49,51,52,55,57,59};

const int Threshold = 10;

#define SIZE_OF_ARRAY(array)    (sizeof(array)/sizeof(array[0]))

MIDI_CREATE_DEFAULT_INSTANCE(); 

void setup()
{
    MIDI.begin(MIDI_CHANNEL_OMNI); //all channel
    pinMode(HiHatPin, OUTPUT);
    pinMode(SnarePin, OUTPUT);
    pinMode(BassPin, OUTPUT);
    pinMode(HiTomPin, OUTPUT);
    pinMode(LowTomPin, OUTPUT);
    pinMode(CymbalPin, OUTPUT);
}

void loop()
{
    if (MIDI.read())
    {
        switch(MIDI.getType())
        {
                //--------Note--------------------
                //MIDI.getData1(): get note number
                //MIDI.getData2(): get velocity
                //--------------------------------
                case midi::NoteOn:
                    if(MIDI.getData2() > Threshold){
                        int hitPin = padPinCheack(MIDI.getData1());
                        hitPad(hitPin);
                    }
                    break;

                default:
                    break;
        }
    } 
}

int padPinCheack(int NoteNum){
    //HH
    for (int index = 0; index < SIZE_OF_ARRAY(HiHatNum); index++) {
      if (NoteNum == HiHatNum[index]) {
        return HiHatPin;
      }
    }

    //SN
    for (int index = 0; index < SIZE_OF_ARRAY(SnareNum); index++) {
      if (NoteNum == SnareNum[index]) {
        return SnarePin;
      }
    }

    //BD
    for (int index = 0; index < SIZE_OF_ARRAY(BassNum); index++) {
      if (NoteNum == BassNum[index]) {
        return BassPin;
      }
    }

     //HT
    for (int index = 0; index < SIZE_OF_ARRAY(HiTomNum); index++) {
      if (NoteNum == HiTomNum[index]) {
        return HiTomPin;
      }
    }

    //LT
    for (int index = 0; index < SIZE_OF_ARRAY(LowTomNum); index++) {
      if (NoteNum == LowTomNum[index]) {
        return LowTomPin;
      }
    }

    //CY
    for (int index = 0; index < SIZE_OF_ARRAY(CymbalNum); index++) {
      if (NoteNum == CymbalNum[index]) {
        return CymbalPin;
      }
    }
    
    return 0;
}

void hitPad(int pin){
    digitalWrite(pin, HIGH);
    delay(15);
    digitalWrite(pin, LOW);
}
