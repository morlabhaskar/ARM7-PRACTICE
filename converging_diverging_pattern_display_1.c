#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
#define LED_AL_8 8

const u8 pattern[]={0xFF,0x81,0x42,0x24,0x18,0x24,0x42,0x81}

main(){
    s32 i;
    IODIR0 |= 255<<LED_AL_8;
    for(i=0;i<8;i++){
        if(i==0){
            IOSET0=0xFF<<LED_AL_8;
            delay_ms(2000);
        }
        else{
            delay_ms(100*i);
        }
        IOSET0=0xFF<<LED_AL_8;     
        IOCLR0=pattern[i]<<LED_AL_8;
        
    }
	while(1);
}
