#include "types.h"
#include "lcd_defines.h"
#include "adc_defines.h"
#include "delay.h"
#include "lcd.h"
#include <stdio.h>
#include <LPC21xx.h>
void Init_ADC(){
    //cfg p0.27 as AIN0 input pin
    // PINSEL1 = (PINSEL1 &~(3<<(27*2))) | (3<<(27*2));
    // PINSEL1 = (PINSEL1 & ~(3 << 22)) | (3 << 22);
    PINSEL1 = (PINSEL1 & ~(3 << 22)) | (3 << 22);

    //cfg ADCR
    ADCR = (1<<PDN_BIT) | (CLKDIV<<CLKDIV_BITS);
}
void Read_ADC(u32 chNo,u32 *adcVal,f32 *analogReading){
    //clear any previous channel select
    ADCR &= 0xFFFFFF00;
    //update with new required channel,&start conversion
    ADCR |= ((1<<chNo) | (1<<START_CONV_BIT)) ;
    //wait untill conversion time >=2.44 uS
    delay_us(3);
    //check status of conversion
    while(((ADDR>>DONE_BIT)&1)==0);
    //stop adc conversion
    ADCR &= ~(1<<START_CONV_BIT);
    //read the digital result after successful conversion
    *adcVal = ((ADDR>>RESULT_BITS)&1023);
    //convert to equivalent analog reading in volts
    *analogReading = *adcVal * (3.3/1024);
}
main(){
    u32 adcVal = 382;
    f32 eAr = 1.234;
    s8 volts[10];
    Init_ADC();
    Init_LCD();
    StrLCD("ADC TEST");
    while(1){
        Read_ADC(0,&adcVal,&eAr);
        sprintf(volts,"%0.3f",eAr);
        CmdLCD(GOTO_LINE2_POS0);
        U32LCD(adcVal);
        CmdLCD(GOTO_LINE2_POS0+8);
        StrLCD(volts);
        delay_ms(100);
        // CmdLCD(GOTO_LINE2_POS0);
        // StrLCD("                         ");
    }
}
