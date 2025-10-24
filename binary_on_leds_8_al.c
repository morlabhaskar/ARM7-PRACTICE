#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
#define LED_AL_8 8

main(){
	u32 i;
    IODIR0 |= 255<<LED_AL_8;//IODIR0 = IODIR0 | 255<<LED_AL_8
    for(i=0;i<=255;i++){
        IOSET0 = i<<LED_AL_8;
        delay_ms(500);
        IOCLR0 = 255<<LED_AL_8;
        delay_ms(500);
    }
}
//0000000000000011111111
//      1111111100000000

//0000000000000000000000000

//   00000000000000            
//        32  16  8  4  2  1
//         0   0  1  0  1  0

