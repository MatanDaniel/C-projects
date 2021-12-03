/* Assignment: 4
Author: Matan Daniel, ID: 315783522
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 11
void freeFunction(char** arry, int size) // a function which frees memory when needed
{
	for (int j = 0; j < size; j++)
	{
		free(arry[j]);
	}
	free(arry);
}
char** buildStr(int* countWords) { // a function to build a dynamic array + memory allocation
	char** words = NULL;
	char space[SIZE];
	printf("How many words would you like to enter? \n");
	scanf("%d", countWords);
	getchar();
	words = (char**)malloc((*countWords) * sizeof(char*));
	if (words == NULL) {
		printf("No memory");
		exit(1);
	}
		printf("Enter words :");
	for (int i = 0; i < (*countWords); i++)
	{
		scanf("%s", space);
		words[i] = (char*)malloc(strlen(space) + 1);
		if (words == NULL)
		{
			freeFunction(words, i);
			exit(1);
		}
		strcpy(words[i], space);
	}
	return words;
}
void wordFrequency(char** words, int countWords) 
{
	int counter = 1, k;
	for (int i = 0; i < countWords; i++)
	{
		counter = 0;
		for (int j = 0; j< countWords; j++)
		{
			if (strcmp(words[i], words[j]) == 0)
			{
				counter++;
			}	
		}
		for (k = 0; k < i; k++)
		{
			if (strcmp(words[i], words[k]) == 0)
			{
				break;
			}
		}
		if (k == i)
		{
			printf("\n%s: %d", words[i], counter);
		}
	}
}
char** textPreprocessing(char** text, int* countWords, char** stopwords, int
	countStopwords)
{
	char** temp = NULL;
	int counter = 0, flag = 0;
	for (int i = 0; i < *countWords; i++)
	{
		flag = 0;
		for (int j = 0; j < countStopwords; j++)
		{
			if (strcmp(text[i], stopwords[j]) == 0)
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			counter++;
			temp = (char**)realloc(temp, counter * sizeof(char*));
			if (temp == NULL)
			{
				printf("Eror! could not allocate memory\n");
				freeFunction(text, *countWords);
				freeFunction(stopwords, countStopwords);
				exit(1);
			}
			temp[counter - 1] = (char*)malloc(strlen(text[i]) + 1);
			if (temp[counter-1] == NULL)
			{
				printf("Error! could not allocate memory\n");
				freeFunction(text, *countWords);
				freeFunction(stopwords, countStopwords);
				freeFunction(temp, counter);
				exit(1);
			}
			strcpy(temp[counter-1], text[i]);
		}
	}
	*countWords = counter;
	return temp;
}
char** updateStr(char** string, int sizeOfstring, int* newUpdateSize)
{
	int flag = 0, counter = 0;
	char** temp = NULL;
	for (int i = 0; i < sizeOfstring; i++)
	{
		flag = 0; 
		for (int j = 0; j < strlen(string[i]); j++) // conditions for numbers and big letters
		{
			if (string[i][j] >= '0' && string[i][j] <= '9')
			{
				flag = 1;
			}
			if (string[i][j] >= 'A' && string[i][j]<= 'Z')
			{
				string[i][j] += 32;
			}
		}
		if (flag == 0)
		{
			counter++; 
			temp = (char**)realloc(temp, counter * sizeof(char*));
			if (temp == NULL)
			{
				printf("Error! could not allocate memory\n");
				freeFunction(string, sizeOfstring);
				exit(1);
			}
			temp[counter - 1] = (char*)malloc(strlen(string[i]) + 1);
			if (temp[counter-1]== NULL)
			{
				printf("Error! could not allocate memory\n");
				freeFunction(string, sizeOfstring);
				freeFunction(temp, counter);
				exit(1);
			}
			strcpy(temp[counter - 1], string[i]);
		}
	}
	*newUpdateSize = counter; 
	return temp;
}
int main(void)
{
	char** str1 = NULL, ** str2 = NULL, ** newStr = NULL;
	int size1, size2, updateSize;
	str1 = buildStr(&size1);
	newStr = updateStr(str1, size1, &updateSize);
	freeFunction(str1, size1);
	printf("Please enter the stop words\n");
	str2 = buildStr(&size2);
	str1 = NULL;
	str1 = textPreprocessing(newStr, &updateSize, str2, size2);
	wordFrequency(str1, updateSize);
	freeFunction(str1, updateSize);
	freeFunction(str2, size2);
	return 0;
}
