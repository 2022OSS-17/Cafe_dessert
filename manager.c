#include "manager.h"

//  메뉴 출력/입력 함수
int selectMenu(){
    int menu;
    printf("\n*** 제품 관리 ***\n");
    printf("1. 메뉴 조회\n");
    printf("2. 메뉴 추가\n");
    printf("3. 메뉴 수정\n");
    printf("4. 메뉴 삭제\n");
    printf("5. 변경 사항 저장\n");
    printf("6. 디저트 검색\n");
    printf("7. 가격 검색\n");
    printf("8. 카테고리 검색\n");
    printf("9. 장바구니\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 서비스 번호는? ");
    scanf("%d", &menu);
    return menu;
}

// 등록된 전체 제품 출력 함수
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

// 제품을 번호명으로 선택하는 함수
int selectDataNo(Product *p, int count){
    int no;
    listProduct(p,count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    return no;
}


// 리스트 저장 함수
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
	printf("변경 사항 저장됨!\n");
}

// 저장된 리스트 불러오는 함수
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
	    printf("=> 로딩 성공!\n");
	    return i;
    } 
    else {
        printf("=> 파일없음\n");
        return 0;
    }
	
}

// 디저트 이름으로 검색
void searchName(Product *p, int count) {
    int scnt = 0;
    char search[20];

    printf("검색할 제품? ");
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
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

// 디저트 가격으로 검색
void searchPrice(Product *p, int count) {
    int scnt = 0;
    int search;

    printf("검색할 가격? ");
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
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");

}

// 카테고리로 검색
void searchCategory(Product *p, int count) {
    int scnt = 0;
    char search[20];

    printf("검색할 카테고리? ");
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
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
//장바구니
printf("디저트를 골라주세요");

