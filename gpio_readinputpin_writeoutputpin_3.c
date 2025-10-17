#include<LPC21xx.h>
#define OPIN 7
#define IPIN 0

main(){
    IODIR0 |= 1<<OPIN;
    while(1){
        IOPIN0=((IOPINO&~(1<<OPIN))|(((IOPIN0>>IPIN)&1)<<OPIN))
    }
}
