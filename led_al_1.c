#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
#define LED_AL_8 8

main(){
    IODIR0 |= 1<<LED_AL_8;
    while(1){
        IOCLR0 = 1<<LED_AL_8;
        delay_ms(1000);
        IOSET0 = 1<<LED_AL_8;
        delay_ms(1000);
    }
}
