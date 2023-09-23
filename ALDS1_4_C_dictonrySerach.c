#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define COMMAND_LEN 10
#define STR_LEN 12 + 1
#define DIC_MAX 100
#define DEBUG

void InitDubleArrayChar(int NumRows, int NumCols, char dArry[][NumCols]);
void CommandInsert(char dArry[][STR_LEN], const char Str[]);

int main(){

    char Dic[DIC_MAX][STR_LEN]; 

    //辞書の初期化
    InitDubleArrayChar(DIC_MAX, STR_LEN, Dic);
    
    //命令数を受け取る
    int n;
    #ifdef DEBUG 
        //命令数を仮設定
        n = 1;
    #else
        scanf("%d",&n);
    #endif

    //命令を受け取る
    char Command[COMMAND_LEN], InputStr[STR_LEN];
    int i;
    for (i = 0; i < n; i++){
        #ifdef DEBUG
            strcpy(Command, "insert");
            strcpy(InputStr, "AAAA");
        #else
            scanf("%s %s", Command, InputStr);
        #endif
        printf("Command: %s, String: %s\n", Command, InputStr);
        if (strcmp(Command, "insert") == 0){
            CommandInsert(Dic, InputStr);
        }
    }

    return 0;
}

//文字型の二次元配列を0で初期化する
void InitDubleArrayChar(int NumRows, int NumCols, char dArry[][NumCols]){
    memset(dArry, 0, sizeof(char) * NumCols * NumRows);
}

//辞書の末尾に文字列を格納する。
//格納したらTrueを返す。既にあったらFalseを返す
void CommandInsert(char dArry[][STR_LEN], const char Str[]){
    int Pos = 0;
    bool FoundFlag = false;
    
    while(Pos < DIC_MAX){
        if(strcmp(dArry[Pos],Str) == 0){
            //既に同じ文字列があったら何もしない
            return false;
        }else if(strcmp(dArry[Pos],"") == 0){
            //配列の末尾だったら文字列を格納する
            strcpy(dArry[Pos], Str);
            return true;

        }
    }
    return false;
}