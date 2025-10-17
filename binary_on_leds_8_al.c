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
        IOCLR0 = i<<LED_AL_8;
        delay_ms(500);
    }
}
