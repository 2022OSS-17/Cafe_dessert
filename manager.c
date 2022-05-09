#include "manager.h"

//  �޴� ���/�Է� �Լ�
int selectMenu(){
    int menu;
    printf("\n*** ��ǰ ���� ***       ***��ǰ ���� Ű����ũ***\n");
    printf("1. �޴� ��ȸ              || 1. �޴� ��ȸ  \n");
    printf("2. �޴� �߰�              || 6. ����Ʈ �˻�\n");
    printf("3. �޴� ����              || 7. ���� �˻�\n");
    printf("4. �޴� ����              || 8. ī�װ� �˻�\n");
    printf("5. ���� ���� ����         || 9. �޴� ����\n");
    printf("6. ����Ʈ �˻�            || 10. ��ٱ��� ����\n");
    printf("7. ���� �˻�              || 0. ����\n");
    printf("8. ī�װ� �˻�\n");
    printf("0. ����\n\n");

    printf("=> ���ϴ� ���� ��ȣ��? ");
    scanf("%d", &menu);
    return menu;
}

// ��ϵ� ��ü ��ǰ ��� �Լ�
void listProduct(Product *p,int count){

    printf("\nNo.      Name      price      category\n");
    printf("==========================================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1 ) continue;
        printf("%2d ", i+1);
        readProduct(&p[i]);
    }
    printf("\n");
}

// ��ǰ�� ��ȣ������ �����ϴ� �Լ�
int selectDataNo(Product *p, int count){
    int no;
    listProduct(p,count);
    printf("��ȣ�� (���:0)?");
    scanf("%d",&no);
    return no;
}


// ����Ʈ ���� �Լ�
void saveData(Product *p, int count){
	FILE* fp;

	fp= fopen("japangi.txt", "wt");

	for (int i=0; i<count; i++){
		if(p[i].price == -1) continue;
        fprintf(fp, "%s\n", p[i].name);
        fprintf(fp, "%d\n", p[i].price);
        fprintf(fp, "%s\n", p[i].ctgy);
	}
	fclose(fp);
	printf("���� ���� �����!\n");
}

// ����� ����Ʈ �ҷ����� �Լ�
int loadData(Product *p){
	int count=0, i=0;
	FILE*fp;

	fp = fopen("japangi.txt", "rt");
    
    if(fp != NULL) {
        for(; i<100; i++){
            fgets(p[i].name, sizeof(p[i].name), fp);
            p[i].name[strlen(p[i].name) - 1] = '\0';
            if(feof(fp)) break;
            fscanf(fp, "%d", &p[i].price);
            fgetc(fp);
            fgets(p[i].ctgy, sizeof(p[i].ctgy), fp);
            p[i].ctgy[strlen(p[i].ctgy) - 1] = '\0';
	    }
	    fclose(fp);
	    printf("=> �ε� ����!\n");
	    return i;
    } 
    else {
        printf("=> ���Ͼ���\n");
        return 0;
    }
	
}

// ����Ʈ �̸����� �˻�
void searchName(Product *p, int count) {
    int scnt = 0;
    char search[20];

    printf("�˻��� ��ǰ? ");
    scanf("%s", search);

    printf("\nNo.      Name      price      category\n");
    printf("==========================================\n");

    for(int i = 0; i < count; i++) {
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, search)) {
            printf("%2d ", i+1);
            readProduct(&p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> �˻��� ������ ����!");
    printf("\n");
}

// ����Ʈ �������� �˻�
void searchPrice(Product *p, int count) {
    int scnt = 0;
    int search;

    printf("�˻��� ����? ");
    scanf("%d", &search);

    printf("\nNo.      Name      price      category\n");
    printf("==========================================\n");

    for(int i = 0; i < count; i++) {
        if(p[i].price == -1) continue;
        if(p[i].price == search) {
            printf("%2d ", i+1);
            readProduct(&p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> �˻��� ������ ����!");
    printf("\n");

}

// ī�װ��� �˻�
void searchCategory(Product *p, int count) {
    int scnt = 0;
    char search[20];

    printf("�˻��� ī�װ�? ");
    scanf("%s", search);

    printf("\nNo.      Name      price      category\n");
    printf("==========================================\n");

    for(int i = 0; i < count; i++) {
        if(p[i].price == -1) continue;
        if(strstr(p[i].ctgy, search)) {
            printf("%2d ", i+1);
            readProduct(&p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> �˻��� ������ ����!");
    printf("\n");
}

//�޴� ����
void putInBasket(Product *p, Customer *c) {
    strcpy(c->name, p->name);
    c->price = p->price;
    strcpy(c->ctgy, p->ctgy);

}

void readBasket(Customer *c){
    printf("||%9s ||%7d�� ||%7s ||\n", c->name, c->price, c->ctgy);
}

// ��ٱ��� ����
void listBasket(Customer *c, int count) {

    printf("**************�� ��ٱ���******************");
    printf("\nNo.      Name      price      category\n");
    printf("==========================================\n");
    for(int i=0; i<count; i++){
        if(c[i].price == -1 ) continue;
        printf("%2d ", i+1);
        readProduct(&c[i]);
    }
    printf("\n");
}

