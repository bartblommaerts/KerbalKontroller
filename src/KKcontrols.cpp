/*
    KKcontrols.cpp - Library for the modular Kerbal Kontroller (https://www.thingiverse.com/thing:2784716).

*/

#include <Wire.h>
#include <Shifty.h>

const int testTIMER = 20000;
const int MAXBARS = 10;


  void Button::setState(bool newState){
    _state = newState;
    setLED(_state);
  }

  bool Button::getState(){
    return _state;
  }

  void Button::setPinButton(byte newPin){
    _pinButton = newPin;
    pinMode(_pinButton,INPUT);
  }

  byte Button::getPinButton(){
    return _pinButton;
  }

  void Button::setPinLED(byte newPin){
    _pinLED = newPin;
    pinMode(_pinLED,OUTPUT);
    digitalWrite(_pinLED,LOW);
  }

  byte Button::getPinLED(){
    return _pinLED;
  }

  void Button::setLED(byte newState){
    _LEDstate = newState;
    digitalWrite(_pinLED,newState);
  }

  byte Button::getLED(){
    return _LEDstate;
  }

  void Button::testLED(){
    digitalWrite(_pinLED,HIGH);
    delay(testTIMER);
    digitalWrite(_pinLED,LOW);

  }

  void Button::flip(){
    setState(!_state);
    setLED(!_LEDstate);
  }

  void Button::run(){
    byte oldState = _state;
    _state = digitalRead(pinButton);
    if (_state != oldState){
      setState(state);
    }
  }

  Button::Button(byte pBtn, byte pLED){
    setPinButton(pBtn);
    setPinLED(pLED);
  }

void Slider::setState(int newState){
    _state = newState;
   }

int Slider::getState(){
    return _state;
   }

void Slider::setPinSlider(byte newPin){
    _pinSlider = newPin;
    pinMode(_pinSlider,INPUT);
   }

byte Slider::getPinSlider(){
    return _pinSlider;
   }

Slider::Slider(byte newPin){
    setPinSlider(newPin);
   }

void Slider::run(){
    int oldState = _state;
    state = analogRead(_pinSlider);
    if (_state != oldState){
      setState(_state);
    }
   }

void Joystick::setPinX(byte newPin){
     _pinX = newPin;
     pinMode(_pinX,INPUT);
   }

byte Joystick::getPinX(){
     return _pinX;
   }

void Joystick::setPinY(byte newPin){
     _pinY = newPin;
     pinMode(_pinY,INPUT);
   }

byte Joystick::getPinY(){
     return _pinY;
   }

void Joystick::setPinZ(byte newPin){
     _pinZ = newPin;
     pinMode(_pinZ,INPUT);
   }

byte Joystick::getPinZ(){
     return _pinZ;
   }

void Joystick::setPinBtn(byte newPin){
     _pinButton = newPin;
     pinMode(_pinButton,INPUT);
   }

byte Joystick::getPinBtn(){
     return _pinButton;
   }

void Joystick::setStateX(int newState){
     _stateX = newState;
   }

int Joystick::getStateX(){
     return _stateX;
   }

void Joystick::setStateY(int newState){
     _stateY = newState;
   }

int Joystick::getStateY(){
     return _stateY;
   }

void Joystick::setStateZ(int newState){
     _stateZ = newState;
   }

int Joystick::getStateZ(){
     return _stateZ;
   }

void Joystick::setStateBtn(byte newState){
     _stateBtn = newState;
   }

byte Joystick::getStateBtn(){
     return _stateBtn;
   }

void Joystick::Joystick(byte newPinX,byte newPinY,byte newPinZ,byte newPinBtn){
     setPinX(newPinX);
     setPinY(newPinY);
     setPinZ(newPinZ);
     setPinBtn(newPinBtn);
   }

void Joystick::run(){
     int oldState = _stateX;
     int newState = analogRead(_pinX);
     if(newState != oldState){
       setStateX(newState);
     }
     oldState = _stateY;
     newState = analogRead(_pinY);
     if(newState != oldState){
       setStateY(newState);
     }
     oldState = _stateZ;
     newState = analogRead(_pinZ);
     if(newState != oldState){
       setStateZ(newState);
     }
     oldState = stateBtn;
     newState = _stateBtn = analogRead(_pinButton);
     if(newState != oldState){
       setStateBtn(newState);
     }
   }

void Bargraphs::setPinCLK(byte newPin){
     _pinCLK = newPin;
   }
byte Bargraphs::getPinCLK(){
     return _pinCLK;
   }
void Bargraphs::setPinDAT(byte newPin){
     _pinDAT = newPin;
   }
byte Bargraphs::getPinDAT(){
     return _pinDAT;
   }
void Bargraphs::setPinLAT(byte newPin){
     _pinLAT = newPin;
   }
byte Bargraphs::getPinLat(){
     return _pinLAT;
   }
void Bargraphs::setNrBars(int newNr){
     _nrBars = newNr;
   }
int Bargraphs::getNrBars(){
     return _nrBars;
   }
void Bargraphs::setNrLEDs(int newNr){
     _nrLEDs = newNr;
   }
int Bargraphs::getNrLEDs(){
     return _nrLEDs;
   }
void Bargraphs::setCtrlChipSize(int newSize){
     _ctrlChipSize = newSize;
   }
int Bargraphs::getCtrlChipSize(){
     return _ctrlChipSize;
   }
void Bargraphs::setBarValue(int barNr, int newValue){
     _baseBars[barNr] = newValue;
   }
int Bargraphs::getBarValue(int barNr){
     return _baseBars[barNr];
   }

Bargraphs::Bargraphs(int newNr, int newLEDs, int newSize, int newCLK, int newDAT, int newLAT){
     setNrBars(newNr);
     setNrLEDs(newLEDs);
     setCtrlChipSize(newSize);
     setPinCLK(newCLK);
     setPinDAT(newDAT);
     setPinLAT(newLAT);
     _baseBars.setBitCount(newLEDs);
     _baseBars.setPins(newDAT,newCLK,newLAT);
     _barSize = _nrLEDs/_nrBars;
   }

void Bargraphs::run(){
     for (int i = 0; i<_nrBars; i++){
       int result = map(_baseBars[i],0,0,1000,10);
       int j;
       for (j = 0; j <= result;j++){
         _baseBars.writeBit((i*10)+j,HIGH);
       }
       for ( j; j <= _barSize; j++){
         baseBars.writeBit((i*10)+j,LOW);
       }
     }
   }
