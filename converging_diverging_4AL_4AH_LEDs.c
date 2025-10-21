#include "types.h"
#include "delay.h"
#include "arduino_defines.h"
#include "arduino.h"
#define LEDS_4AL_4AH 8

const u8 pattern[]={0x00,0x81,0x42,0x24,0x18,0x24,0x42,0x81};

main(){
    u32 i;
    u8 t;
    portMode(LEDS_4AL_4AH,8,OUTPUT);
    while(1){
        for(i=0;i<8;i++){
            t=pattern[i];
            write2Pins(LEDS_4AL_4AH,8,(t^0x0F));
        }
        if(i==0){
            delay_ms(2000);
        }
        else{
            delay_ms(100*i);
        }

    }
}
