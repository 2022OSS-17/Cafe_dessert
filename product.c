#include "product.h"

// 디저트 생성하는 함수
int createProduct(Product *p){
    printf("\n");
    printf("제품명은? ");
    scanf("%[^\n]s",p->name);
    getchar();

    printf("가격은? ");
    scanf("%d", &p->price);
    getchar();

    printf("카테고리? (커피, 티, 주스, 빵, 쿠키, 샐러드) ");
    scanf("%[^\n]s", p->ctgy);
    getchar();
    
    printf("==> 성공적으로 추가됨!\n"); 
    return 1;
}

// 하나의 디저트 품목 출력 함수
void readProduct(Product *p){
    printf("||%9s ||%7d원 ||%7s ||\n",p->name,p->price,p->ctgy);
}

// 생성된 디저트 수정 함수
int updateProduct(Product *p){

    printf("\n");
    printf("제품명은? ");
    scanf("%[^\n]s",p->name);
    getchar();

    printf("가격은? ");
    scanf("%d",&p->price);
    getchar();

    printf("카테고리? (커피, 티, 주스, 빵, 쿠키, 샐러드) ");
    scanf("%[^\n]s", p->ctgy);
    getchar();

    printf("==> 성공적으로 수정됨!\n");
    return 1;
};

// 생성된 디저트 품목 삭제 함수
int deleteProduct(Product *p){
    p->price=-1;
    printf("==> 성공적으로 삭제됨!\n");
    return 0;
}
