/*
Write an ECP to Show up counting from 0 to 9 on seg1 and then after show down
counting 9 to 0 on seg2 @ of 1sec (approximately).  
*/
#include "arduino.h"
#include "arduino_defines.h"
#include "delay.h"
#include "types.h"
#include<stdio.h>
#include<stdlib.h>
#define OPINS 8
#define DSEL1 16
#define DSEL2 17

cu8 segLUT[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
main(){
    u32 i;
    portMode(OPINS,8,OUTPUT);
    pinMode(DSEL1,OUTPUT);
    pinMode(DSEL2,OUTPUT);
    while(1){
        digitalWrite(DSEL1,1);
        digitalWrite(DSEL2,0);
        for(i=0;i<10;i++){
            write2Pins(OPINS,8,segLUT[i]);
            delay_ms(500);
        }
        digitalWrite(DSEL1,0);

        digitalWrite(DSEL2,1);
        digitalWrite(DSEL1,0);        
        for(i=0;i<10;i++){
            write2Pins(OPINS,8,segLUT[i]);
            delay_ms(500);
        }

    }
}
