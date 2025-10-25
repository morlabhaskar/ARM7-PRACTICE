#include "LPC21xx.h"
#include "types.h"
#define SW_AL 4    //@p0.4
#define LED_AL 8   //@p0.8

main(){
    IODIR0 |= 1<<LED_AL;
    while(1){
        if(((IOPIN0>>SW_AL)&1)==0){
            IOCLR0 = 1<<LED_AL;
        }
        else{
            IOSET0 = 1<<LED_AL;
        }
    }
}
