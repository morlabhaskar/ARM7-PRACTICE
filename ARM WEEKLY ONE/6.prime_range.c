#include<LPC21xx.h>
#include "types.h"
#include "delay.h"
int is_prime(int num){
    s32 cnt=0,i;
    for(i=1;i<=num;i++){
        if(num%i==0){
            cnt++;
        }
    }
    if(cnt==2){
        return 1;
    }
    return 0;
}
int main(){
    s32 arr[20],min=0,max=50,len=0,i;
    IODIR0 |= ((1<<8)-1)<<8;
    for(i=min;i<=max;i++){
        if(is_prime(i)){
            arr[len]=i;
            len++;
        }
    }
    for(i=0;i<len;i++){
        // printf("%d\n",arr[i]);
        IOPIN0 = ((IOPIN0 & ~(((1<<8)-1)<<8)) | (arr[i]<<8));
        delay_ms(600);
    }
    while(1);
}
