#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
void freememory(int** arr) // a funcation which releases memory
{
	free(*arr);
	*arr = NULL;
}
typedef enum { FALSE, TRUE }boolean; 
boolean duplication(int** num1, int var, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (var == (*num1)[i])
		{
			return TRUE;
		}
	}
	return FALSE;
}

int* SymmetricDiff(int* one, int sizeOne, int* two, int sizeTwo, int* pNewSize)
{
	int count = 0, index = 0;
	int* newArray = NULL;
	for (int i = 0; i < sizeOne; i++) // a funcation which determines the size of the new array
	{
		if (!duplication(&two, one[i], sizeTwo)) 
		{
			count++;
		}
	}
	for (int i = 0; i < sizeTwo; i++)
	{
		if (!duplication(&one, two[i], sizeOne))
		{
			count++;
		}
	}
	*pNewSize = count;
	if (count == 0)
	{
		printf("Invaild values, try again\n");
		return NULL;
	}
	newArray = (int*)malloc((*pNewSize) * sizeof(int)); // memory allocation to newArray depends on count 
	if (newArray == NULL) 
	{
		printf("Error!, memory not found\n");
		exit(1);
	}
	for (int i = 0; i < sizeTwo; i++)
	{
		if (!duplication(&two, one[i], sizeTwo)) // the xor condtion on the first array with the second array
		{
			newArray[index++] = one[i];
		}
	}
	for (int i = 0; i < sizeTwo; i++)
	{
		if (!duplication(&one, two[i], sizeOne)) // the same xor condtion but the opposite arrays
		{
			newArray[index++] = two[i];
		}
	}
	return newArray; 
}

int main(void) {
	int size1, size2, sizeNew = 0;
	printf("Enter the size of the first array:\n");
	scanf("%d", &size1);
	printf("Enter the size of the second array:\n");
	scanf("%d", &size2);
	int* one = (int*)malloc(size1 * sizeof(int));
	if (one == NULL) {
		printf("Error, memory is not found:\n");
		exit(1);
	}
	int* two = (int*)malloc(size2 * sizeof(int));
	if (two == NULL) {
		printf("Error, memory is not found:\n");
		exit(1);
	}
	printf("Enter the first array: %d\n" , size1);
	for (int i = 0; i < size1; i++)
	{
		scanf("%d", &one[i]);
	}
	printf("Enter the second array: %d\n", size2);
	for (int i = 0; i < size2; i++)
	{
		scanf("%d", &two[i]);
	}
	int* newArray = SymmetricDiff(one, size1, two, size2, &sizeNew);
	printf("The new symtrical array is:\n");
	for (int i = 0; i < sizeNew; i++)
	{
		printf("%d ", newArray[i]);
	}
	printf("\n");
	freememory(&one);
	freememory(&two);
	return 0;
}