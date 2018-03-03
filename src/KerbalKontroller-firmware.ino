#include <QList.h>

const bool DEBUG = false;

//timing settings
const int IDLETIMER = 20000;
const int CONTROLREFRESH = 10;


//Communication variables
bool connection = false;
byte id = 0;


//Controls
Joystick joyA = new Joystick();




void setup() {
  Serial.begin(38400); //KSPSerialIO


  //Inits


}

void loop() {   
  

}
