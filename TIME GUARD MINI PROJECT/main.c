#include<LPC21xx.h>
#include<string.h>
#include "lcd.h"
#include "lcd_defines.h"
#include "types.h"
#include "rtc.h"
#include "kpm.h"
#include "delay.h"
#include "arduino.h"
#include "system_init.h"

#define ENTRY_SW 0 //@P0.0
#define EINT_SW 1  //@P0.1
cu8 UserCGRAM[8][8] = {
    {0x0E,0x11,0x11,0x1F,0x1B,0x1B,0x1F,0x00}, // Lock
    {0x04,0x0E,0x0E,0x0E,0x1F,0x00,0x00,0x00}, // Key
    {0x1F,0x11,0x15,0x1B,0x00,0x00,0x00,0x00}, // Backspace
    {0x01,0x03,0x16,0x1C,0x08,0x00,0x00,0x00}, // Checkmark
    {0x1B,0x0E,0x04,0x0E,0x1B,0x00,0x00,0x00}, // Wrong
    {0x04,0x06,0x1F,0x06,0x04,0x00,0x00,0x00}, // Arrow
    {0x04,0x0E,0x0E,0x04,0x00,0x04,0x00,0x00}  // Warning
};
u8 password[] = "1234",pass[10];
u32 key,i;

void display_title(){
    CmdLCD(GOTO_LINE1_POS0);
    StrLCD("   TIME GUARD   ");
    CmdLCD(GOTO_LINE2_POS0);
    StrLCD(" ACCESS SHIELD  ");
    delay_ms(1000);
    CmdLCD(CLEAR_LCD);
}
s32 hour,min,sec,date,month,year,day;
void display_RTC(){
    while(digitalRead(ENTRY_SW) && digitalRead(EINT_SW)){
        
        // Get and display the current time on LCD
	    GetRTCTimeInfo(&hour,&min,&sec);
	    DisplayRTCTime(hour,min,sec);

	    GetRTCDateInfo(&date,&month,&year);
	    DisplayRTCDate(date,month,year);

	    GetRTCDay(&day);
	    DisplayRTCDay(day);
        delay_ms(500);
    }
}
u32 chack_password(){
    i = 0;
    memset(pass, 0, sizeof(pass));
    BuildCGRAM((u8 *)UserCGRAM[0], 8);
    CmdLCD(GOTO_LINE1_POS0);
    CharLCD(0);
    CmdLCD(GOTO_LINE1_POS0 + 2);
    StrLCD("ENTER PASSWORD");
    CmdLCD(GOTO_LINE2_POS0 + 5);
    while(i<4){
        key = KeyScan();//for key press
        if(key >= '0' && key <= '9'){
            pass[i] = key;
            // CharLCD(key);
            CharLCD('*');
            i++;
        }
        else if(key == 'C'){
            i--;
            pass[i]='\0';
            CmdLCD(GOTO_LINE2_POS0+5+i);
            CharLCD(' ');
            CmdLCD(GOTO_LINE2_POS0+5+i);
        }
        pass[i]='\0';
        while(ColScan()==0);//wait for key release
    }
    if(strcmp(password,pass)==0){
        CmdLCD(CLEAR_LCD);
        BuildCGRAM((u8 *)UserCGRAM[3], 8);
        CmdLCD(GOTO_LINE1_POS0);
        CharLCD(0);
        CmdLCD(GOTO_LINE1_POS0 + 2);
        StrLCD("LOGIN SUCCESS   ");
        CmdLCD(GOTO_LINE2_POS0);
        StrLCD("WAIT 2 SECONDS     ");
        delay_ms(2000);
        return 1;
    }
    else{
        CmdLCD(CLEAR_LCD);
        BuildCGRAM((u8*)UserCGRAM[4],8);
        CmdLCD(GOTO_LINE1_POS0);
        CharLCD(0);
        CmdLCD(GOTO_LINE1_POS0 + 2);
        StrLCD("WRONG PASSWORD  ");
        delay_ms(2000);
        return 0;
    }
}

main(){
    init_system();
    delay_ms(10);
    IODIR0 &= ~((1<<ENTRY_SW) | (1<<EINT_SW));

    // Set the initial time (hours, minutes, seconds)
	SetRTCTimeInfo(00,00,00);
	SetRTCDateInfo(27,11,2025);
	SetRTCDay(4);


    while(1){
        do{
            display_title();
            display_RTC();
        }while(digitalRead(ENTRY_SW) && digitalRead(EINT_SW));
        CmdLCD(CLEAR_LCD);
        //for entry switch
        if(digitalRead(ENTRY_SW)==0){
            u32 count=0,fail=0;
            while(count<3){
                u32 status = chack_password();
                if(status==1){
                    break;
                }
                CmdLCD(CLEAR_LCD);
                BuildCGRAM((u8*)UserCGRAM[6],8);
                CmdLCD(GOTO_LINE1_POS0);
                CharLCD(0);
                CmdLCD(GOTO_LINE1_POS0+2);
                StrLCD("TRY AGAIN");
                delay_ms(1000);
                count++;
            }
            if(count==3) fail=1;
            if(fail){
                CmdLCD(CLEAR_LCD);
                StrLCD("LIMIT EXCEEDED ");
            }else{
                BuildCGRAM((u8 *)UserCGRAM[3], 8);
                CmdLCD(GOTO_LINE1_POS0);
                CharLCD(0);
                CmdLCD(GOTO_LINE1_POS0 + 2);
                StrLCD("LOGIN SUCCESS   ");
            }
            
            
            
        }
        //for interrupt switch
        else if(digitalRead(EINT_SW)==0){
            CmdLCD(GOTO_LINE1_POS0);
            StrLCD("INTERRUPT MODE");
            delay_ms(2000);
        }
        while(1);
    }
}
