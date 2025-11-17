#include "lcd_defines.h"
#include "lcd.h"
#include "delay.h"
cu8 cgramLUT[]={0x1D,0x05,0x05,0x1F,0x14,0x17,0x00};
main(){
    Init_LCD();
		delay_ms(10);
    //CharLCD('A');
    //StrLCD("V25HE2-EMD-C");
    // CmdLCD(GOTO_LINE2_POS0);
    // U32LCD(1234567890);
    // delay_ms(2000);
    // CmdLCD(CLEAR_LCD);
    // S32LCD(-78678766);
    // CmdLCD(GOTO_LINE2_POS0);
    // F32LCD(-123.564,6);
    // delay_ms(2000);
    //CmdLCD(CLEAR_LCD);
    BuildCGRAM((u8*)cgramLUT,8);
    CmdLCD(GOTO_LINE2_POS0);
    //CharLCD('0');
    CharLCD(0);
    while(1);
}
