#include "LPC21xx.h"
#include "types.h"
#include "defines.h"
#define SW_AL 4    //@p0.4
#define LED_AL 8   //@p0.8

main(){
    SETBIT(IODIR0,LED_AL);
    while(1){
        READWRITEBIT(IOPIN0,LED_AL,IOPIN0,SW_AL);
    }
}