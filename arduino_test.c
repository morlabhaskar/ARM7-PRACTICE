// #include<LPC21xx.h>
#include "arduino.h"
#include "arduino_defines.h"

main(){
    // pinMode(7,OUTPUT);
    portMode(8,8,OUTPUT);
    while(1){
        // digitalWrite(7,digitalRead(0));
        write2Pins(8,8,readPins(0,8));
    }
}


