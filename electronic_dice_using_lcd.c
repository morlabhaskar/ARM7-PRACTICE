#include "arduino.h"
#include "types.h"
#include "delay.h"
#include<stdlib.h>
#include "lcd_defines.h"
#include "lcd.h"
#define ROLL_SW 4
main(){
    u32 diceFace=0,seed;
    Init_LCD();
    StrLCD("Electronic Dice !");
	while(1){
        CmdLCD(GOTO_LINE2_POS0);
        U32LCD(diceFace);
        if(digitalRead(ROLL_SW)==0){
            diceFace=(rand()%6)+1;
            srand(seed++);
            delay_ms(5000);
        }
    }
}
