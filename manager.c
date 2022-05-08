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

	fp= fopen("product.txt","wt");
	for (int i=0; i<count; i++){
		if(p[i].price == -1) continue;
		fprintf(fp, "%s %d %d\n", p[i].name, p[i].price, p[i].ctgy);
	}
	fclose(fp);
	printf("���� ���� �����!\n");
}

// ����� ����Ʈ �ҷ����� �Լ�
int loadData(Product *p){
	int count=0, i=0;
	FILE*fp;

	fp = fopen("product.txt", "rt");
    
    if(fp != NULL) {
        for(; i<100; i++){
            fgets(p[i].name, sizeof(p[i].name), fp);
            p[i].name[strlen(p[i].name) - 1] = '\0';
            if(feof(fp)) break;
            fscanf(fp, "%d", &p[i].price);
            fgets(p[i].ctgy, sizeof(p[i].ctgy), fp);
            p[i].ctgy[strlen(p[i].ctgy) - 1] = '\0';
	    }
	    fclose(fp);
	    printf("=> �ε� ����!\n");
	    return count;
    } 
    else {
        printf("=> ���Ͼ���\n");
        return 0;
    }
	
}
