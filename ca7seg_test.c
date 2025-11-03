#include "arduino.h"
#include "arduino_defines.h"
#include "types.h"
#include "delay.h"
#include<stdio.h>
#include<stdlib.h>
#define CA7SEG_PINS 8
cs8 segLUT[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
main(){
    u32 i;
    portMode(CA7SEG_PINS,8,OUTPUT);
		write2Pins(CA7SEG_PINS,8,segLUT[i]);
    while(1){
        if(digitalRead(4)==0){
					for(;i<10;i++){
            write2Pins(CA7SEG_PINS,8,segLUT[i]);
            delay_ms(500);
						if(digitalRead(4)==1){
							break;
						}
					}
				}
						
				
    }
}
