//Write an ECP to display binary equivalent of 0-255 on 8-leds (4-active high led’s and 4-active low led’s)
#include <LPC21xx.h>
#include "delay.h"

void display_binary(unsigned int num) {
    unsigned int ah_part, al_part;

    // Extract active-high (lower nibble) and active-low (upper nibble)
    ah_part = num & 0x0F;        // Bits 0–3
    al_part = (num >> 4) & 0x0F; // Bits 4–7

    // Clear all LEDs
    IOCLR0 = 0x0F;   // Clear active-high LEDs (P0.0–P0.3)
    IOSET0 = 0xF0;   // Turn OFF active-low LEDs (P0.4–P0.7)

    // Set the LEDs according to binary value
    IOSET0 = ah_part;             // Active-high LEDs ON
    IOCLR0 = (al_part << 4);      // Active-low LEDs ON
}

int main(void) {
    //unsigned int i;

    // Configure P0.0–P0.7 as output
    IODIR0 |= 0xFF;

    // Initialize LEDs OFF
    IOCLR0 = 0x0F;  // Turn OFF active-high LEDs
    IOSET0 = 0xF0;  // Turn OFF active-low LEDs

    //while(1) {
        //for(i = 0; i <= 255; i++) {
            display_binary(12);   // Show binary equivalent on LEDs
           // delay_ms(500);       // Delay 0.5 second between counts
        //}
    //}
	while(1);
}
