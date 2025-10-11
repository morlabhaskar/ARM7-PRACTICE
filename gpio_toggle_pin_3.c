#include<LPC21xx.h>
#include "delay.h"

#define OPIN 7 //@P0.7 Pin

main(){
	//cfg P0.7 Pin as gpio pin
	IODIR0 |= 1<<OPIN;
	while(1){
		IOSET0 ^= 1<<OPIN;
		delay_ms(100);
	}
}