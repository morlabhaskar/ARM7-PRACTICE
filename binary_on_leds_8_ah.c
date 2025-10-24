#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
#define LED_AL_8 8
void write2pins(u32 pinStartNo,u32 nPins,u32 data){
    if(pinStartNo<32){
        IOPIN0 = ((IOPIN0&~(((1<<nPins)-1)<<pinStartNo))|(data<<pinStartNo));
    }
    else if((pinStartNo>=32)&&(pinStartNo<=47)){
        IOPIN1 = ((IOPIN1&~(((1<<nPins)-1)<<(pinStartNo-16)))|(data<<(pinStartNo-16)));
    }
}

int main(){
	u32 i;
    IODIR0 |= (((1<<LED_AL_8)-1)<<LED_AL_8);
    for(i=0;i<=255;i++){
        // IOSET0 = i<<LED_AL_8;
        // delay_ms(500);
        // IOCLR0 = 255<<LED_AL_8;
        // delay_ms(500);
        // IOPIN0 = ((IOPIN0&~(((1<<LED_AL_8)-1)<<LED_AL_8)) | (i<<LED_AL_8));
        write2pins(LED_AL_8,8,i);
		delay_ms(600);
    }
	while(1);
}

