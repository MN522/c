#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define COMMAND_LEN 10
#define STR_LEN 12 + 1
#define DIC_MAX 1000003
#define HASH_PRIME 3
//#define DEBUG

void InitDubleArrayChar(int NumRows, int NumCols, char dArry[][NumCols]);
bool CommandInsert(char dArry[][STR_LEN], const char Str[]);
void CommandFind(char dArry[][STR_LEN], const char Str[]);
unsigned int GenDoubleHashKey(const char Str[], int NumCollisions);
unsigned int GenHashKey1(const int key);
unsigned int GenHashKey2(const int key);
int main(){

    char Dic[DIC_MAX][STR_LEN]; 

    //辞書の初期化
    InitDubleArrayChar(DIC_MAX, STR_LEN, Dic);
    
    //命令数を受け取る
    int n;
    #ifdef DEBUG 
        //命令数を仮設定
        n = 2;
    #else
        scanf("%d",&n);
    #endif

    //命令を受け取る
    char Command[COMMAND_LEN], InputStr[STR_LEN];
    int i;
    for (i = 0; i < n; i++){
        #ifdef DEBUG
            //コマンドを仮設定
            if(i == 0){
                strcpy(Command, "insert");
                strcpy(InputStr, "AAAB");
            }else if(i == 1){
                strcpy(Command, "insert");
                strcpy(InputStr, "AABA");
            }
        #else
            scanf("%s %s", Command, InputStr);
        #endif
        //printf("Command: %s, String: %s\n", Command, InputStr);
        if (strcmp(Command, "insert") == 0){
            CommandInsert(Dic, InputStr);
        }else if(strcmp(Command, "find") == 0){
            CommandFind(Dic, InputStr);
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
bool CommandInsert(char dArry[][STR_LEN], const char Str[]){
    unsigned int HashKey = 0;
    int NumCollisions = 0;
    bool InsertDone = false;

    while (HashKey < DIC_MAX)
    {
        //ダブルハッシュ法でハッシュ値を算出
        HashKey = GenDoubleHashKey(Str, NumCollisions);
        if(strcmp(dArry[HashKey], Str) == 0){
            //既に文字列が辞書あれば格納しない
            return false;
        }else if(strlen(dArry[HashKey]) != 0){
            //空いてなかったらダブルハッシュ法の為に衝突回数をインクリメント
            NumCollisions++;
        }else{
            //空いてたら文字列を格納する
            strcpy(dArry[HashKey], Str);
            return true;
        }
    }

    printf("error\n");
    return false;
}

//辞書から文字列を探す
//あったら”Yes”なかったら”No”
void CommandFind(char dArry[][STR_LEN], const char Str[]){
    unsigned int HashKey = 0;
    int NumCollisions = 0;
    bool FindDone = false;

    while (true)
    {
        HashKey = GenDoubleHashKey(Str, NumCollisions);
        if(strcmp(dArry[HashKey],Str) == 0){
            //ハッシュ値の場所に探査文字列があった
            printf("yes\n");
            return;
        }else if (strlen(dArry[HashKey]) == 0){
            //ハッシュ値の場所が空なら辞書にないという事
            printf("no\n");
            return;
        }else{
        //他の文字列と衝突したらダブルハッシュ法の為に衝突回数をインクリメント
        NumCollisions++;
        }
    }
}

//ダブルハッシュ法でハッシュ値を求める
unsigned int GenDoubleHashKey(const char Str[], int NumCollisions){
    unsigned int HashKey = 0;
    unsigned int ASCIISum = 0;

    for(int j = 0; j < Str[j] != '\0'; j++){
        ASCIISum += Str[j];
    }
    HashKey = (GenHashKey1(ASCIISum) + (NumCollisions * GenHashKey2(ASCIISum))) % DIC_MAX;
    
    return HashKey;
}

//1つ目のハッシュ値を求める
unsigned int GenHashKey1(const int key){
    unsigned int HashKey = 0;
    HashKey = key % DIC_MAX;
    return HashKey;
}

//2つ目のハッシュ値を求める
unsigned int GenHashKey2(const int key){
    unsigned int HashKey = 0;
    HashKey = HASH_PRIME + (key % DIC_MAX - HASH_PRIME);
    return HashKey;
}