#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define COMMAND_LEN 10
#define STR_LEN 12
#define ARY_SIZE 1000000

void Insert(char *ary[ARY_SIZE], int size){

}
int main(void){

    //入力を受け取る
    int n;
    char command[COMMAND_LEN], str[STR_LEN];
    scanf("%d",&n);

    int i;
    for (i = 0; i < n; i++){
        scanf("%s %s", command, str);
        printf("Command: %s, String: %s\n", command, str);
        if (command =="insert"){
            Insert(str);
        }
    }


}