#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Assignment: 3
Author: Matan Daniel, ID: 315783522
*/
int FlagReturner(int matrix[5][8], int rowStart, int rowEnd, int colStart, int colEnd) //A function which runs on the semetrical condition//
{/*
    for (int k = colStart; k < colEnd; k++) {
        for (int l = rowStart; l < rowEnd; l++) {
            printf("%d ", matrix[k][l]);

        }
        printf("\n");
    }
    printf("\n");*/

    for (int i = colStart; i <= colEnd; i++)
    {
        for (int j = rowStart; j <= rowEnd; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return -1;
            }
        }
    }
    return 1;
}
void SubMatrix(int matrix[5][8], int rows, int cols) // פונקצציה שמוצאת את התת מטריצה //
{
    for (int i = 0; i <= rows; i++) {
        for (int j = i; j <= rows; j++) {
            for (int m = 0; m <= cols; m++) {
                for (int n = m; n <= cols; n++) {                 
                    if (n - m == j - i)
                    {        
                        if (FlagReturner(matrix, i, j, m, n) == 1) 
                        {
                            for (int k = m; k <= n; k++) {
                                for (int l = i; l <= j; l++) {
                                    printf("%d ", matrix[k][l]);

                                }
                                printf("\n");
                            }
                            printf("\n");

                            
                        }
                    }
                }
            }
        }
    }
}
int main(void) {
    int matrix[5][8] = { {1, 2, 0, 3, 2, 1, 0, 7},
                        {2, 3, 4, 1, 2, 3, 4, 5},
                        {3, 4, 6, 2, 5, 6, 7, 6},
                        {4, 5, 7, 3, 6, 8, 9, 8},
                        {6, 7, 1, 4, 7, 9, 0, 9} };
    SubMatrix(matrix, 8, 5);

	return 0;
}

