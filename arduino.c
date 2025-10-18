#include<LPC21xx.h>
#include "types.h"
#include "arduino_defines.h"

void pinMode(u32 pinNo,u32 pinDir){
    if(pinNo<32){
        if(pinDir==OUTPUT){
            IODIR0 |= 1<<pinNo;
        }
        else{
            IODIR0 &= ~(1<<pinNo);
        }
    }
    else if((pinNo>=32) && (pinNo<=47)){
        if(pinDir==OUTPUT){
            IODIR1 |= 1<<pinNo;
        }
        else{
            IODIR1 &= ~(1<<pinNo);
        }
    }
}
void digitalWrite(u32 pinNo,u32 bit){
    if(pinNo<32){
        bit ? (IOSET0 = 1<<pinNo) : (IOCLR0 = 1<<pinNo);
    }
    else if((pinNo>=32) && (pinNo<=47)){
        bit ? (IOSET1 = (1<<(pinNo-16))) : (IOCLR1 = (1<<(pinNo-16)));
    }
}
void digitalRead(u32 pinNo){
    u32 bit;
    if(pinNo<32){
        bit = ((IOPIN0>>pinNo)&1);
    }
    else if((pinNo>=32) && (pinNo<=47)){
        bit = ((IOPIN1>>(pinNo-16))&1);
    }
    return bit;
}
