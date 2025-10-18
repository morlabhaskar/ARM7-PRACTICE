//for arduino Style
#include "types.h"
#include "delay.h"
#include "arduino_defines.h"
#include "arduino.h"
#define LED_AL_8 8

const u8 pattern[]={0x00,0x81,0x42,0x24,0x18,0x24,0x42,0x81};

main(){
    u32 i,j;
    u8 t;
    for(i=0;i<8;i++){
        pinMode(LED_AL_8+i,OUTPUT);
    }
	while(1){
        for(i=0;i<8;i++){
            t=pattern[i];
            for(j=0;j<8;j++){
                digitalWrite(LED_AL_8+j,!((t>>j)&1));
            }
            if(i==0){
			    delay_ms(2000);
		    }
            else{
			    delay_ms(100*i);
    	    }
        }
    }
}
