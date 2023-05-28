#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage_p.h"

//indexより後方の要素を一つずつ後方にシフトする
static void shift_array(int index){
    int src;
    for (src = num_of_word -1; src >= index;src--){
        word_arry[src+1] = word_arry[src];
    }
    num_of_word++;
}

static char *my_strdup(char *src){
    char *dest;
    dest = malloc(sizeof(char) * (strlen(src)+1));
    strcpy(dest,src);
    return dest;
}

//単語を追加
void add_word(char *word){
    int i;
    int reslut;

    for (i = 0; i < num_of_word; i++){
        reslut = strcmp(word_arry[i].name, word);
        if(reslut >= 0)
            break;
    }if(num_of_word != 0 && reslut == 0){
        word_arry[i].count++;
    }else{
        shift_array(i);
        word_arry[i].name = my_strdup(word);
        word_arry[i].count = 1;
    }
}