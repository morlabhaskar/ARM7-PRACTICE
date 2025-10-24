//1. Flash an LED connected to any port line at the rate of 1 second for 10 times and stop. 
#include <LPC21xx.h> 
#include "delay.h"
#include "types.h"
#define OPIN 8  // Set P0.8 as output

main(){
    u32 i;
    IODIR0 = 1<<OPIN;
    for(i = 0; i < 10; i++) {
        IOSET0=1<<OPIN;
				delay_ms(1000);
				IOCLR0=1<<OPIN;
				delay_ms(1000);
    }
    while(1);  // End of program
}
