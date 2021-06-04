#include "header.h"


int ConfigureSW2(){
    //Port RJ5
    TRISJbits.TRISJ5 = 1; //En entrée
    return 0;
}

int ConfigureLeds(){
    //LED1=RJ7, LED2=RK7, LED3=RJ3
    TRISJbits.TRISJ7 = 0; //En sortie
    TRISKbits.TRISK7 = 0; //En sortie
    TRISJbits.TRISJ3 = 0; //En sortie
    
    LATJbits.LATJ7 = 1;
    LATKbits.LATK7 = 1;
    LATJbits.LATJ3 = 1;
    
    return 0;
}

int ConfigureADC(){
    
    return 0;
}

bool SW2_GetState(){
    //BP trigger = 1 / else = 0
    return (PORTJbits.RJ5==false);
}


void main (){
    
    ConfigureSW2();
    ConfigureLeds();

    while(1){
        if(SW2_GetState()){
            int b =5;
            LATJbits.LATJ7 = 0;
        }
        else{
            LATJbits.LATJ7 =1;
        }
    }
    
}


