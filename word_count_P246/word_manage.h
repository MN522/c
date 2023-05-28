#ifndef WORD_MANAGE_H_INCLUDE
#define WORD_MANAGE_H_INCLUDE
#include <stdio.h>

void word_initilize(void);
void add_word(char *word);
void dump_word(FILE *fp);
void word_finalize(void);

#endif