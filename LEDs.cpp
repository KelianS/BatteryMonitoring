/* 
 * File:   LEDs.cpp
 * Author: kelia
 * 
 * Created on 14 mai 2021, 14:27
 */

#include "header.h"

LEDs::LEDs() {
    //LED1=RJ7, LED2=RK7, LED3=RJ3
    TRISJbits.TRISJ7 = 0; //En sortie
    TRISKbits.TRISK7 = 0; //En sortie
    TRISJbits.TRISJ3 = 0; //En sortie
    
    LATJbits.LATJ7 = 1;//Light off all the LEDs
    LATKbits.LATK7 = 1;
    LATJbits.LATJ3 = 1;
}

void LEDs::SetAll(bool LedV=1, bool LedO=1, bool LedR=1){
    LATJbits.LATJ7 = LedR;//Light off all the LEDs by default
    LATKbits.LATK7 = LedV;
    LATJbits.LATJ3 = LedO;
}
    
bool LEDs::LedRed(int state = -1){
    if(state == 0 || state == 1){
        LATJbits.LATJ7 = state;
    }
    return PORTJbits.RJ7;
}

bool LEDs::LedGreen(int state = -1){
    if(state == 0 || state == 1){
        LATKbits.LATK7 = state;
    }
    return PORTKbits.RK7;
}

bool LEDs::LedOrange(int state = -1){
    if(state == 0 || state == 1){
        LATJbits.LATJ3 = state;
    }
    return PORTJbits.RJ3;
}





