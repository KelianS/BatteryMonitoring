/* 
 * File:   Processing.cpp
 * Author: kelia
 * 
 * Created on 29 mai 2021, 16:29
 */

#include "header.h"


int Processing::processVoltage(float Voltage){
    int iState;
    
    if(Voltage>=12.3){
        iState=STATE::high;
    }
    else if(Voltage>=12){
        iState=STATE::mid1;
    }
    else if(Voltage>=11.8){
        iState=STATE::mid2;
    } 
    else if(Voltage>=11.3){
        iState=STATE::wk;
    }
    else{
        iState=STATE::ct;
    }
    
    return iState;
}


void Processing::UpdateLedState(int iState,LEDs LED, RGB rgb){
    switch(iState){
        case STATE::high :
            LED.SetAll(LEDs::ON,LEDs::OFF,LEDs::OFF); // Vert +vertRGB
            rgb.setRGB(0,1,0);
            break;
        case STATE::mid1 :
            LED.SetAll(LEDs::OFF,LEDs::ON,LEDs::OFF); //Orange +vertRGB
            rgb.setRGB(0,1,0);
            break;
        case STATE::mid2 :
            LED.SetAll(LEDs::OFF,LEDs::ON,LEDs::OFF); //Orange +OrangeRGB
            rgb.setRGB(1,1,0);
            break;
        case STATE::wk :
            LED.SetAll(LEDs::OFF,LEDs::OFF,LEDs::ON); //RED +OrangeRGB
            rgb.setRGB(1,1,0);
            break;            
        case STATE::ct :
            LED.SetAll(LEDs::OFF,LEDs::OFF,LEDs::ON); //RED +RougeRGB
            rgb.setRGB(1,0,0);
            break;
        default :
            LED.SetAll(LEDs::OFF,LEDs::OFF,LEDs::OFF); //RED +RougeRGB
            rgb.setRGB(0,0,0);
        break; 
    }
}


