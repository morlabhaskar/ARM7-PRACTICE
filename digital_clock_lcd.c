#include "lcd_defines.h"
#include "lcd.h"
#include "delay.h"
#include "types.h"
main(){
    u8 hrs,min,sec;
    Init_LCD();
    StrLCD("DIGITAL CLOCK");
    while(1){
        for(hrs=0;hrs<24;hrs++){
            for(min=0;min<60;min++){
                for(sec=0;sec<60;sec++){
                    CmdLCD(GOTO_LINE2_POS0);
                    CharLCD((hrs/10)+48);
                    CharLCD((hrs%10)+48);
                    CharLCD(':');
                    CharLCD((min/10)+48);
                    CharLCD((min%10)+48);
                    CharLCD(':');
                    CharLCD((sec/10)+48);
                    CharLCD((sec%10)+48);
                    delay_ms(982);
                }
            }
        }
    }
}
