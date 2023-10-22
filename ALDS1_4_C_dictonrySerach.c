#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define COMMAND_LEN 10
#define STR_LEN 12 + 1
#define DIC_MAX 10003
//ダブルハッシュ法用の定数
#define HASH_PRIME 3
//MMH用の定数
#define MMH_CONST1 0xcc9e2d51
#define MMH_CONST2 0x1b873593
#define MMH_CONST3 0xe6546b64
#define MMH_CONST4 0x85ebca6b
#define MMH_CONST5 0xc2b2ae35
#define MMH_SEED 42
//#define DEBUG

void InitDubleArrayChar(int NumRows, int NumCols, char dArry[][NumCols]);
bool CommandInsert(char dArry[][STR_LEN], const char Str[]);
void CommandFind(char dArry[][STR_LEN], const char Str[]);
unsigned int GenMurmurhash3Key(const char Str[], int len, unsigned int seed);
unsigned int GenDoubleHashKey(const char Str[], int NumCollisions);
unsigned long long GenBaseKey(const char Str[]);
unsigned int GetCharNum(char ch);
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
        //ダブルハッシュ法でハッシュ値を算出
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

//murmurhash法でハッシュ値を求める
unsigned int GenMurmurhash3Key(const char Str[], int len, unsigned int seed){
    const unsigned char *Data = (const unsigned char *)Str;
    const int nBlocks = len / 4;

    unsigned int h1 = seed;

    //4byteずづキーを生成する
    for(int i = 0; i < nBlocks; i++){
        unsigned int Chunk;
        memcpy(&Chunk, Data + (i * 4), sizeof(unsigned int));
        
        Chunk *= MMH_CONST1;
        Chunk = (Chunk << 15 ) | (Chunk >> 17);
        Chunk *= MMH_CONST2;

        h1 ^= Chunk;
        h1 = (h1 << 13) | (Chunk >> 19);
        h1 = h1 * 5 + MMH_CONST3;
    }

    //最後のブロックが4byte未満だったら専用の処理が必要
    const unsigned char *tail = (const unsigned char*)(Data + nBlocks * 4);
    unsigned int k1 = 0;
    switch (len & 0x3)
    {
    case 3:
        //余り3
        k1 ^=tail[2] << 16;
        break;
    case 2:
        //余り2
        k1 = tail[1] << 8;
        break;
    case 1:
        //余り1
        k1 ^= tail[0];
        k1 *= MMH_CONST1;
        k1 = (k1 << 15) | (k1 >> 17);
        k1 *= MMH_CONST2;
        h1 ^= k1;
        break;
    default:
        break;
    }

    //締めの処理
    h1 ^= len;
    h1 ^= h1 >> 16;
    h1 *= MMH_CONST4;
    h1 ^= h1 >> 13;
    h1 *= MMH_CONST5;
    h1 ^= h1 >> 16;

    return h1; 
}

//ダブルハッシュ法でハッシュ値を求める
unsigned int GenDoubleHashKey(const char Str[], int NumCollisions){
    unsigned int HashKey = 0;
    unsigned int ASCIISum = 0;
    unsigned int BaseKey = 0;

    BaseKey = GenBaseKey(Str);
    HashKey = (GenHashKey1(Str) + (NumCollisions * GenHashKey2(Str))) % DIC_MAX;
    
    return HashKey;
}

//文字列からベースとなる一意のキーを求める
unsigned long long GenBaseKey(const char Str[]){
    long long sum = 0;
    long long p = 0;
    long long i = 0;

    for(i = 0; i<strlen(Str); i++){
        sum += p * GetCharNum(Str[i]);
        p *= 5;
    }
}

//文字から数値に変換
unsigned int GetCharNum(char ch){
    switch (ch)
    {
    case 'A':
        return 1;
    case 'C':
        return 2;
    case 'G':
        return 3;
    case 'T':
        return 4;
    default:
        return 0;
    }
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