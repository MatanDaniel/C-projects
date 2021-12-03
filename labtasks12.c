//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <malloc.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct
//{
//	char name[30];
//	int amount, price;
//}Product;
//
//typedef struct
//{
//	int id[10];
//	Product* pProd;
//	int numProd;
//}Cart;
//
//Cart* InitCashReg(int* pSize)
//{
//	printf("Enter input for the array:\n");
//	scanf("%d", pSize);
//	Cart* arr = (Cart*)malloc(*pSize * sizeof(Cart));
//	for (int i = 0; i < pSize; i++) {
//		{
//			Cart* cart = &arr[i];
//			printf("Enter number of products\n");
//			scanf("%d", &cart->numProd);
//			cart->pProd = (Product*)malloc(cart->numProd * sizeof(Product));
//			for (int j = 0; j < cart->numProd; j++)
//			{
//				Product* product = cart->pProd;
//				printf("Enter product name, price and count\n");
//				scanf("%s %d %d", &product->name, &product->price, &product->amount);
//			}
//		}
//	}
//}
//int main() {
//	int a;
//	Cart* carts = InitCashReg(&a);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	
	char name[30];
	int amount, price;
}Product;
typedef struct
{
	int id[10];
	Product* pProd;
	int numProd;
}Cart;

Cart* InitCashReg(int* pSize) 
{
	Cart* carts;
	printf("Enter the number of carts:\n");
	scanf("%d", &pSize);
	carts = (Cart*)malloc(*pSize * sizeof(Cart));
	for (int i = 0; i < *pSize; i++)
	{
		printf("Enter id of the cart you want:\n");
		scanf("%d", carts[i].id);
		printf("Enter number of products:\n");
		scanf("%d", carts[i].numProd);
		carts[i].pProd = (Product*)malloc((carts[i].numProd) * sizeof(Product);
		for (int j = 0; j < carts[i].numProd; j++)
		{
			printf("Enter id of the product %d")
		}
	}

}
int main(void) {


	return 0;
}