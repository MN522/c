#include <stdio.h>
#include <string.h>

void cpy(char* dst, char* src){
    *dst = *src;
}

// srcのさす先（文字列）がRO
void const_cpy(char *dst, char const *src){
    src = NULL;
    dst = src;
}

void const_ptr_cpy(char *dst, char * const src){
    //src = NULL;
    dst = src;
}
int main(void){

    char *s1 = "hello";  // ポインタ変数 s1 を宣言し、"hello" の先頭アドレスを割り当てる
    char *s2 = "world";  // ポインタ変数 s2 を宣言し、"world" の先頭アドレスを割り当てる
    
    char ss1[] = "hello";  // 文字列を格納するための配列 ss1 を宣言し、"hello" のコピーを格納する
    char ss2[] = "world";  // 文字列を格納するための配列 ss2 を宣言し、"world" のコピーを格納する
    
    printf("s1=%s\n",s1);
    printf("s2=%s\n",s2);

    cpy(ss1, ss2);
    printf("s1=%s\n",s1);
    printf("s2=%s\n",s2);
    
    strcpy(ss1, ss2);
    printf("s1=%s\n",ss1);
    printf("s2=%s\n",ss2);
    
    return 0;
}