// #include<LPC21xx.h>
#include "arduino.h"
#include "arduino_defines.h"

main(){
    pinMode(7,OUTPUT);
    while(1){
        digitalWrite(7,digitalRead(0));
    }
}


