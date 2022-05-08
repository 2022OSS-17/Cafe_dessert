#include <stdio.h>
#include "manager.h"

//  �޴� ���/�Է� �Լ�
int selectMenu(){
    int menu;
    printf("\n*** ��ǰ ���� ***\n");
    printf("1. �޴� ��ȸ\n");
    printf("2. �޴� �߰�\n");
    printf("3. �޴� ����\n");
    printf("4. �޴� ����\n");
    printf("5. ���� ���� ����\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� ���� ��ȣ��? ");
    scanf("%d", &menu);
    return menu;
}

// ��ϵ� ��ü ��ǰ ��� �Լ�
void listProduct(Product *p,int count){

    printf("\nNo. Name          weight price\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if( p[i].weight == -1 || p[i].price == -1 ) continue;
        printf("%2d.", i+1);
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
    getchar();
    return no;
}


// ����Ʈ ���� �Լ�
void saveData(Product *p, int count){
	FILE* fp;

	fp= fopen("product.txt","wt");
	for (int i=0; i<count; i++){
		if(p[i].weight == -1) continue;
		fprintf(fp, "%s %d %d\n", p[i].name, p[i].weight, p[i].price);
	}
	fclose(fp);
	printf("���� ���� �����!\n");
}

// ����� ����Ʈ �ҷ����� �Լ�
int loadData(Product *p){
	int count=0, i=0;
	FILE*fp;
	fp = fopen("product.txt", "rt");
	for(; i<100; i++){
		fscanf(fp, "%s", p[i].name);
		if(feof(fp)) break;
		fscanf(fp, "%d", &p[i].weight);
		fscanf(fp, "%d", &p[i].price);
	}
	fclose(fp);
	printf("=> �ε� ����!\n");
	return count;
}
