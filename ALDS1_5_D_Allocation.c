#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_STUFF_SIZE 100000
#define MAX_TRACK_NUM 100000
# define MAX_P 1000000000

int GetStuffCap(int p, int w[], int k, int n);
int main(){

    // 問題文読み込み
    int n,k;
    int w[MAX_STUFF_SIZE];
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++){
        scanf("%d", w + i);
    }

    // 荷物の総量
    int Sum = 0;
    for (int i = 0; i < n; i++){
        Sum += w[i];
    }
    int MaxP = Sum;

    // n個の荷物が載りきるPを2分探索で探す。
    // Pが増加すれば乗り切る荷物の増加する性質を利用。
    // Pを0からインクリメントしていたら計算量が多すぎる。
    int LoadStuffSum = 0;
    int Left = 0;
    int Right = MaxP;
    int Mid =  (Left + Right) / 2;
    int P;

    while(Right - Left > 1){
        P = Mid;
        LoadStuffSum = GetStuffCap(P, w, k ,n);
        if (LoadStuffSum >= n){
            Right = Mid;
            Mid =  (Left + Right) / 2;
        }else{
            Left = Mid;
            Mid =  (Left + Right) / 2;
        }
    }
    printf("%d\n", Right);
    return 0;
}

// Pとkを入力として、何個の荷物が積載可能か返す
int GetStuffCap(int p, int w[], int k, int n){
    int WightSum = 0;
    int LoadStuffSum = 0; //積んだ荷物の数

    for (int i = 0; i < k; i++){
        WightSum = 0;
        for (int j = LoadStuffSum; j < n ;j++){
            WightSum += w[j];
            LoadStuffSum++;
            if(WightSum > p){
                //重量オーバーしてしまったので一個戻す
                LoadStuffSum--;
                break;
            }
        }
        // 全ての荷物が積載させたらTrueを返す。
        if (LoadStuffSum == n){
            return n;
        }
    }
    return LoadStuffSum;
} 