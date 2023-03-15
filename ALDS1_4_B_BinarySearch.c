#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_S_SIZE 100005
#define MAX_T_SIXE 50000
bool reBinarySearch(int* pArry, int Target, int LeftIndex, int RightIndex);

int main(){
    int n, q, t;
    int S[MAX_S_SIZE];
    int T[MAX_T_SIXE];

    //Data読み込み（空白がある長さ決まっている数列の読み込み）
    scanf("%ld",&n);
    for(int i = 0 ; i < n; i++){
        scanf("%ld",&S[i]);
    }

    scanf("%ld",&q);
    for(int i = 0 ; i < q; i++){
        scanf("%ld",&T[i]);
    }

    //2分探索
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