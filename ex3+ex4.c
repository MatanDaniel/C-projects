#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SQUARE 4
#define ROW 5
#define COLS 8 
/* Assignment: 3
Author: Matan Daniel, ID: 315783522
*/
void func(int array[][SQUARE]) {   //**question 3**//
    int row = 0, col = 0;
    int i = 0, j = 0, counter1 = 0, counter2 = 0;
    printf("Enter index location:\n");
    scanf("%d %d", &row, &col);
    while (row > SQUARE || col > SQUARE)
    {
        if (row > SQUARE)
        {
            printf("Invalid row index, try again!\n");
        }
        if (col > SQUARE)
        {
            printf("Invalid column, try again!\n");
        }
        scanf("%d%d", &row, &col);
    }
    for (i = 0; i < SQUARE; i++)
    {
        for (j = 0; j < SQUARE; j++)
        {
            if (array[i][j] % array[row][col] == 0)
            {
                counter1++;
            }
            if (array[row][col] % array[i][j] == 0)
            {
                counter2++;
            }
        }
    }
    printf("number of multiplies: %d\n", counter1);
    printf("number of divisors: %d\n", counter2);
}
int is_symmetric(int cols, int matrix[][COLS], int first_row, int first_col, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matrix[first_row + i][first_col + j] != matrix[first_row + j][first_col + i]) {
                return 0;
            }
        }
    }
    return n;
}
void symmetric_sub_matrix(int rows, int cols, int matrix[][COLS]) {
    int max = 0, i_index = 0, j_index = 0, m;
    for (int i = 0, mi = rows; i < rows; ++i, --mi) {
        for (int j = 0, mj = cols; j < cols; j++, --mj) {
            if (mj < mi) {
                m = mj;
            }
            else {
                m = mi;
            }
            for (int n = 2; n <= m; ++n) {
                n = is_symmetric(cols, matrix, i, j, n);
                if (n != 0) {
                    if (max < n) {
                        i_index = i;
                        j_index = j;
                        max = n;
                    }
                }
                else {
                    n = m + 1;
                }
            }
        }
    }
    printf("The Max symmetric sub-matrix starts at indexes [%d][%d] and its size is: %d\n", i_index, j_index, max);
}
int main(void) {
    int matrix1[SQUARE][SQUARE], matrix2[ROW][COLS];
    printf("Enter numbers for the first matrix for question 3:\n");
    for (int i = 0; i < SQUARE; i++)
    {
        for (int j = 0; j < SQUARE; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter numbers for the second matrix for question 4:\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    func(matrix1);
    symmetric_sub_matrix(ROW, COLS, matrix2);


    return 0;
}