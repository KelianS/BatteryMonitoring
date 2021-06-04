/* 
 * File:   ADC.cpp
 * Author: kelia
 * 
 * Created on 14 mai 2021, 13:19
 */

#include "header.h"

ADC::ADC() {
    // INIT
    /* initialize ADC calibration setting */ 
    ADC0CFG = DEVADC0;
    ADC1CFG = DEVADC1;
    ADC2CFG = DEVADC2;
    ADC3CFG = DEVADC3;
    ADC4CFG = DEVADC4;
    ADC7CFG = DEVADC7;
    
    /* Configure ADCCON1 */
    ADCCON1 = 0;   // No ADCCON1 features are enabled including: Stop-in-Idle, turbo, //désactive tous les trucs superflux
    // CVD mode, Fractional mode and scan trigger source.
    /* Configure ADCCON2 */
    ADCCON2 = 0;   // Since, we are using only the Class 1 inputs, no setting is
    // required for ADCDIV
    /* Initialize warm up time register */
    ADCANCON = 0;
    ADCANCONbits.WKUPCLKCNT = 5; // Wakeup exponent = 128 * TADx
    /* Clock setting */
    ADCCON3 = 0;
    ADCCON3bits.ADCSEL = 0;       // Select input clock source
    ADCCON3bits.CONCLKDIV = 1;    // Control clock frequency is half of input clock ??????????
    ADCCON3bits.VREFSEL = 0;      // Select AVDD and AVSS as reference source
    /* Select ADC sample time and conversion clock */
    ADC0TIMEbits.ADCDIV = 1;      // ADC0 clock frequency is half of control clock = TAD0 || 128* TQ = TAD
    ADC0TIMEbits.SAMC = 5;        // ADC0 sampling time = 31 * TAD0
    ADC0TIMEbits.SELRES = 3;      // ADC0 resolution is 10 bits

    /* Select analog input for ADC modules, no presync trigger, not sync sampling */
    ADCTRGMODEbits.SH4ALT = 0;    // ADC0 = AN0

    /* Select ADC input mode */
    ADCIMCON1bits.SIGN7 = 0;      // unsigned data format
    ADCIMCON1bits.DIFF7 = 0;      // Single ended mode
    
    ADCCON3bits.DIGEN7=1;

    /* Configure ADCGIRQENx */
    ADCGIRQEN1 = 0;               // No interrupts are used
    ADCGIRQEN2 = 0;
    /* Configure ADCCSSx */
    ADCCSS1 = 0;                  // No scanning is used
    ADCCSS2 = 0;  
    /* Configure ADCCMPCONx */
    ADCCMPCON1 = 0;               // No digital comparators are used. Setting the ADCCMPCONx
    ADCCMPCON2 = 0;               // register to '0' ensures that the comparator is disabled.
    ADCCMPCON3 = 0;               // Other registers are ?don't care?.
    ADCCMPCON4 = 0;
    ADCCMPCON5 = 0;
    ADCCMPCON6 = 0;
    
    /*Configure ADCFLTRx*/
    ADCFLTR1=0;
    ADCFLTR2=0;
    ADCFLTR3=0;
    ADCFLTR4=0;
    ADCFLTR5=0;
    ADCFLTR6=0;
    
    /*Set up Trigger sources*/
    ADCTRGSNSbits.LVL5=0; //edge trigger
    ADCTRG2bits.TRGSRC5=1; //AN5 software trigger
    
    ADCEIEN1 =0;
    ADCEIEN2 =0;
    ADCCON1bits.ON = 1;
    
    while(!ADCCON2bits.BGVRRDY);
    while(ADCCON2bits.REFFLT);
    
    ADCANCONbits.ANEN7 = 1;
    
    while(!ADCANCONbits.WKRDY7);
    ADCCON3bits.DIGEN7 = 1;
    
    TRISBbits.TRISB10=1; //Pin input
    ANSELBbits.ANSB10=1; //Analog mode
}

int ADC::ReadADC(){
    int result;
     /* Trigger a conversion */
  
    ADCCON3bits.GSWTRG = 1;
    
    while (ADCDSTAT1bits.ARDY5 == 0);   /* Wait the conversions to complete */
 
   result= ADCDATA5;    /* fetch the result */
   
   return result;
    
}





