/*
    KKcontrols.h - Library for the modular Kerbal Kontroller (https://www.thingiverse.com/thing:2784716).

*/

#ifndef KKcontrols_h
#define KKcontrols_h

#include <Wire.h>
#include <Shifty.h>

class Button{
    public:
    Button(byte pBtn, byte pLED);
    void setState(byte newState);
    byte getState();
    void setPinButton(byte newPin);
    byte getPinButton();
    void setPinLed(byte newPin);
    byte getPinLed();
    void setLED(byte newState);
    byte getLED();
    void testLED();
    void flip();
    void run();

    private:
    byte _state;
    byte _LEDstate;
    byte _pinButton;
    byte _pinLED;
};

class Slider{
private:
  int _state;
  byte _pinSlider;

public:
  Slider(byte newPin);
  void setState(int newState);
  int getState();
  void setPinSlider(byte newPin);
  byte getPinSlider();
  void run();
};

class Joystick{
private:
  byte _pinX;
  byte _pinY;
  byte _pinZ;
  byte _pinButton;
  int _stateX;
  int _stateY;
  int _stateZ;
  byte _stateBtn;

public:
  Joystick Joystick(byte newPinX, byte newPinY, byte newPinZ, byte newPinBtn);
  void setPinX(byte newPin);
  byte getPinX();
  void setPinY(byte newPin);
  byte getPinY();
  void setPinZ(byte newPin);
  byte getPinZ();
  void setPinBtn(byte newPin);
  byte getPinBtn();
  void setStateX(int newState);
  int getStateX();
  void setStateY(int newState);
  int getStateY();
  void setStateZ(int newState);
  int getStateZ();
  void setStateBtn(byte newState);
  byte getStateBtn();
  void run();
};

class Bargraphs{
private:
  int _baseBars[MAXBARS];
  Shifty _baseBars;
  byte _pinCLK;
  byte _pinDAT;
  byte _pinLAT;
  int _nrBards;
  int _nrLEDs; //total nr of LEDs!
  int _ctrlChipSize;
  int _barSize;

public:
  Bargraphs Bargraphs(int newNr, int newLEDs, int newSize, byte newCLK, byte newDAT, byte newLAT);
  void setPinCLK(byte newPin);
  byte getPinCLK();
  void setPinDAT(byte newPin);
  byte getPinDAT();
  void setPinLAT(byte newPin);
  byte getPinLAT();
  void setNrBars(int newNr);
  int getNrBars();
  void setNrLEDs(int newNr);
  int getNrLEDs();
  void setCtrlChipSize(int newSize);
  int getCtrlChipSize();
  void setBarValue(int barNr, int newValue);
  int getBarValue(int barNr);
  void run();
};

#endif
