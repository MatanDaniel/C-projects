//void SizeOfString(char* str) //question 2
//{
//	int counter = 0;
//	for (int i = 0; *(str + i) != '\0'; i++)
//	{
//		counter++;;
//	}
//	printf("%d", counter);
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main(void) {
//	char string[80];
//	printf("Enter a value of a string:\n");
//	gets(string);
//	SizeOfString(string);
//	return 0;
//
////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>                 ///question 3 // ** not finished
////void Sort(int* x, int* y, int* z)
////{
////	int max = 0, min = 0, mid = 0;
////	if (*x > *y && *x > *z && *y > *z && *y < *x)
////	{
////		max = *x;
////		mid = *y;
////	}
////	else if (*y > *x && *y > *z && )
////	{
////		max = *y;
////	}
////	else if (*y > *z && *x > *y)//x>y>z
////	{
////		mid = *y;
////	}
////	else if (*z < *y && *z < *x) 
////	{
////		min = *z;
////	}
////}
////int main(void) {
////	int max, min, mid;
////	printf("Enter three values:\n");
////	scanf("%d%d%d", &max, &min, &mid);
////	Sort(&max, &mid, &min);
////	printf("Your max value is:%d\n", max);
////	printf("Your in between value is:%d\n", mid);
////	printf("Your minimum is:%d\n", min);
////	return 0;
////}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 3
void MinMax(int mat[][N], int* equal, int* max, int* min) // question 4 // *********
{
	int avg = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			avg += mat[i][j];
		}
	}
	avg = avg / (N*N); 
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		{
			if (avg > mat[i][j])
			{
				(*max)++;
			}
			else if (avg == mat[i][j]) 
			{
				(*equal)++;
			}
			else if (avg < mat[i][j])
			{
				(*min)++;
			}
		}
	}
}
void InsertMat(int mat[][N])
{
	printf("Enter %d values:\n",N* N);
	for (int i = 0;  i < N;  i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
}
int main(void) {
	int matrix[N][N],nim=0,max=0,equal=0;
	InsertMat(matrix);
	MinMax(matrix,&equal, &nim, &max);
	printf("%d %d %d", nim, equal, max);
	return 0;
}