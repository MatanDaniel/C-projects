#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
void freememory2D(int** mat, int row) // A fucation which frees memory from  2 dimensional array
{
	for (int i = 0; i < row; i++)
	{
		free(mat[i]);
		mat[i] = NULL;
	}
	free(mat);
	mat = NULL;
	exit(1);
}
void PrintMatrix(int** matrix, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
}
int** BuildMatrix(int* pRow, int* pColumn){
	int** matrix = NULL;
	printf("Enter rows:\n");
	scanf("%d", pRow);
	printf("Enter number of columns:\n");
	scanf("%d", pColumn);
	// נעשהה הקצאה דינמית  
	matrix = (int**)malloc(*pRow * sizeof(int*));
	if (matrix == NULL)
	{
		printf("Not enough memory allocated\n");
		exit(1);
	}
	for (int i = 0; i < *pRow; i++)
	{
		matrix[i] = (int*)malloc(*pColumn * sizeof(int));
		if (matrix[i] == NULL) 
		{
			for (int j = 0; j < i; j++)
			{
				free(matrix[j]);
				matrix[j] = NULL;
			}
			free(matrix);
			matrix = NULL;
			exit(1);
		}
		printf("Enter number of rows: %d\n Enter total %d elements:\n", i+1, *pColumn);
		for (int j = 0; j < *pColumn; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	return matrix;
}
int** TransposeMatrix(int** matrix, int row, int col, int* pRow, int* pCol)
{
	int** transmatrix = NULL;
	transmatrix = (int**)malloc(col * sizeof(int*));
	if (transmatrix == NULL)
	{
		printf("Not enough memory allocated\n");
		exit(1);
	}
	for (int i = 0; i < col; i++)
	{
		transmatrix[i] = (int*)malloc(row * sizeof(int));
		if (transmatrix[i] == NULL)
		{
			printf("Not enough memory allocated\n");
			for (int j = 0; j < i; j++)
			{
				free(transmatrix[j]);
				transmatrix[j] = NULL;
			}
			free(transmatrix);
			transmatrix = NULL;
			exit(1);
		}
	}
	for (int i = 0; i < row ; i++)
	{
		for (int j = 0; j < col; j++)
		{
			transmatrix[j][i] = matrix[i][j];
		}
	}
	*pCol = row;
	*pRow = col;
	return transmatrix;
}
int main(void) {
	int row = 0, column = 0, pCol = 0, pRow = 0;
	int** matrix = NULL, **transmatrix = NULL;
	matrix = BuildMatrix(&row, &column);
	PrintMatrix(matrix, row, column);
	transmatrix = TransposeMatrix(matrix, row, column, &pRow, &pCol);
	printf("\n");
	PrintMatrix(transmatrix, pRow, pCol);
	freememory2D(matrix, row);
	freememory2D(transmatrix, pRow);
	return 0;
}