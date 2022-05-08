#include <stdio.h>
#include "manager.h"
#include "product.h"

int main(void){
    
    Product plist[100];
    int curcount=0;
    int count = 0, menu;
    
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
                printf("=>��ҵ�!");
                continue;
            }
            updateProduct(&plist[no-1]);
        }
        else if (menu == 4) {
            int no=selectDataNo(plist, curcount);
            if(no==0){
                printf("=>��ҵ�!");
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
	}

	printf("\n�����!\n");
   	return 0;
}
