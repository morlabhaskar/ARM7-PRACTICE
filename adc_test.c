#include "adc.h"
#include "types.h"

u32 adcDval;
f32 eAR;
main(){
    Init_ADC();
    while(1){
        Read_ADC(0,&adcDval,&eAR);
    }
}
