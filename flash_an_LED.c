
// #include <LPC21xx.h>   // Header for LPC2129 registers
// #include "delay.h"
// #define OPIN 0  // Set P0.6 as output

// int main(void) {
//     unsigned int i;
//     IODIR0 = (31 << OPIN);
//     for(i = 0; i < 5; i++) {
//         IOSET0 = (1 << i);  // Turn ON LED
//         delay_ms(1000);   // Delay 200 milli seconds

//         IOCLR0 = (1 << i);  // Turn OFF LED
//         delay_ms(1000);   // Delay 200 milli seconds
//     }
//     // Stop blinking (LED remains ON)
//     IOSET0 = (1 << i);

//     while(1);  // End of program
// }

//Flash an LED connected to any port line at the rate of 1 second for 10 times and stop.
#include <LPC21xx.h>   // Header for LPC2129 registers
#include "delay.h"
// #define OPIN 0  // Set P0.6 as output

int main(void) {
    unsigned int i;
    IODIR0 = 1023;
    for(i = 0; i < 10; i++) {
        IOSET0 = (1 << i);  // Turn ON LED
        delay_ms(300);   // Delay 200 milli seconds

        IOCLR0 = (1 << i);  // Turn OFF LED
        delay_ms(300);   // Delay 200 milli seconds
    }
    // Stop blinking (LED remains ON)
    //IOSET0 = (1 << i);

    while(1);  // End of program
}

