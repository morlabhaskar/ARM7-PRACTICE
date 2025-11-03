#include "arduino.h"
#include "arduino_defines.h"
#include "types.h"
#include "delay.h"
#include "seg_defines.h"
cu8 segLUT[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void init_2_mux_segs(void){
    portMode(CA7SEG_2_MUX_PINS,10,OUTPUT);
}

void disp_2_mux_segs(u8 num){
    write2Pins(CA7SEG_2_MUX_PINS,8,segLUT[num/10]);
    digitalWrite(DSEL1,1);
    delay_ms(1);
    digitalWrite(DSEL1,0);

    write2Pins(CA7SEG_2_MUX_PINS,8,segLUT[num%10]);
    digitalWrite(DSEL2,1);
    delay_ms(1);
    digitalWrite(DSEL2,0);
}
