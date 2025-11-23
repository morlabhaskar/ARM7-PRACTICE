#include "types.h"
#include "delay.h"
#include "lcd_defines.h"
#include "lcd.h"
u8 name[]="               MORLA BHASKAR NANI";
main(){
    Init_LCD();
    StrLCD(name);
    while(1){
        CmdLCD(0x18);
        delay_ms(150);
    }
}


