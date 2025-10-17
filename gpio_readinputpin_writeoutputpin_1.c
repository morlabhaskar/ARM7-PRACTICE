#include<LPC21xx.h>
#define OPIN 7
#define IPIN 0

main(){
    IODIR0 |= 1<<OPIN;
    while(1){
        if(((IOPIN0>>IPIN)&1)==1){
            IOSET0=1<<OPIN;
        }
        else{
            IOCLR0=1<<OPIN;
        }
				
    }
}
