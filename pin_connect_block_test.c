#include "pin_connect_block.h"
#include "pin_functions_defines.h"

main(){
    //cfg P0.0 for function 4
    CfgPortPinFunc(0,0,RSVD_0_0);
    //cfg P0.0 for function 3
    //CfgPortPinFunc(0,0,PWM1_0_0);
    //cfg P0.0 for function 2
    //CfgPortPinFunc(0,0,TXDO_0_0);
    //cfg P0.0 for function 1
    //CfgPortPinFunc(0,0,GPIO_0_0);
}
