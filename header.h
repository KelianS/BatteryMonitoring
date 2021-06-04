/* 
 * File:   header.h
 * Author: kelia
 *
 * Created on 14 mai 2021, 13:19
 */

#ifndef HEADER_H
#define	HEADER_H

#define LED_OFF 1
#define LED_ON 0

#include <xc.h>
#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>
#include <sys/attribs.h>  



class BoutonPoussoir {
public:
    BoutonPoussoir(); //Constructor
    bool GetState();
    
private:

};

class ADC {
public:  
    ADC(); //Constructor
    
    int ReadADC();
    
private:
};

class Timer {
public:
    Timer(); //Constructor

    
    void wait_4s();
    void startTempo4s();
    void Tempo4sDone();
    bool wait24h();
    
private :
    int iCPT24 = 0;
    bool tempo4sDone=true;
};

class LEDs {
public:
    enum {ON=0,OFF=1};
    LEDs(); //Constructor
    
    void SetAll(bool LedV, bool LedO, bool LedR);
    static bool LedGreen(int state);
    static bool LedOrange(int state);
    static bool LedRed(int state);
    
private:
};

class RGB {
public:

    RGB(); //Constructor
    
    void setRGB(int red, int green, int blue);

    
private:
};

class Processing{ // /!\ Processing is a static class
public:
    enum STATE{high=1,mid1,mid2,wk,ct};
    
    
    static int processVoltage(float iVoltage);
    static void UpdateLedState(int iState,LEDs LED, RGB rgb);
    
private:    
};







#endif	/* HEADER_H */

