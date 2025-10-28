#include <LPC21xx.h>
#define SW1  4 // Switch @ P0.4
#define SW2  5  //Switch  @ P0.5
#define LED   8 //LED @ P0.8
main(){
      IODIR0 = 1 << LED;
      while (1){
          IOPIN0 = (( ( IOPIN0 >> SW1 ) & 1 )  &  ( ( IOPIN0 >> SW2 ) & 1 ) ) << LED ;
      }
}

