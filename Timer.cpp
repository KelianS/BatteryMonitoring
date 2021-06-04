/* 
 * File:   Processing.cpp
 * Author: nour
 * 
 * Created on 04 june 2021, 11:00
 */

#include "header.h"


Timer::Timer(){
    
}

void Timer::wait_4s()
{
    PR1= 0xFFFF;        //
    T1CONbits.ON=0;     //

    IFS0bits.T1IF=0;    //
    T1CONbits.TCKPS=0b11;// le plus long temps

    T1CONbits.TCKPS0=0; //
    T1CONbits.TCS=0;    //
    T1CONbits.TGATE=0;  //
    TMR1 =0x0000;       //
    T1CONbits.ON=1;     //

while(IFS0bits.T1IF==0) //
{
    // attendre  } 
   // 4 s en maximal
}
IFS0bits.T1IF=0; 
 
}

void Timer::startTempo4s(){
    PR1= 0xFFFF;        //
    T1CONbits.ON=0;     //
    TMR1 =0x0000;       //

    IFS0bits.T1IF=0;    //
    T1CONbits.TCKPS=0b11;// le plus long temps

    T1CONbits.TCKPS0=0; //
    T1CONbits.TCS=0;    //
    T1CONbits.TGATE=0;  //
    T1CONbits.ON=1;     //
}


bool Timer::wait24h()
{
    if(this->iCPT24 == 0){
        iCPT24=10;
        return true;
    }
    else {
        if(this->tempo4sDone){
            startTempo4s();
            tempo4sDone =false;
        }
        else {
            this->Tempo4sDone(); //Check if finished
        }
        return false;
    }
}

void Timer::Tempo4sDone(){
    if(IFS0bits.T1IF){
        this->tempo4sDone =true;
        IFS0bits.T1IF=0; //acquitte Timer
        iCPT24--;
    }
}