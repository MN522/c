#include <stdio.h>
#define ARYSIZE 10
int main(){
    int cnt = 10;
    int sum[ARYSIZE]={0};

    for (int i=1; i < ARYSIZE; i++){
        if((i==0) || (i==1)){
            sum[i]=i;
        }else{
        sum[i] = sum[i-1]+sum[i-2];
        }
    }

    for(int i=0; i<ARYSIZE ; i++){
        printf("%d ",sum[i]);
    }
}