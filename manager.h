#pragma once
#include <stdio.h>
#include <string.h>
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

// 디저트 이름으로 검색
void searchName(Product *p, int count);

// 디저트 가격으로 검색
void searchPrice(Product *p, int count);

// 카테고리로 검색
void searchCategory(Product *p, int count);