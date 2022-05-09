#include <stdio.h>
#include "manager.h"
#include "product.h"

int main(void){
    
    Product plist[100];
    Customer clist[20];
    int curcount=0;
    int count = 0, menu;
    int selected = 0; // 고객이 장바구니에 넣은 수 카운트
    
    count = loadData(plist);
    curcount=count; 

    while (1){
        menu = selectMenu();
        getchar();
        if(menu == 0) break;
        if(menu == 1 || menu ==3 || menu == 4){	
		    if (count==0){ 
                printf(" 데이터가 없습니다!\n");
			    continue;
			}
		}

        if(menu == 1) listProduct(plist,curcount); 
        else if (menu == 2) {
            count+=createProduct(&plist[curcount++]); 
        }
        else if (menu == 3) {
            int no=selectDataNo(plist, curcount);
            if(no==0){
                printf("=>취소됨!\n");
                continue;
            }
            updateProduct(&plist[no-1]);
        }
        else if (menu == 4) {
            int no=selectDataNo(plist, curcount);
            if(no==0){
                printf("=>취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제:1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteProduct(&plist[no-1])) count --;       
           	 } 
        }
	    else if (menu == 5){
		    if (count==0) printf("데이터가 없습니다!\n");
		    else saveData(plist,curcount);
	    }
        else if (menu == 6) {
            searchName(plist, curcount);
        } else if (menu == 7) {
            searchPrice(plist, curcount);
        } else if (menu == 8) {
            searchCategory(plist, curcount);
        } else if (menu == 9) {
            
            int n = 0;
            while (1) {
                printf("\n원하는 메뉴 번호를 선택해 장바구니에 담으세요.\n");

                int no = selectDataNo(plist, curcount);
                if(no==0){
                    printf("=>취소됨!\n");
                    continue;
                }

                putInBasket(&plist[no-1], &clist[selected++]);
                printf("메뉴 선택 나가기: 0 | 계속하기: 1 ");
                scanf("%d", &n);  
                if(n == 0) {
                   break;
                }
            }
            
        } else if (menu == 10) {
            listBasket(clist, selected);
        } 
	}

	printf("\n종료됨!\n");
   	return 0;
}
