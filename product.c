#include "product.h"

// ����Ʈ �����ϴ� �Լ�
int createProduct(Product *p){
    printf("\n");
    printf("��ǰ����? ");
    scanf("%[^\n]s",p->name);
    getchar();

    printf("������? ");
    scanf("%d", &p->price);
    getchar();

    printf("ī�װ�? (Ŀ��, Ƽ, �ֽ�, ��, ��Ű, ������) ");
    scanf("%[^\n]s", p->ctgy);
    getchar();
    
    printf("==> ���������� �߰���!\n"); 
    return 1;
}

// �ϳ��� ����Ʈ ǰ�� ��� �Լ�
void readProduct(Product *p){
    printf("||%9s ||%7d�� ||%7s ||\n",p->name,p->price,p->ctgy);
}

// ������ ����Ʈ ���� �Լ�
int updateProduct(Product *p){

    printf("\n");
    printf("��ǰ����? ");
    scanf("%[^\n]s",p->name);
    getchar();

    printf("������? ");
    scanf("%d",&p->price);
    getchar();

    printf("ī�װ�? (Ŀ��, Ƽ, �ֽ�, ��, ��Ű, ������) ");
    scanf("%[^\n]s", p->ctgy);
    getchar();

    printf("==> ���������� ������!\n");
    return 1;
};

// ������ ����Ʈ ǰ�� ���� �Լ�
int deleteProduct(Product *p){
    p->price=-1;
    printf("==> ���������� ������!\n");
    return 0;
}
