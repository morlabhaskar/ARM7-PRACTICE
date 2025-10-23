//Write an ECP to display below mentioned patterns on 8-led�s (4-active high led�s and
//4-active low led�s)
//a. Switch ON one by one led from left to right at the rate of 1 second
//b. Switch ON one by one led from right to left at the rate of 1 second 
#include <LPC21xx.h> 
#include "delay.h"
#include "types.h"
#define OPINS 8  // Set P0.8 to P0.15 as output

main(){
    s32 i;
    IODIR0 = ((1<<OPINS)-1)<<OPINS;
		IOSET0 = 15<<OPINS;
		delay_ms(1000);
    for(i = 7; i >= 0; i--) {
        if(i<=3){
			IOCLR0=1<<(OPINS+i);
			delay_ms(1000);
            IOSET0 = 1<<(OPINS+i); 
        }
		else{
			IOSET0=1<<(OPINS+i);
			delay_ms(1000);
			IOCLR0=1<<(OPINS+i);
		}
    }
    while(1);  // End of program
}
