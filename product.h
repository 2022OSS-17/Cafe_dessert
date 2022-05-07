typedef struct{
	char name[60];
	int weight;
	int price;
} Product;

// 디저트 생성 함수
int createProduct(Product *p);

// 생성된 디저트 읽어오는 함수
void readProduct(Product *p); 

// 생성된 디저트 수정하는 함수
int updateProduct(Product *p);

// 생성된 디저트 삭제하는 함수
int deleteProduct(Product *p); 
