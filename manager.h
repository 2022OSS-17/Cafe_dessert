#pragma once
#include <stdio.h>
#include <string.h>
#include "product.h"

// ���Ǳ� �޴� �����ִ� �Լ�
int selectMenu();

// ����� ����Ʈ ��� �����ִ� �Լ�
void listProduct(Product *p,int count);

// ��ȣ�� ���ؼ� ����Ʈ �����ϴ� �Լ�
int selectDataNo(Product *p, int count);

// ����Ʈ ����Ʈ �����ϴ� �Լ�
void saveData(Product *p, int count);

// ����� ����Ʈ �ҷ����� �Լ�
int loadData(Product *p);

// ����Ʈ �̸����� �˻�
void searchName(Product *p, int count);

// ����Ʈ �������� �˻�
void searchPrice(Product *p, int count);

// ī�װ��� �˻�
void searchCategory(Product *p, int count);