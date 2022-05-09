#pragma once
#include <stdio.h>

typedef struct{
	char name[60]; // ����Ʈ ��
	int price; // ����
	char ctgy[20];  // ī�װ�
} Product;

typedef struct{
	char name[60]; // ����Ʈ ��
	int price; // ����
	char ctgy[20];  // ī�װ�
} Customer;

// ����Ʈ ���� �Լ�
int createProduct(Product *p);

// ������ ����Ʈ �о���� �Լ�
void readProduct(Product *p); 

// ������ ����Ʈ �����ϴ� �Լ�
int updateProduct(Product *p);

// ������ ����Ʈ �����ϴ� �Լ�
int deleteProduct(Product *p); 
