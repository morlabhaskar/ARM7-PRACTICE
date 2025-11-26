#include<LPC21xx.h>
#include<string.h>
#include "lcd.h"
#include "lcd_defines.h"
#include "types.h"
#include "rtc.h"
#include "delay.h"
#include "system_init.h"

#define ENTRY_SW 1 //@P0.0
#define EINT_SW 2  //@P0.1

s32 hour,min,sec,date,month,year,day,i;
main(){
    init_system();
    delay_ms(10);
    while(1){
        do{
            CmdLCD(GOTO_LINE1_POS0);
            StrLCD("   TIME GUARD   ");
            CmdLCD(GOTO_LINE2_POS0);
            StrLCD(" ACCESS SHIELD  ");
            delay_ms(1000);
            CmdLCD(0x01);
            while(1){
                // Set the initial time (hours, minutes, seconds)
	            SetRTCTimeInfo(00,00,00);
	            SetRTCDateInfo(27,11,2025);
	            SetRTCDay(4);
                // Get and display the current time on LCD
		        GetRTCTimeInfo(&hour,&min,&sec);
		        DisplayRTCTime(hour,min,sec);
		        GetRTCDateInfo(&date,&month,&year);
		        DisplayRTCDate(date,month,year);
		        GetRTCDay(&day);
		        DisplayRTCDay(day);
            }
        }while();
    }
}
