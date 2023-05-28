#ifndef WORD_MANAGE_P_H_INCLUDE
#define WORD_MANAGE_P_H_INCLUDE
#include "word_manage.h"

typedef struct 
{
    char *name;
    char count;
}Word;

#define WORD_NUM_MAX (10000)

extern Word word_arry[];
extern int num_of_word;

#endif 
