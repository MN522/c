#include <stdio.h>

//summry
//演算優先度

//topic:優先度
/* インクリデクリ >> * */

void subfunc1(long *l){//lをインクリしてその実態を見ているだけ
    *l++;
}
//実態をインクリしている
void subfunc2(long *l){
    (*l)++;
     
}

//topic:前置きと後置き
/*前か後ろで動作が変わる。左から処理は実行されるので後置インクリは後回しになる*/

void increment(void){//前置と後置インクリ
    int var1 =8;
    int var2;

    //後置
    var2 = var1++;
    printf("%d\n",var2);//代入の後インクリメントされる
    //前置
    var2 = ++var1;//インクリメントした後代入される
    printf("%d\n",var2);
}


void subfunc3(char *p){
    printf("%d\n", *p );

    //pの指す値を位置をインクリ  
    printf("%d\n",++*p);

    //pの指す位置をインクリした後、インクリされた位置の値を参照
    printf("%d\n",*++p);
    p--;
    printf("%d\n",*(++p));//同じ結果

    //pの指す位置を参照後にインクリ
    printf("%d\n",*p++);
    printf("%d\n",*p);//インクリされた後の値を見てみると
    p--;
    printf("%d\n",*(p++));//同じ結果
    printf("%d\n",*p);//インクリされた後の値を見てみると

    //pの指す値を参照したあとpの指す値をインクリ
    printf("%d\n",(*p)++);
    printf("%d\n",*p);

}
void syrcpy(char *s, char *d){
    while(*s++ = *d++);
}
int main(){
    
    //インクリメント
    increment();

    //subfunc1,2
    printf("subfunc1,2\n");
    long num1 = 1;
    long num2 = 2;
    subfunc1(&num1);
    printf("%d\n",num1);
    subfunc2(&num2);
    printf("%d\n",num2);

    //subfunc3
    printf("\nsubfunc3\n");
    char *pc;
    char str[]={1,3,5,7};
    pc = str;
    subfunc3(pc);
    return 0;
    
}