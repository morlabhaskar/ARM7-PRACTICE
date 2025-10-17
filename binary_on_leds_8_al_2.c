#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
#define LED_AL_8 8

main(){
		u32 i;
    IODIR0 |= 255<<LED_AL_8;
    for(i=0;i<=255;i++){
        IOPIN0 = ((IOPIN0 &~(255<<LED_AL_8)) | (~i<<LED_AL_8));
        delay_ms(700);
    }
}
