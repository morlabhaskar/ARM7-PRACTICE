#include "lcd_defines.h"
#include "lcd.h"
#include "arduino.h"
#include "types.h"
#define TRIG_SW 4
u32 time=0,flag=0,dly;
main(){
    Init_LCD();
    StrLCD("SECs STOP WATCH : ");
    while(1){
        CmdLCD(GOTO_LINE2_POS0);
        U32LCD(time);
        while(digitalRead(TRIG_SW)==0){
            flag=1;
        }
        while(flag==1){
            dly=1000000;
            while(dly--){
                if(digitalRead(TRIG_SW)==0){
                    break;
                }
            }
            CmdLCD(GOTO_LINE2_POS0);
            U32LCD(time);
            while(digitalRead(TRIG_SW)==0){
                flag=2;
            }
            if(flag!=2) time++;
            if(time>59){
                time=0;
                CmdLCD(GOTO_LINE2_POS0);
                StrLCD(" ");
            }
        }
        while(flag==2){
            while(digitalRead(TRIG_SW)==0){
                time=flag=0;
                CmdLCD(GOTO_LINE2_POS0);
                StrLCD(" ");
                CmdLCD(GOTO_LINE2_POS0);
                U32LCD(time);
            }
        }
    }
}

