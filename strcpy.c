#include <stdio.h>

//summry
//ポインタを使った特殊なコピー
void my_strcpy(char *s,char *t){
   while(*s++ = *t++);
}

int main(){
    
    char str1[6];
    char str2[6]={"apple"};
    my_strcpy(str1,str2);
    printf("%s",str2);
    printf("%s",str1);
    return 0;
}