/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Button.h
 * Author: bartb
 *
 * Created on March 3, 2018, 12:16 AM
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <limits.h>


class Button {
public:
    Button();
    Button(const Button& orig);
    virtual ~Button();
    unsigned int Button::getLEDstate();
    void setLEDstate(unsigned int newLEDstate);
    unsigned int getLEDstate();
    void SetPinLED(unsigned int newPinLED);
    unsigned int GetPinLED();
    

private:
  unsigned int ctrlType;
  unsigned int btnState;
  unsigned int LEDstate;
  unsigned int pinButton;
  unsigned int pinLED;
};

#endif /* BUTTON_H */
