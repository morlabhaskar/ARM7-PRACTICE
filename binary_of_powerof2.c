#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
#define OPINS 8
#define TRIG_PIN 0
main(){
    u32 i;
    IODIR0 |= 255<<OPINS;
    while(1){
        for(i=0;i<=7;i++){
            if(((IOPIN0>>TRIG_PIN)&1)==0){
                IOPIN0 = ((IOPIN0&~(255<<OPINS)) | ((1<<i)<<OPINS));
								delay_ms(600);
                while(((IOPIN0>>TRIG_PIN)&1)==0);
                i++;
            }
        }
    }
}
