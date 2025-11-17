/*
Write an ECP for Single segment only should be lit (starting from segment A)
cyclically around the periphery of single seven segment (5 times clock wise and 5 times
anti-clock wise @ proper visualization). 
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

// cu8 segLUT[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
cu8 segLUT[]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF};
main(){
    u32 i,cnt=0;
    portMode(OPINS,8,OUTPUT);
    for(cnt=0;cnt<10;cnt++){
        if(cnt<5){
            for(i=0;i<6;i++){
                write2Pins(8,8,segLUT[i]);
                delay_ms(100);
            }
        }else{
            for(i=6;i>0;i--){
                write2Pins(8,8,segLUT[i-1]);
                delay_ms(100);
            }
        }
    }
		write2Pins(8,8,0xC0);
}
