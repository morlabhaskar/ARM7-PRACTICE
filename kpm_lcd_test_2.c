#include "kpm.h"
#include "lcd_defines.h"
#include "lcd.h"
u32 key;
main(){
    Init_LCD();
    Init_KPM();
    StrLCD("KPM TEST");
    while(1){
        key=KeyScan();
        CmdLCD(GOTO_LINE2_POS0);
        StrLCD("  ");
        CmdLCD(GOTO_LINE2_POS0);
        U32LCD(key);
        while(ColScan()==0);
    }
}
