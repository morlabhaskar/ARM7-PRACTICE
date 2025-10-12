//Active LEDs @PO.0 to PO.7 Each 300 milli sec delay 
#include<LPC21xx.h>
#include "delay.h"

int main(){
    unsigned int i;
    IODIR0 = 255<<0;
    for(i=0;i<8;i++){
        IOSET0 = 1<<i;
        delay_ms(300);
    }
    while(1);
}
