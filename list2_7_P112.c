#include <stdio.h>
#include <stdlib.h>
// free()したからといってもすぐに領域が破壊されるわけではない。
// 値が残っていて、次のmallocで破壊されることもある。
// この環境ではすぐに破壊されているようだが
int main(){
    
    int *int_p =malloc(sizeof(int));

    *int_p = 4321;
    printf("%d\n",*int_p);

    free(int_p);

    printf("%d\n",*int_p);

    int *int_p1 =malloc(sizeof(int));
    printf("%d\n",*int_p1);


    
}