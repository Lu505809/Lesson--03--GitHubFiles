#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix1[3][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int matrix2[3][3] = {6, 7, 2, 7, 4, 15, 9, 10, 12};
    int add[3][3];
    int multy[3][3];
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            add[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d\t", add[i][j]);
        }
        printf("\n");
    }
    printf("for the multy:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            multy[i][j] = matrix1[i][0] * matrix2[0][j] + matrix1[i][1] * matrix2[1][i] + matrix1[j][2] * matrix2[2][i];
            printf("%d\t", multy[i][j]);
        }
        printf("\n");
    }
    // printf("%d",add); how to print a matrix
    return 0;
}