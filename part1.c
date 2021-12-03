#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Assignment: 3
Author: Matan Daniel, ID: 315783522
*/
#define N  10
#define M 5
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
	printf("Longest series: ");
	for (int i = index; i < index + max + 1; i++)
	{
		printf("%d ", arr1[i]);
	}printf("\n");
	return counter1;
}
int main(void) {
	int One[N], Two[M];
	printf("Enter elements to array one:\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &One[i]);
	}
	printf("Enter elements too array two:\n");
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &Two[i]);
	}
	printf("%d\n", SubArray(One, Two, N, M));
	printf("%d\n", SequenceOfArray(One, N));
	return 0;
}