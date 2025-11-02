#include <LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "arduino.h"

#define OPINS      8  // LEDs connected from P0.8 to P0.15
#define TRIG_PIN   0  // Switch connected to P0.0

int main() {
    u32 cnt = 0;
    IODIR0 |= (0xFF << OPINS);  
    while (1) {
        if (((IOPIN0 >> TRIG_PIN) & 1) == 0) {
            cnt++;
            write2Pins(OPINS,8,0x0F^cnt);

            delay_ms(300); 
        }
    }
}
