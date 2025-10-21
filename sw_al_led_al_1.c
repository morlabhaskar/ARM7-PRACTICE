#include "arduino_defines.h"
#include "arduino.h"
#define SW_AL 4    //@p0.4
#define LED_AL 8   //@p0.8

main(){
    pinMode(LED_AL,OUTPUT);
    while(1){
        digitalWrite(LED_AL,digitalRead(SW_AL));
    }
}
