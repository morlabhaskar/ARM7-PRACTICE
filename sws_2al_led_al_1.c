#include "arduino_defines.h"
#include "arduino.h"
#define SW1_AL 4
#define SW2_AL 5

#define LED_AL 8

main(){
    pinMode(LED_AL,OUTPUT);
    while(1){
        digitalWrite(LED_AL,(digitalRead(SW1_AL)&digitalRead(SW2_AL)));
    }
}
