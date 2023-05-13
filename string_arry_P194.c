#include <stdio.h>
#include <string.h>

int main(void){
    // 文字列リテラルも単なる配列なので、サイズがわかる
    printf("size = %d\n", sizeof("abcdef"));
    printf("size = %d", sizeof(""));

}