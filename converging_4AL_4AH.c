#include<LPC21xx.h>
#include "delay.h"
#include "types.h"
#include "arduino_defines.h"
#include "arduino.h"
#define OPINS 8
const char arr[]={0x81,0x42,0x24,0x18};
main(){
    u32 i,n=5;
    //IODIR0 |= ((1<<OPINS)-1)<<OPINS;
		portMode(8,OPINS,OUTPUT);
    while(n){
        for(i=0;i<4;i++){
            //IOSET0 = (0xFF&(arr[i]^0xF0))<<OPINS;
            //delay_ms(600);
            //IOCLR0 = 0xFF<<OPINS;
						IOPIN0 = ((IOPIN0 &~((1<<OPINS)-1)) | (arr[i]^0xF0))<<OPINS;
            delay_ms(1000);
        }
        n--;
    }
}
