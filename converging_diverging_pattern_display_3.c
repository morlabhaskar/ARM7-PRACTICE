#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "defines.h"
#define LED_AL_8 8

const u8 pattern[]={0x00,0x81,0x42,0x24,0x18,0x24,0x42,0x81};
void write_2_port_byte(u32 portNo,u32 pinStartNo,u8 byte){
    if(portNo==0){
        IOCLR0=0xFF<<pinStartNo;
        IOSET0=byte<<pinStartNo;
    }
    else if(portNo==1){
        IOCLR1=0xFF<<pinStartNo;
        IOSET1=byte<<pinStartNo;
    }
}

main(){
    s32 i;
    WRITEBYTE(IODIR0,LED_AL_8,0xFF);
		while(1){
        for(i=0;i<8;i++){
            write_2_port_byte(1,LED_AL_8,~pattern[i]);
            if(i==0){
			    delay_ms(2000);
		    }
            else{
			    delay_ms(100*i);
    	    }
        }
    }
}
