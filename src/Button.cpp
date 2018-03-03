/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Button.cpp
 * Author: bartb
 *
 * Created on March 3, 2018, 12:16 AM
 */

#include "Button.h"


Button::Button() {
}

Button::Button(const Button& orig) {
}

Button::Button(unsigned int newCtrlType, unsigned int newBtnState, unsigned int newLEDstate, unsigned int newPinButton, unsigned int newPinLED){
    this->ctrlType = newCtrlType;
    this->btnState = newBtnState;
    this->LEDstate = newLEDstate;
    this->pinButton = newPinButton;
    this->pinLED = newPinLED;
    pinMode(this->pinButton,INPUT);
    pinMode(this->pinLED,OUTPUT);
}

Button::~Button() {
}

unsigned int GetLEDstate() const {
    return this->LEDstate;
}

void SetLEDstate(unsigned int newLEDstate) {
    this->LEDstate = newLEDstate;
    digitalWrite(this->pinLED,this->LEDstate);
}

unsigned int GetBtnState() const {
    this->btnState = digitalRead(this->pinButton);
    return this->btnState;
}

void SetBtnState(unsigned int newbtnState) {
    this->btnState = newbtnState;
}

unsigned int GetCtrlType() const {
    return this->ctrlType;
}

void SetCtrlType(unsigned int newCtrlType) {
    this->ctrlType = newCtrlType;
}

unsigned int GetPinButton() const {
    return this->pinButton;
}

void SetPinButton(unsigned int newPinButton) {
    this->pinButton = newPinButton;
    pinMode(this->pinButton,INPUT);
}

unsigned int GetPinLED() const {
    return this->pinLED;
}

void SetPinLED(unsigned int newPinLED) {
    this->pinLED = newPinLED;
    pinMode(this->pinLED,OUTPUT);
}
