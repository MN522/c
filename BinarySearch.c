#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_S_SIZE 100000
#define MAX_T_SIXE 50000
bool reBinarySearch(int* pArry, int Target, int MinIndex, int MaxIndex);

int main(){
    //Data読み込み（空白がある長さ決まっている数列の読み込み）
    int S[MAX_S_SIZE];
    int n, q;
    int T[MAX_T_SIXE];
    char SBuf[MAX_S_SIZE];
    char TBuf[MAX_T_SIXE];

    scanf("%d",&n);
    int dt[128];
    int i=0,k,f;
    char *pSBuf=SBuf;
    char *pTBuf=TBuf;
    fgets(SBuf,MAX_S_SIZE*2,stdin);//前行の不要な改行を捨てる
    fgets(SBuf,MAX_S_SIZE*2,stdin);//fgetsはscnafの入力が標準入力ではなく文字列配列になったVer
    while(i < n){
        f=sscanf(pSBuf,"%d",&k);
        S[i] = k;
        i++;
        while(*pSBuf != ' ')pSBuf++;
        pSBuf++;
    }

    scanf("%d",&q);
    i=0;
    fgets(TBuf,MAX_S_SIZE*2,stdin);//前行の不要な改行を捨てる
    fgets(TBuf,MAX_S_SIZE*2,stdin);
    while(i < q){
        f=sscanf(pTBuf,"%d",&k);
        T[i] = k;
        i++;
        while(*pTBuf != ' ')pTBuf++;
        pTBuf++;
    }

    //2分探索
    int Mid, MidIndex;
    int MinIndex, MaxIndex;
    int Target;
    int Cnt = 0;
    for(int i = 0; i < q; i++){
        
        Target = T[i];
        MinIndex = 0;
        MaxIndex = n-1;
        if(reBinarySearch(S,Target, MinIndex, MaxIndex)){
                Cnt++;
        }
    }
    printf("%d",Cnt);
    return 0;
} 

bool reBinarySearch(int* pArry, int Target, int MinIndex, int MaxIndex){

    int MidIndex,Mid;
    MidIndex = (MinIndex + MaxIndex)/2;
    Mid = pArry[MidIndex];

    if(Target == pArry[MidIndex] || Target == pArry[MidIndex+1]){
        return true;
    }
    else if(MinIndex == MaxIndex){//続き。ヒットしないパターン
        return false;
    }
    else if(Target < Mid){
        MinIndex = 0;
        MaxIndex = MidIndex;
        return reBinarySearch(pArry, Target, MinIndex, MaxIndex);
    }else {
        MinIndex = MidIndex;
        MaxIndex = MaxIndex;
        return reBinarySearch(pArry, Target, MinIndex, MaxIndex);

    }

}