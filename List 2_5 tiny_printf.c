#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void tiny_printf(char *format, ...){
    int i;
    va_list ap; //可変長仮引数(...)を保持する型

    va_start(ap, format);//formatの次以降をapに格納
    for(i = 0; format [i] !='\0'; i++){
        switch (format[i])
        {
        case 's':
            printf("%s ",va_arg(ap, char*));
            break;
        
        default:
            break;
        }
    }
}

int main(void){
    tiny_printf("s", "sesulr");
    return 0;
}