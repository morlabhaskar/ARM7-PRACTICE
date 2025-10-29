/*
4. Write an ECP to display binary equivalent of 0-255 on 8-leds (4-active high led’s an 4-active low led’s)
*/
#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
#define LED_AL_8 8

main(){
	u32 i;
    IODIR0 |= 255<<LED_AL_8;
    for(i=0;i<=255;i++){
        IOSET0 = 255<<LED_AL_8;
        delay_ms(500);
        IOCLR0 = (0xF0^i)<<LED_AL_8;
        delay_ms(500);
    }
}