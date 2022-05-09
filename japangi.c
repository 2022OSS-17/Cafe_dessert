#include <stdio.h>
#include "manager.h"
#include "product.h"

int main(void){
    
    Product plist[100];
    Customer clist[20];
    int curcount=0;
    int count = 0, menu;
    int selected = 0; // ���� ��ٱ��Ͽ� ���� �� ī��Ʈ
    
    count = loadData(plist);
    curcount=count; 

    while (1){
        menu = selectMenu();
        getchar();
        if(menu == 0) break;
        if(menu == 1 || menu ==3 || menu == 4){	
		    if (count==0){ 
                printf(" �����Ͱ� �����ϴ�!\n");
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
                printf("=>��ҵ�!\n");
                continue;
            }
            updateProduct(&plist[no-1]);
        }
        else if (menu == 4) {
            int no=selectDataNo(plist, curcount);
            if(no==0){
                printf("=>��ҵ�!\n");
                continue;
            }
            int deleteok;
            printf("������ �����Ͻðڽ��ϱ�?(����:1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteProduct(&plist[no-1])) count --;       
           	 } 
        }
	    else if (menu == 5){
		    if (count==0) printf("�����Ͱ� �����ϴ�!\n");
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
                printf("\n���ϴ� �޴� ��ȣ�� ������ ��ٱ��Ͽ� ��������.\n");

                int no = selectDataNo(plist, curcount);
                if(no==0){
                    printf("=>��ҵ�!\n");
                    continue;
                }

                putInBasket(&plist[no-1], &clist[selected++]);
                printf("�޴� ���� ������: 0 | ����ϱ�: 1 ");
                scanf("%d", &n);  
                if(n == 0) {
                   break;
                }
            }
            
        } else if (menu == 10) {
            listBasket(clist, selected);
        } 
	}

	printf("\n�����!\n");
   	return 0;
}
