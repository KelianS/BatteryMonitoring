/* 
 * File:   BoutonPoussoir.cpp
 * Author: kelia
 * 
 * Created on 14 mai 2021, 13:37
 */

#include "header.h"

BoutonPoussoir::BoutonPoussoir() {
    //Configure SW2 on Port RJ5
    TRISJbits.TRISJ5 = 1; //En entrée
}

bool BoutonPoussoir::GetState(){
    //BP trigger = 0 / else = 1
    return (PORTJbits.RJ5==false);
}


