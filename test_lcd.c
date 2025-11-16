#include "lcd_defines.h"
#include "lcd.h"
#include "arduino.h"
#include "arduino_defines.h"
#include "delay.h"
int main(void){
	//int i;
    Init_LCD();
    delay_ms(50);

    // 1) Try to display "Bhaskar"
    StrLCD("I LOVE YOU");
    //delay_ms(1000);
		CmdLCD(GOTO_LINE2_POS0);
		StrLCD("KAPPALU");
    //delay_ms(1000);

    // 2) If still blank, write full-block characters to force display:
    // Write 16 characters 0xFF (some modules interpret 0xFF as solid block)
    //for(i=0;i<16;i++){
      //  CharLCD(0xFF);
    //}

    while(1);
}
