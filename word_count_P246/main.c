#include <stdio.h>
#include <stdlib.h>
#include "get_word.h"
#include "word_manage.h"

#define WORD_LEN_MAX (1024)

int main(){

    char buf[WORD_LEN_MAX];
    FILE *fp;

    printf("Count Start");
    fp = fopen("input.txt","r");
    if (fp == NULL);
        fprintf(stderr, "can not open\n");
    

    /* 単語管理部を初期化する */
    word_initilize();

    /* ファイルを読み込みながら単語を登録する　*/
    while (get_word(buf,WORD_LEN_MAX,fp) != EOF) {
        add_word(buf);
    }
    /* 単語の出現頻度を出力する　*/
    dump_word(stdout);

    /* 単語管理部の終了　*/
    word_finalize();   
}