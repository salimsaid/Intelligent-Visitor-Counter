/*
 * File:   visitorSensorMain.c
 * Author: Salim
 *
 * Created on December 9, 2015, 7:07 PM
 */


#define _XTAL_FREQ 8000000 //The speed of your internal(or)external oscillator
#define USE_AND_MASKS
#include "config.h"
#include <xc.h>

#define bulb RB4
#define sensor RC0

int direction = 0;

/**
 * This function will initialize OSSCON register 
 * the bits IRCF0,IRCF1 and IRCF2 are all set to 1
 * this will set this will initialize the internal
 * Crystal frequency to 8Mhz
 * @No arguments
 */
void SetupClock()
{
    OSCCONbits.IRCF0 = 1;
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF2 = 1;
}

/**
 * This function will create a software delay in ms 
 * The delay time is determined by the value
 * passed to the function i.e 1 = 1ms Delay
 * @param int
 */
void msDelay(unsigned int x){
    for(int i = 0; i < x; i++){
        __delay_ms(1);
    }
}

/**
 * Initialize ports and set port direction
 */
void portInit(){
    TRISBbits.RB4 = 0;
    TRISCbits.RC0 = 1;
    bulb = 0;
}



void main(void) {
    SetupClock();
    portInit();
    while(true){
        /**
         * Check if there is someone in the room, 
         * if a person is detected inside the room then 
         * switch on the bulb, otherwise keep the bulb off.
         */
        while(direction == 0){
            if(!sensor){
            msDelay(100);
            if(!sensor){
                msDelay(100);
                bulb = 1;
                direction = 1;
            }
        }
        }
        while(direction == 1){
            if(!sensor){
                msDelay(100);
                    if(!sensor){
                        msDelay(100);
                        bulb = 0;
                        direction = 0;
                    }
                }
            }
        }
    }
    


