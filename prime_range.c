#include<LPC21xx.h>
#include<stdlib.h>
#include "types.h"
void input(int *ptr,int min,int max){
    ptr = realloc(ptr,sizeof(int));

}
int main(){
    int *arr=NULL,min=0,max=50;
    input(arr,min,max);
}