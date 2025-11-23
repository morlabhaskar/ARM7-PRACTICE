#include <LPC21xx.h>
#include <string.h>
#include "types.h"
#include "delay.h"
#include "arduino.h"
#include "arduino_defines.h"
#include "lcd_defines.h"
#include "kpm_defines.h"
#define GLED 4
#define RLED 5
// cu8 cgramLUT[]={0x1D,0x05,0x05,0x1F,0x14,0x17,0x00};
cu8 passwordLUT[]={0x0E,0x11,0x11,0x1F,0x1B,0x1B,0x1F,0x00};

//lcd
void WriteLCD(u8 byte){
    //select write operations
    digitalWrite(LCD_RW,0);//17
    //write byte on the data
    write2Pins(LCD_DATA,8,byte);
    //provide high to low pulse for latching
    digitalWrite(LCD_EN,1);//18
    delay_us(1);
    digitalWrite(LCD_EN,0);
    delay_ms(2);
}
void CmdLCD(u8 cmdByte){
    //select cmd register
    digitalWrite(LCD_RS,0);//16
    //write on cmd register via data pins
    WriteLCD(cmdByte);
}
void Init_LCD(void){
    //cfg lcd data pins and 3 control pins as gpio out
    portMode(LCD_DATA,11,OUTPUT);//8
    //power on delay
    delay_ms(15);
    //initialize start
    CmdLCD(MODE_8BIT_1LINE);
    delay_us(4100);
    CmdLCD(MODE_8BIT_1LINE);
    delay_us(100);
    CmdLCD(MODE_8BIT_1LINE);
    CmdLCD(MODE_8BIT_2LINE);
    CmdLCD(DSP_ON_CUR_OFF);
    CmdLCD(CLEAR_LCD);
    CmdLCD(SHIFT_CUR_RIGHT);
}
void CharLCD(u8 ascii){
    //select data register
    digitalWrite(LCD_RS,1);//16
    //write to DDRAM / display via data register
    WriteLCD(ascii);
}
void StrLCD(s8 *p){
    while(*p){
        CharLCD(*p++);
    }
}
void U32LCD(u32 n){
    u8 digit[10];
    s32 i=0;
    if(n==0) CharLCD('0');
    else{
        while(n>0){
            digit[i++]=(n%10)+48;
            n/=10;
        }
        for(--i;i>=0;i--){
            CharLCD(digit[i]);
        }
    }
}
void BuildCGRAM(u8 *p,u8 nBytes){
    u32 i;
    //point to CGRAM start
    CmdLCD(GOTO_CGRAM_START);//0x40
    //select data register
    digitalWrite(LCD_RS,1);
    //write to CGRAM , required bytes for custom char
    for(i=0;i<nBytes;i++){
        WriteLCD(p[i]);
    }
}

//kpm
// u32 kpmLUT[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
u32 kpmLUT[4][4]={{'7','8','9','/'},{'4','5','6','x'},{'1','2','3','-'},{'C','0','=','+'}};
void Init_KPM(void){
    //rows output & grounded
    IODIR1 |= 15<<ROW0;
    //cols input & high, any by default
}
u32 ColScan(void){
    u32 status;
    status = (((IOPIN1>>COL0)&15)<15) ? 0 : 1;
    return status;
}
u32 RowCheck(void){
    u32 r;
    for(r=0;r<=3;r++){
        //starting with row0,upto row3
        IOPIN1 = ((IOPIN1 &~(15<<ROW0))|(~(1<<r)<<ROW0));
        //check if key was pressed in that row
        if(ColScan()==0){
            break;
        }
    }
    //re-initialize rows to their state
    IOCLR1 = 15<<ROW0;
    return r;
}
u32 ColCheck(void){
    u32 c;
    for(c=0;c<=3;c++){
        //starting with col0,upto col3
        //check one col at a time for low
        if(((IOPIN1>>(COL0+c))&1)==0){
            break;
        }
    }
    return c;
}
u32 KeyScan(void){
    u32 r,c,keyV;
    //Initialize KPM
    Init_KPM();
    //wait for any key press detection
    while(ColScan());
    //upon key press detection
    //identify row in which key is pressed
    r=RowCheck();
    //identify col in which key is pressed
    c=ColCheck();
    //extract key value from LUT
    keyV = kpmLUT[r][c];
    return keyV;
}
cu8 pass[6]={'1','2','3','4','5','6'};
u8 password[6];
u32 key,i;
main(){
    Init_LCD();
    delay_ms(10);
    BuildCGRAM((u8*)passwordLUT,8);
    CmdLCD(GOTO_LINE1_POS0);
    CharLCD(0);
    CmdLCD(GOTO_LINE1_POS0+2);
    StrLCD("ENTER PASSWORD");
    CmdLCD(GOTO_LINE2_POS0+5);
    while(i<6){
        key=KeyScan();// wait until a key is pressed
        if(key>='0' && key<='9'){
            password[i]=key;
            // CharLCD(key);
            CharLCD('*');
            i++;
        }
        else if(key=='C'){
            i--;
            password[i]='\0';
            CmdLCD(GOTO_LINE2_POS0+5+i);
            CharLCD(' ');
            CmdLCD(GOTO_LINE2_POS0+5+i);
        }
        while(ColScan()==0);// wait until key is released
    }
    IODIR0 |= (1<<GLED) | (1<<RLED); 
    IOCLR0 = (1<<GLED) | (1<<RLED); 
    if(strcmp(pass,password)==0){
        IOSET0 = 1<<GLED;
        CmdLCD(GOTO_LINE2_POS0);
        StrLCD("CORRECT PASSWORD");
    }
    else{
        IOSET0 = 1<<RLED;
        CmdLCD(GOTO_LINE2_POS0);
        StrLCD("WRONG PASSWORD");
    }

    while(1);
}
