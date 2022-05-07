#include "product.h"

// 자판기 메뉴 보여주는 함수
int selectMenu();

// 저장된 디저트 목록 보여주는 함수
void listProduct(Product *p,int count);

// 번호를 통해서 디저트 선택하는 함수
int selectDataNo(Product *p, int count);

// 디저트 리스트 저장하는 함수
void saveData(Product *p, int count);

// 저장된 리스트 불러오는 함수
int loadData(Product *p);
