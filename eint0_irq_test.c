#include<LPC21xx.h>
#include "types.h"
#include "pin_functions_defines.h"
#include "pin_connect_block.h"

#define EINT0_VIC_CHNO 14
#define EINT0_STATUS_LED 16
#define EINT0_PIN_0_1 PIN_FUNC4

void eint0_isr(void) __irq;
u32 gCount;
main(){
    //cfg EINT0 status led pin as gpio output
    IODIR1 |= 1<<EINT0_STATUS_LED;

    //cfg p0.1 pin as EINT0 input pin
    CfgPortPinFunc(0,1,EINT0_PIN_0_1);
    
    //cfg VIC peripheral for EINT0
    //cfg EINT0 as irq type, def all are anyway irq
    //VICIntSelect=0;
    //Enable EINT0 via VIC
    VICIntEnable = 1<<EINT0_VIC_CHNO;
    //cfg EINT0 as v.irq,highest priority 0
    VICVectCntl0 = (1<<5) | EINT0_VIC_CHNO;
    //load eint0_isr address in hardware lut sfr for v.irq
    VICVectAddr0 = (u32)eint0_isr;
    //cfg External Interrupt peripheral
    //Enable EINT0,def all eint's are any enable
    //EXTINT = 0
    //cfg EINT0 for edge triggering
    EXTMODE = 1<<0;
    //cfg EINT0 for falling edge triggering,def FE anyway
    //EXTPOLAR = 0;
    //enter regular operations
    while(1){
        gCount++;
    }
}

void eint0_isr(void) __irq{
    //eint0 isr user activity begins
    //toggle EINT0 status led upon interrupt fired/raised
    IOPIN1 ^= 1<<EINT0_STATUS_LED;
    //eint0 isr user activity ends
    //clear EINT0 status in External Interrupt Peripheral 
    EXTINT = 1<<0;
    //clear EINT0 status in VIC peripheral
    VICVectAddr = 0;
}

