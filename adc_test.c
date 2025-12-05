#include "adc.h"
#include "types.h"
#include "lcd.h"
#include "lcd_defines.h"

u32 adcDval;
f32 eAR;
main(){
    Init_ADC();
    Init_LCD();
    while(1){
        Read_ADC(0,&adcDval,&eAR);
        CmdLCD(GOTO_LINE1_POS0);
        StrLCD("ADC = ");
        CmdLCD(GOTO_LINE1_POS0+7);
        U32LCD(adcDval);
        CmdLCD(GOTO_LINE2_POS0);
        StrLCD("VOLTAGE = ");
        CmdLCD(GOTO_LINE2_POS0+11);
        F32LCD(eAR,3);
    }
}




