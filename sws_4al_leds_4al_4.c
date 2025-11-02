#include "arduino_defines.h"
#include "arduino.h"
#include "types.h"
#include "LPC21xx.h"
#define SW1_AL 4
#define SW2_AL 5
#define SW3_AL 6
#define SW4_AL 7

#define LED1_AL 8
#define LED2_AL 9
#define LED3_AL 10
#define LED4_AL 11
//2AH LEDs 2AL LEDs
int main(){
    u32 i;
    for(i=0;i<4;i++){
        pinMode(LED1_AL+i,OUTPUT);
    }
    while(1){
        for(i=0;i<4;i++){
            if(i<2){
                digitalWrite(LED1_AL+i,!digitalRead(SW1_AL+i));
            }
            else{
                digitalWrite(LED1_AL+i,digitalRead(SW1_AL+i));
            }
        }
    }
}
