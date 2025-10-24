/*
2. Write an ECP to display below mentioned patterns on 8-led’s (4-active high led’s and 4-active low led’s)
    a. Switch ON one by one led from left to right at the rate of 1 second
    b. Switch ON one by one led from right to left at the rate of 1 second 
*/

#include <LPC21xx.h>
#include "delay.h"

void pattern_right_to_left(){
    unsigned int i;
    for(i = 0; i < 8; i++) {
        // Turn OFF all LEDs first
        IOCLR0 = 0x0F;         // Clear active-high LEDs (P0.0-P0.3)
        IOSET0 = 0xF0;         // Set inactive state for active-low LEDs (P0.4-P0.7)

        // Turn ON current LED
        if(i < 4) {
            IOSET0 = (1 << i); // Active-high LED ON
        } else {
            IOCLR0 = (1 << i); // Active-low LED ON
        }
        delay_ms(800);
    }
}

void pattern_left_to_right(void) {
    int i;
    for(i = 7; i >= 0; i--) {
        // Turn OFF all LEDs first
        IOCLR0 = 0x0F;         // Clear active-high LEDs
        IOSET0 = 0xF0;         // Set inactive state for active-low LEDs

        // Turn ON current LED
        if(i < 4) {
            IOSET0 = (1 << i); // Active-high LED ON
        } else {
            IOCLR0 = (1 << i); // Active-low LED ON
        }
        delay_ms(400);
    }
}

int main(){
    //configure P0-0 to P0.7 as Output 0xFF=(1111 1111)
    IODIR0 |= 0xFF;

    while(1){
        //pattern_left_to_right();
        pattern_right_to_left();
    }
}
