/*
5. Write an ECP to find the second highest digit in a given integer and display its binary equivalent on 8-LEDS (4-Active High LEDS& 4-Active Low LEDS)
*/

#include<LPC21xx.h>
#include "types.h"
#define OPIN 8
int second_high(int num){
    s32 high=-1,shigh=-1;
    while(num){
        s32 last = num%10; 
        if(last>high){
            shigh=high;
            high=last;
        }
        else if(high>last && shigh<last){
            shigh=last;
        }
        num /= 10;
    }
    return shigh;
}
int main(){
	s32 num = 1789,x;
    IODIR0 |= 255<<OPIN;
    
    x = second_high(num);
    IOPIN0 = ((IOPIN0&~(((1<<OPIN)-1)<<OPIN)) | ((0x0F^x)<<OPIN));
}
