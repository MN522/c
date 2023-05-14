#include <stdio.h>

int main()
{
    int (*ptr_ary1)[3];//要素2の配列のポインタ -> 二次元配列可能

    int double_arry[2][3]={{1,2,3},{4,5,6}};
 
    

    for (int i=0 ; i<1 ; i++){
            ptr_ary1 = double_arry[i];
        }
    

     for (int i=0 ; i<3 ; i++){
            //%p ポインタ型を16進数で表示
            //%x Unsigned　Intを16進数で表示

            printf("1, %p\n", ptr_ary1);
            printf("2 未定義, %p\n", ptr_ary1[i]);
            printf("3, %p\n", (*ptr_ary1)+i);
            printf("3.1, %d\n", *((*ptr_ary1)+i));
            printf("4未定義, %p\n", *ptr_ary1+i);
            printf("5, %p\n", (*ptr_ary1+i));
            printf("5.1, %d\n", (*ptr_ary1+i));
            printf("6, %d\n", *ptr_ary1[i]);
            printf("7, %d\n ",(*ptr_ary1)[i]);
        
        printf("\n");
    }
    
} 