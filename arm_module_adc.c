#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "adc.h"
#include "arduino.h"
#include "adc_defines.h"
#include "lcd_defines.h"
#include "lcd.h"

u32 adcVal;
f32 analog;
int main(){
    Init_LCD();
    Init_ADC();
    Read_ADC(0,&adcVal,&analog);
    CmdLCD(GOTO_LINE1_POS0);
    StrLCD("adcVal : ");
    CmdLCD(GOTO_LINE1_POS0+9);
    U32LCD(adcVal);
    CmdLCD(GOTO_LINE2_POS0);
    StrLCD("adcVtg : ");
    CmdLCD(GOTO_LINE2_POS0+9);
    F32LCD(analog,2);
    CmdLCD(GOTO_LINE2_POS0+13);
    CharLCD('v');
}
