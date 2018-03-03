/*
 * 
 * type Listing:
 * 0x00 = Button
 * 0x01 = Slider
 * 0x02 = Joystick
 * 0x03 = Bargraph
 * 0x04 = LCD screen
 */

#include <Wire.h>
#include <Shifty.h>

const int testTIMER = 20000;
const int MAXBARS = 10;

#ifndef Button
#define Button
// Button with LED
class Button{
  byte type = 0x00;
  byte state;
  byte LEDstate;
  byte pinButton;
  byte pinLED;
  String name;

  public:

  byte getType(){
    return type;
  }

  void setState(bool newState){
    state = newState;
    setLED(state);
  }

  bool getState(){
    return state;
  }

  void setPinButton(byte newPin){
    pinButton = newPin;
    pinMode(pinButton,INPUT);
  }

  byte getPinButton(){
    return pinButton;
  }

  void setPinLED(byte newPin){
    pinLED = newPin;
    pinMode(pinLED,OUTPUT);
    digitalWrite(pinLED,LOW);
  }

  byte getPinLED(){
    return pinLED;
  }

  void setName(String newName){
    name = newName;
  }

  String getName(){
    return name;
  }

  void setLED(byte newState){
    LEDstate = newState;
    digitalWrite(pinLED,newState);
  }

  byte getLED(){
    return LEDstate;
  }

  void testLED(){
    digitalWrite(pinLED,HIGH);
    delay(testTIMER);
    digitalWrite(pinLED,LOW);
    
  }

  void flip(){
    setState(!state);
    setLED(!LEDstate);
  }

  void setup(String newName, byte pBtn, byte pLED){
    setPinButton(pBtn);
    setPinLED(pLED);
    setName(newName);
  }

  void loop(){
    byte oldState = state;
    state = digitalRead(pinButton);
    if (state != oldState){
      setState(state);
    }
  }
  
};
#endif

#ifndef Slider
#define Slider
class Slider{
  byte type = 0x01;
  int state;
  byte pinSlider;
  String name;

 public:

 byte getType(){
  return type;
 }
 void setState(int newState){
  state = newState;
 }
 int getState(){
  return state;
 }
 void setPinSlider(byte newPin){
  pinSlider = newPin;
  pinMode(pinSlider,INPUT);
 }
 byte getPinSlider(){
  return pinSlider;
 }
 void setName(String newName){
  name = newName;
 }
 String getName(){
  return name;
 }

 void setup(byte newPin,String newName){
  setPinSlider(newPin);
  setName(newName);
 }
 void loop(){
  int oldState = state;
  state = analogRead(pinSlider);
  if (state != oldState){
    setState(state);
  }
 }
};
#endif

#ifndef Joystick
#define Joystick
class Joystick{
  byte type = 0x02;
  byte pinX;
  byte pinY;
  byte pinZ;
  byte pinButton;
  int stateX;
  int stateY;
  int stateZ;
  byte stateBtn;
  String name;

  public:
  void setPinX(byte newPin){
    pinX = newPin;
    pinMode(pinX,INPUT);
  }
  byte getPinX(){
    return pinX;
  }
  void setPinY(byte newPin){
    pinY = newPin;
    pinMode(pinY,INPUT);
  }
  byte getPinY(){
    return pinY;
  }
  void setPinZ(byte newPin){
    pinZ = newPin;
    pinMode(pinZ,INPUT);
  }
  byte getPinZ(){
    return pinZ;
  }
  void setPinBtn(byte newPin){
    pinButton = newPin;
    pinMode(pinButton,INPUT);
  }
  byte getPinBtn(){
    return pinButton;
  }
  void setStateX(int newState){
    stateX = newState;
  }
  int getStateX(){
    return stateX;
  }
  void setStateY(int newState){
    stateY = newState;
  }
  int getStateY(){
    return stateY;
  }
  void setStateZ(int newState){
    stateZ = newState;
  }
  int getStateZ(){
    return stateZ;
  }
  void setStateBtn(byte newState){
    stateBtn = newState;
  }
  byte getStateBtn(){
    return stateBtn;
  }
  void setName(String newName){
    name = newName;
  }
  String getName(){
    return name;
  }
  void setup(byte newPinX,byte newPinY,byte newPinZ,byte newPinBtn,String newName){
    setPinX(newPinX);
    setPinY(newPinY);
    setPinZ(newPinZ);
    setPinBtn(newPinBtn);
    setName(newName);
  }
  void loop(){
    int oldState = stateX;
    int newState = analogRead(pinX);
    if(newState != oldState){
      setStateX(newState);
    }
    oldState = stateY;
    newState = analogRead(pinY);
    if(newState != oldState){
      setStateY(newState);
    }
    oldState = stateZ;
    newState = analogRead(pinZ);
    if(newState != oldState){
      setStateZ(newState);
    }
    oldState = stateBtn;
    newState = stateBtn = analogRead(pinButton);
    if(newState != oldState){
      setStateBtn(newState);
    }
  }
};
#endif

#ifndef Bargraphs
#define Bargraphs
class Bargraphs{
  int baseBars[MAXBARS];
  Shifty registers;
  byte type = 0x03;
  byte pinCLK;
  byte pinDAT;
  byte pinLAT;
  int nrBars;
  int nrLEDs; //total!
  int ctrlChipSize = 8;
  int barSize = 0;

  public:
  void setPinCLK(byte newPin){
    pinCLK = newPin;
  }
  byte getPinCLK(){
    return pinCLK;
  }
  void setPinDAT(byte newPin){
    pinDAT = newPin;
  }
  byte getPinDAT(){
    return pinDAT;
  }
  void setPinLAT(byte newPin){
    pinLAT = newPin;
  }
  byte getPinLat(){
    return pinLAT;
  }
  void setNrBars(int newNr){
    nrBars = newNr;
  }
  int getNrBars(){
    return nrBars;
  }
  void setNrLEDs(int newNr){
    nrLEDs = newNr;
  }
  int getNrLEDs(){
    return nrLEDs;
  }
  void setCtrlChipSize(int newSize){
    ctrlChipSize = newSize;
  }
  int getCtrlChipSize(){
    return ctrlChipSize;
  }
  void setBarValue(int barNr, int newValue){
    baseBars[barNr] = newValue;
  }
  int getBarValue(int barNr){
    return baseBars[barNr];
  }

  void setup(int newNr, int newLEDs, int newSize, int newCLK, int newDAT, int newLAT){
    setNrBars(newNr);
    setNrLEDs(newLEDs);
    setCtrlChipSize(newSize);
    setPinCLK(newCLK);
    setPinDAT(newDAT);
    setPinLAT(newLAT);
    registers.setBitCount(newLEDs);
    registers.setPins(newDAT,newCLK,newLAT);
    barSize = nrLEDs/nrBars;
  }

  void loop(){
    for (int i = 0; i<nrBars; i++){
      int result = map(baseBars[i],0,0,1000,10);
      int j;
      for (j = 0; j <= result;j++){
        registers.writeBit((i*10)+j,HIGH);
      }
      for ( j; j <= barSize; j++){
        registers.writeBit((i*10)+j,LOW);
      }
    }
  }
  
};
#endif



