//#define _CRT_SECURE_NO_WARNINGS *** question 1***
//#include <stdio.h>
//#include< stdlib.h >
//void  insertArray(int arr1[],int size1) {
//	for (int i = 0; i < size1; i++)
//	{
//		printf("Enter array value:\n");
//		scanf("%d", &arr1[i]);
//	}
//}
//int minimizeArray(int arr2[], int size2)
//{
//	int counter = 0;
//	for (int i = 0; i < size2; i++)
//	{
//		if (arr2[i] % 2 == 0)
//		{
//			counter++;
//		}
//	} 	
//	int* arrayOfCounter = (int*)malloc(counter * sizeof(int));
//	int j = 0;
//	for (int i = 0; i < size2; i++)
//	{
//		if (arr2[i] % 2 == 0)
//		{
//			arrayOfCounter[j] = arr2[i];
//			j++;
//		}
//	}
//	return arrayOfCounter;
//}
//int func(int arr2[], int size2){
//
//	int counter = 0;
//	for (int i = 0; i < size2; i++)
//	{
//		if (arr2[i] % 2 == 0)
//		{
//			counter++;
//		}
//	}
//	return counter;
//}
//int main(void) {
//	int size3;
//	printf("Enter the size of the array:\n");
//	scanf("%d", &size3);
//	int* digitOfArray = (int*)malloc(size3 * sizeof(int));
//	insertArray(digitOfArray, size3);
//	int* evenNumbers = minimizeArray(digitOfArray, size3);
//	int x = func(digitOfArray, size3);
//	for (int i = 0; i < func(digitOfArray, size3); i++)
//	{
//		printf("%d", evenNumbers[i]);
//	}
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS /// question 2
//#include <stdio.h>
//#include <stdlib.h>
//void fun(int ch, int size2, int str2);
//void str_cut(char* str1)
//{
//	char* str2=(char*)malloc(1);
//	char ch,fresh;
//	int size2=0,size1=0;
//	while (1)
//	{
//		printf("enter the current character of # for ending the process\n");
//		scanf("%c", &ch);
//		scanf("%c", &fresh);
//		if (ch == '#')
//			break;
//		size2++;
//		str2 = (char*)realloc(str2,size2 * sizeof(char));
//		str2[size2 - 1] = ch;
//	}
//	str2 = (char*)realloc(str2, (size2+1) * sizeof(char));
//	str2[size2 ] = '\0';
//	for (size1 = 0; str1[size1] != '/0'; size1++);
//	str1= (char*)realloc(str2, (size1+size2 + 1) * sizeof(char));
//	for (int i = 0; i < size2; i++)
//	{
//		str1[size1+i] = str2[i];
//	}
//	str1[size1+size2] = '\0';
//}
//int main(void) {
//	char* str;
//	int sizeOfString = 0;
//	printf("Enter size of string:\n");
//	scanf("%d", &sizeOfString);
//	str = (char*)malloc(sizeOfString * sizeof(char));
//	printf("Enter string values:\n");
//	//scanf("%s", str);
//	gets(str);
//	gets(str);
//	str_cut(str);
//	printf("%s", str);
//	return 0;
//}
//void fun(int ch, int size2, int* str2) {
//	while (1)
//	{
//		printf("enter the current character of # for ending the process\n");
//		scanf("%c", &ch);
//		if (ch == '#')
//			break;
//		size2++;
//		str2 = (char*)realloc(str2, size2 * sizeof(char));
//		str2[size2 - 1] = ch;
//	}
//	str2 = (char*)realloc(str2, (size2 + 1) * sizeof(char));
//	str2[size2] = '\0';
//}
//#define _CRT_SECURE_NO_WARNINGS /// question 3
//#include <stdio.h>
//#include <stdlib.h>
//#define N 80
//void paintWords(char** str,int sizeOfStr)
//{
//	for (int i = 0;i < sizeOfStr ; i++)
//	{
//		printf("%s\n", str[i]);
//	}
//}
//int main(void) {
//	int input = 0, i = 0,sizeOfString;
//	char** words;
//	char c;
//	int sizeOfArray = 0;
//	words = (char**)malloc(1  * sizeof(char*));
//	do
//	{
//		printf("Would you like to add new word?\n");
//		scanf("%d", &input);
//		scanf("%c", &c);
//		if (input) 
//		{
//			sizeOfArray++;
//			words = (char**)realloc(words, sizeOfArray * sizeof(char*));
//			printf("Enter size of string:\n");
//			scanf("%d", &sizeOfString);
//			scanf("%c", &c);
//			words[i - 1] = (char*)malloc(sizeOfString * sizeof(char));
//			scanf("%s", words[i-1]);
//		}
//	} while (input == 1);
//	paintWords(words, sizeOfArray );
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS /// question 4
#include <stdio.h>
#include <stdlib.h>
#include <stdaib.h>
void insertMat(int** arr, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			scanf("%d", &arr[i][j]);
		}
		
	}
}
void sortMat(int** arr1, int size1, int size2)
{
	int temp = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			for (int k = i; k < size1; k++)
			{
				for (int s = j; s < size2; s++)
				{
					if (arr1[k][s] < arr1[i][j])
					{
						temp = arr1[k][s];
						arr1[k][s] = arr1[i][j];
						arr1[i][j] = temp;
					}
				}
			}
		}
	}
}
int main(void) {



	return 0;
}
