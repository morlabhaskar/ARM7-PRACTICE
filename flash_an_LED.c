//Flash an LED connected to any port line at the rate of 1 second for 10 times and stop.
#include <LPC21xx.h>   // Header for LPC2129 registers
#include "delay.h"
#define OPIN 6  // Set P0.6 as output

int main(void) {
    unsigned int i;
    IODIR0 = (8 << OPIN);
    for(i = 0; i < 10; i++) {
        IOSET0 = (8 << OPIN);  // Turn ON LED
        delay_ms(200);   // Delay 200 milli seconds

        IOCLR0 = (8 << OPIN);  // Turn OFF LED
        delay_ms(200);   // Delay 200 milli seconds
    }
    // Stop blinking (LED remains ON)
    IOSET0 = (8 << OPIN);

    while(1);  // End of program
}

