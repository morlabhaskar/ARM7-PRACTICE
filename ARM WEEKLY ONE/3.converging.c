/*
3. Create a display on 8 LED’s (4-active high and 4-active low) connected to port0 (0.0- 0.7) in the given pattern.
    a. First all LEDs should be OFF, at 1st second, LED 0 and LED 7 (P0.0 and P0.7) should be ON
    b. At 2nd second, LED 1 and LED 6 (P0.1 and P0.6) should be ON
    c. At 3rd second, LED 2 and LED 5 (P0.2 and P0.5) should be ON
    d. At 4th second, LED 3 and LED 4 (P0.3 and P0.4) should be ON
    e. Repeat above pattern for 5 times and stop the process.  
*/
#include<LPC21xx.h>
#include "delay.h"

#define OPINS 8
const char arr[]={0x81,0x42,0x24,0x18};
main(){
    u32 i,n=5;
    IODIR0 |= ((1<<OPINS)-1)<<OPINS;
    while(n){
        for(i=0;i<4;i++){
            //IOSET0 = (arr[i]^0x0F)<<OPINS;
            //delay_ms(600);
            //IOCLR0 = 0xFF<<OPINS;
            IOPIN0 = ((IOPIN0&~((0xFF)<<OPINS))|(arr[i]^0x0F)<<OPINS);
			delay_ms(300);
        }
        n--;
    }
    IOCLR0 = (0xFF << OPINS);  
    IOSET0 = (0x0F << OPINS);   
}