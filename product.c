#include <stdio.h>
#include "product.h"

// 디저트 생성하는 함수
int createProduct(Product *p){
    printf("\n");
    printf("제품명은? ");
    scanf("%[^\n]s",p->name);
    getchar();

    printf("중량은? ");
    scanf("%d",&p->weight);

    printf("가격은? ");
    scanf("%d",&p->price);
    
    printf("==> 성공적으로 추가됨!\n"); 
    return 1;
}

// 하나의 디저트 품목 출력 함수
void readProduct(Product *p){
    printf("%-15s %3dg %4d원\n",p->name,p->weight,p->price);
}

// 생성된 디저트 수정 함수
int updateProduct(Product *p){

    printf("\n");
    printf("제품명은? ");
    scanf("%[^\n]s",p->name);
    getchar();

    printf("중량은? ");
    scanf("%d",&p->weight);

    printf("가격은? ");
    scanf("%d",&p->price);
    printf("==> 성공적으로 수정됨!\n");
    return 1;
};

// 생성된 디저트 품목 삭제 함수
int deleteProduct(Product *p){
    p->weight=-1;
    p->price=-1;
    printf("==> 성공적으로 삭제됨!\n");
    return 0;
}
