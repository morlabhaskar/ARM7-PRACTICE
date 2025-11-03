#include "arduino.h"
#include "arduino_defines.h"
#include "delay.h"
#include "types.h"
#include<stdio.h>
#include<stdlib.h>
#define CA7SEG_PINS 8
#define ROLL_SW 4
cu8 segLUT[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
main(){
    u32 diceFace,seed;
    portMode(CA7SEG_PINS,8,OUTPUT);
    write2Pins(CA7SEG_PINS,8,segLUT[0]);
    while(1){
        if(digitalRead(ROLL_SW)==0){
            diceFace = (rand()%6)+1;
            srand(seed++);
            write2Pins(CA7SEG_PINS,8,segLUT[diceFace]);
            delay_ms(100);
        }
    }
}

