#include <stdio.h>
#include <stdlib.h>

//summry
//いろんなアドレスの表示

//topic:static
/*ファイル内static = 他のファイルから読めない
ローカル内static = ローカルをでても値が保持される。もう一度このローカルに来たら保持された値を使える*/

//topic:スタックメモリ
/*自動変数のアドレスだけ離れた場所にあることが分かる。それがスタック領域*/

int glocal_variavle=10;
static int global_static_variavlel=99;

void func1(void){
    int func1_variavle;
    static int func1_static_variable;

    printf("&func1_variavle..%p\n",&func1_variavle);
    printf("&func1_static_variable%p\n",&func1_static_variable);

}



void func2(void){
    int func2_variavle;

    printf("&func2_variavle %p\n",&func2_variavle);

}

int main(void){
    int *p;

    //関数へのポインタ表示
    printf("func1 %p\n",func1);
    printf("func2 %p\n",func2);

    //文字列リテラルのアドレスの表示
    printf("string litral %p\n","abc");

    //グローバル変数のアドレス表示
    printf("global_variavle %p\n",&glocal_variavle);

    //ファイル内のstatic変数のアドレスを表示
    printf("global_static_variavle %p\n",&global_static_variavlel);

    //ローカル変数の表示
    func1();
    func2();

    //mallocにより確保した領域の＾アドレス
    p=(int*)malloc(sizeof(int));
    printf("malloc address %p\n",p);

    return 0;

}


