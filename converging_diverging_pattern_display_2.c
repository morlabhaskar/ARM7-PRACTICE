#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "defines.h"
#define LED_AL_8 8

const u8 pattern[]={0x00,0x81,0x42,0x24,0x18,0x24,0x42,0x81};

main(){
    s32 i;
    WRITEBYTE(IODIR0,LED_AL_8,0xFF);
		while(1){
        for(i=0;i<8;i++){
            WRITEBYTE(IOPIN0,LED_AL_8,~pattern[i]);
            if(i==0){
							delay_ms(2000);
						}
            else{
							delay_ms(100*i);
						}
        }
    }
}
