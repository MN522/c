#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int get_word(char *buf, int buf_size, FILE *fp){
    int len;
    int ch;

    //空白文字の読みとばし
    while ((ch = getc(fp)) != EOF && !isalnum(ch));
    if (ch == EOF)
    return EOF;

    //chには最初の文字が格納されているはず
    len = 0;
    do{
        buf[len] = ch;
        len++;
        if(len >= buf_size){
            //単語長すぎエラー
            fprintf(stderr, "wrod too long\n");
            exit(1);
        }
    }while((ch = getc(fp)!=EOF && isalnum(ch)));
    buf[len] = '\0';

    return len;
}