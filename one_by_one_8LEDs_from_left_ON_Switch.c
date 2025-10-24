/*
2. Write an ECP to display below mentioned patterns on 8-led’s (4-active high led’s and 4-active low led’s)
    a. Switch ON one by one led from left to right at the rate of 1 second
    b. Switch ON one by one led from right to left at the rate of 1 second 
*/

#include <LPC21xx.h>
#include "delay.h"
#include "types.h"

void pattern_right_to_left(){
    s32 i;
    for(i = 0; i < 8; i++) {    
        if(i < 4) {
            IOCLR0 = (1 << i); 
            delay_ms(500);
            IOSET0 = (1 << i);  
        } else {
            IOSET0 = (1<<i);
            delay_ms(500);
            IOCLR0 = (1 << i);  
        }
    }
}

void pattern_left_to_right() {
    s32 i;
    for(i = 7; i >= 0; i--) {
        if(i < 4) {
            IOCLR0 = (1 << i); 
            delay_ms(500);
            IOSET0 = (1 << i); 
        } else {
            IOSET0 = (1<<i);
            delay_ms(500);
            IOCLR0 = (1 << i); 
        }
    }
}

int main(){
    IODIR0 |= 0xFF;
	
    IOSET0 = 0x0F;
    delay_ms(600);
    while(1){
        // pattern_left_to_right();
        pattern_right_to_left();
    }
}
