#include <stdio.h>
#include <stdlib.h>

typedef struct BookData_tag
{
    char *title;
    int price;
    char isbn[32];
    struct BookData_tag *next;

}BookData;

int main(){
    printf("hello");
    BookData *book_data_p0 = malloc(sizeof(BookData));
    char str1[] = "Hello"; // 宣言と初期化
    
    book_data_p0->price = 1000;
    book_data_p0->next = NULL;
    
    BookData *book_data_p1 = malloc(sizeof(BookData));
    book_data_p1->price = 500;
    book_data_p1->next = book_data_p0;

    BookData *book_data_p;
    book_data_p = book_data_p1;
    while (book_data_p->next != NULL){
        printf("%d\n",book_data_p->price);
        book_data_p = book_data_p->next;
    }
    printf("%d",book_data_p->price);

}