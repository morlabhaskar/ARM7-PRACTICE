#include "seg.h"
#include "arduino.h"
#include "types.h"
#include "delay.h"
#include <stdlib.h>
#define ROLL_SW  4
main(){
    u32 diceFace=0,seed;
    init_2_mux_segs();
    while(1){
        disp_2_mux_segs(diceFace);
        if(digitalRead(ROLL_SW)==0){
            diceFace=(rand()%6)+1;
            srand(seed++);
            delay_ms(50);
        }
    }
}
