#include "arduino_defines.h"
#include "types.h"
#include "LPC21xx.h"
#define SW1_AL 4
#define SW2_AL 5
#define SW3_AL 6
#define SW4_AL 7

#define LED1_AL 8
#define LED2_AL 9
#define LED3_AL 10
#define LED4_AL 11
void pinMode(u32 pinNo,u32 pinDir){
    if(pinNo<32){
        if(pinDir==OUTPUT){
            IODIR0 |= 1<<pinNo;
        }
        else{
            IODIR0 &= ~(1<<pinNo);
        }
    }
    else if((pinNo>=32)&&(pinNo<=47)){
        if(pinDir==OUTPUT){
            IODIR1 |= 1<<(pinNo-16);
        }
        else{
            IODIR1 &= ~(1<<(pinNo-16));
        }
    }
}
u32 digitalRead(u32 pinNo){
    u32 bit;
    if(pinNo<32){
        bit = ((IOPIN0>>pinNo)&1);
    }
    else if((pinNo>=32)&&(pinNo<=47)){
        bit = ((IOPIN1>>(pinNo-16))&1);
    }
    return bit;
}
void digitalWrite(u32 pinNo,u32 bit){
    if(pinNo<32){
        bit ? (IOSET0 = 1<<pinNo) : (IOCLR0 = 1<<pinNo);
    }
    else if((pinNo>=32)&&(pinNo<=47)){
        bit ? (IOSET0 = 1<<(pinNo-16)) : (IOCLR0 = 1<<(pinNo-16));
    }
}
main(){
    u32 i;
    for(i=0;i<4;i++){
        pinMode(LED1_AL+i,OUTPUT);
    }
    while(1){
        for(i=0;i<4;i++){
            digitalWrite(LED1_AL+i,digitalRead(SW1_AL+i));
        }
    }
}
