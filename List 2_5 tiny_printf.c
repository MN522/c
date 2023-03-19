#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void tiny_printf(char *format, ...){
    int i;
    va_list ap; //可変長仮引数(...)を保持する型

    va_start(ap, format);//formatの次以降のアドレスをポインタapに格納
    for(i = 0; format [i] !='\0'; i++){
        switch (format[i])
        {
        case 's':
            printf("%s ",va_arg(ap, char*));//apの示すアドレスを出力。apの示すアドレスはインクリメントされる
            break;
        case 'd':
            printf("%d ",va_arg(ap, int));
            break;
        default:
            break;
        }
    }
    va_end(ap);
    putchar('\n');
}



int main(void){
    tiny_printf("sdd", "result",3,5);
    return 0;
}