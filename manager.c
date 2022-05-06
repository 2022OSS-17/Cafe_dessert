#include "manager.h"

int selectMenu(){
    int menu;
    printf("\n*** 제품 관리 ***\n");
    printf("1. 메뉴 조회\n");
    printf("2. 메뉴 추가\n");
    printf("3. 메뉴 수정\n");
    printf("4. 메뉴 삭제\n");
    printf("5. 변경 사항 저장\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 서비스 번호는? ");
    scanf("%d", &menu);
    return menu;
}
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

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p,count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}

void saveData(Product *p, int count){
	FILE* fp;

	fp= fopen("product.txt","wt");
	for (int i=0; i<count; i++){
		if(s[i].weight == -1) continue;
		fprintf(fp, "%s %d %d\n", p[i].name, p[i].weight, p[i].price);
	}
	fclose(fp);
	printf("변경 사항 저장됨!\n");
}


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
	printf("=> 로딩 성공!\n");
	return count;
}
