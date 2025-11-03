#include "arduino.h"
#include "arduino_defines.h"
#include "delay.h"
#include "types.h"
#include<stdio.h>
#include<stdlib.h>
#define CA7SEG_2_MUX_PINS 8
#define DSEL1 16
#define DSEL2 17

cu8 segLUT[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
main(){
    u32 i=15;
    portMode(CA7SEG_2_MUX_PINS,10,OUTPUT);
    while(1){
        write2Pins(CA7SEG_2_MUX_PINS,8,segLUT[i/10]);
        digitalWrite(DSEL1,1);
        delay_ms(1);
        digitalWrite(DSEL1,0);

        write2Pins(CA7SEG_2_MUX_PINS,8,segLUT[i%10]);
        digitalWrite(DSEL2,1);
        delay_ms(1);
        digitalWrite(DSEL2,0);
    }
}

