/* 
 * File:   LEDs.cpp
 * Author: kelia
 * 
 * Created on 03 june 2021, 15:20
 */

#include "header.h"

RGB::RGB(){
    //pin in output
    TRISBbits.TRISB7 = 0; //En sortie
    TRISBbits.TRISB8 = 0; //En sortie
    TRISBbits.TRISB9 = 0; //En sortie
    LATBbits.LATB7 = 1;//Light off all the LEDs
    LATBbits.LATB8 = 1;
    LATBbits.LATB9 = 1;
    
    //PPS assign :
    RPB7R =0b1011; //on OC5  Timer2
    RPB8R =0b1100; //on OC8  Timer6
    RPB9R =0b1011; //on OC3  Timer4
    CFGCONbits.OCACLK=1; //choix pour affecter un timer différent a chaque pin OCx

    //Output Compare Config
    //Timer 2  --RED--
    OC5CONbits.OC32 = 0; //OCxR<15:0> is used to compare (16 bits only)
    OC5CONbits.OCTSEL =0; //TimerX is the clock source
    OC5CONbits.OCM=0b110; //PWM mode on OC5, fault pin disabled
    OC5CONbits.ON=0;
    OC5CONbits.SIDL=0; //Continue operation in IDLE (if implemented one day)
    OC5R=0;   //Comparison value
    
    //Timer 6  --GREEN--
    OC8CONbits.OC32= 0; //OCxR<15:0> is used to compare (16 bits only)
    OC8CONbits.OCTSEL =0; //TimerX is the clock source
    OC8CONbits.OCM=0b110; //PWM mode on OC5, fault pin disabled
    OC8CONbits.ON=0;
    OC8CONbits.SIDL=0; //Continue operation in IDLE (if implemented one day)
    OC8R=0;   //Comparison value
    
    //Timer 4   --BLUE--
    OC3CONbits.OC32 = 0; //OCxR<15:0> is used to compare (16 bits only)
    OC3CONbits.OCTSEL =0; //TimerX is the clock source
    OC3CONbits.OCM=0b110; //PWM mode on OC5, fault pin disabled
    OC3CONbits.ON=0;
    OC3CONbits.SIDL=0; //Continue operation in IDLE (if implemented one day)
    OC3R=0;   //Comparison value
    
    //Timer4 Config
    T4CON = 0x0;
    TMR4 =0;
    PR4 = 0xFFFF;
    T4CONbits.TCKPS=0b111; //Prescaler =256
    //T4CONbits.TCS = 0; //use internal clock 80Mhz
    IFS0bits.T4IF=0;
    IEC0bits.T4IE=0;
    T4CONbits.ON =1;
    
    //Timer2 Config
    T2CON = 0x0;
    TMR2 =0;
    PR2 = 0xFFFF;
    T2CONbits.TCKPS=0b111; //Prescaler =256
    //T4CONbits.TCS = 0; //use internal clock 80Mhz
    IFS0bits.T2IF=0;
    IEC0bits.T2IE=0;
    T2CONbits.ON =1;
    
    //Timer6 Config
    T6CON = 0x0;
    TMR6 =0;
    PR6 = 0xFFFF;
    T6CONbits.TCKPS=0b111; //Prescaler =256
    //T4CONbits.TCS = 0; //use internal clock 80Mhz
    IFS0bits.T6IF=0;
    IEC0bits.T6IE=0;
    T6CONbits.ON =1;

    
}

void RGB::setRGB(int red, int green, int blue){
    //[0;65635]
    if(red>0){  
        OC5R =red;   //Comparison value
        OC5CONbits.ON=1;
    }
    else    OC5CONbits.ON=0;
    
    if(green>0){ 
        OC8R=green;   //Comparison value
        OC8CONbits.ON=1;
    }
    else    OC8CONbits.ON=0;
    
    if(blue>0){
        OC8R=blue;   //Comparison value
        OC3CONbits.ON=1;
    }
    else    OC3CONbits.ON=0;  
}

