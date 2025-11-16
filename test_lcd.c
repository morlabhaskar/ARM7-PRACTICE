#include "lcd_defines.h"
#include "lcd.h"
#include "arduino.h"
#include "arduino_defines.h"
#include "delay.h"
cu8 cgramLUT[]={0x1D,0x05,0x05,0x1F,0x14,0x17,0x00};
int main(void){
	//int i;
    Init_LCD();
    delay_ms(50);

    // 1) Try to display "Bhaskar"
    StrLCD("I LOVE");
    delay_ms(1000);
    CmdLCD(CLEAR_LCD);
		CmdLCD(GOTO_LINE1_POS0);
		StrLCD("India");
    delay_ms(1000);
    CmdLCD(CLEAR_LCD);
    BuildCGRAM((u8*)cgramLUT,8);

    // 2) If still blank, write full-block characters to force display:
    // Write 16 characters 0xFF (some modules interpret 0xFF as solid block)
    //for(i=0;i<16;i++){
      //  CharLCD(0xFF);
    //}

    while(1);
}
