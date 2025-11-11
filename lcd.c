#include "types.h"
#include "delay.h"
#include "arduino_defines.h"
#include "arduino.h"
#include "lcd_defines.h"

void WriteLCD(u8 byte){
    //select write operations
    digitalWrite(LCD_RW,0);
    //write any byte onto data pins(d0-d7)
    write2Pins(LCD_DATA,8,byte);
    //provide high to low pulse for latching
    digitalWrite(LCD_EN,1);
    delay_us(1);
    digitalWrite(LCD_EN,0);
    //byte between byte time
    delay_ms(2);
}
void Init_LCD(void);
void CmdLCD(u8);
void CharLCD(u8);

void StrLCD(s8*);
void U32LCD(u32);
void S32LCD(s32);
void F32LCD(f32,u32);
void BuildCGRAM(u8*,u8);

