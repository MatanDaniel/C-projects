#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Assignment: 2
Author: Matan Daniel, ID: 315783522
*/
#define VALUE -1
int SubArray(int arr1[], int arr2[], int size1, int size2)
{
	int index = 0, flag = 1; // init local value 
	for (int i = 0; i < size1; i++) // Running through the first array
	{
		if (arr1[i] == arr2[0]){ // Checks if the second array first index, matches the first array index
			for (int j = i; j < size2 + i; j++, index++) 	// Keeps on checking if the next elements equals between the two array
			{
				if (arr1[j] != arr2[index]) // Checks wether there is a match, or not
				{
					flag = -1;
				}	
			}
			if (flag == 1) // We find the arr2, in arr1
			{
				printf("The sub-array starts at index %d\n", i);
				return i;
			}
			else // Not found, keep on searching
			{
				index = 0;
				flag = 1;
			}
		}
	}
	printf("The sub-array doesnt exist in the array\n");
	return VALUE;
} 
int SequenceOfArray(int arr1[], int size1)
{
	int counter1 = 0 , counter2 = 0, max = 0, index = 0;
	for (int i = 0; i < size1; i++)
	{
		if (arr1[i] < arr1[i + 1])
		{
			counter1++;
			for (int j = i; j < size1; j++) 
			{
				if (arr1[j] < arr1[j + 1])
				{
					counter2++;
				}
				else
				{
					j = size1;
				}
			}
			if (counter2 > max)
			{
				max = counter2;
				index = i;
			}
			i = i + counter2;
			counter2 = 0;
		}
	}
	printf("Longest serie: ");
	for (int i = index; i < index + max + 1; i++)
	{
		printf("%d ", arr1[i]);
	}printf("\n");
	return counter1;
}
int main(void) {
	int arr1[] = { -3, 8, 23, -60, -54, 6, 87, -43, 12, -7 };
	int size1 = 10;
	printf("%d\n", SequenceOfArray(arr1, size1));

	/*int arr1[] = {9 , 5, 12, 7, 8, -2, 4, 32, 900, 13}, arr2[] = {9, 5, 12, 8, 7};
	int size1 = 10, size2 = 5;
	printf("%d\n", SubArray(arr1, arr2, size1, size2));*/
	return 0;
}
