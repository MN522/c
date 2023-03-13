#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_S_SIZE 100000
#define MAX_T_SIXE 50000
bool reBinarySearch(int* pArry, int Target, int LeftIndex, int RightIndex);

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
        while(*pSBuf != ' '){
            pSBuf++;
            if (*pTBuf == '\n'){
                break;
                }
            }
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
        while(*pTBuf != ' '){
            pTBuf++;
            if (*pTBuf == '\n'){
                break;
                }
            }
        pTBuf++;
        
    }

    //2分探索
    int Mid, MidIndex;
    int LeftIndex, RightIndex;
    int Target;
    int Cnt = 0;
    for(int i = 0; i < q; i++){
        
        Target = T[i];
        LeftIndex = 0;
        RightIndex = n;
        if(reBinarySearch(S,Target, LeftIndex, RightIndex)){
                Cnt++;
        }
    }
    printf("%d\n",Cnt);
    return 0;
} 

bool reBinarySearch(int* pArry, int Target, int LeftIndex, int RightIndex){

    int MidIndex,Mid;
    MidIndex = (LeftIndex + RightIndex)/2;
    Mid = pArry[MidIndex];

    if(Target == pArry[MidIndex]){
        return true;
    }
    else if(LeftIndex == RightIndex){//ヒットしないパターン
        return false;
    }
    else if(Target <= Mid){ 
        LeftIndex = 0;
        RightIndex = MidIndex;
        return reBinarySearch(pArry, Target, LeftIndex, RightIndex);
    }else {
        LeftIndex = MidIndex+1;
        RightIndex = RightIndex;
        return reBinarySearch(pArry, Target, LeftIndex, RightIndex);

    }

}