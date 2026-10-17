
#include <stdio.h>

int main()
{
    int A[3][3], B[3][3], C[3][3];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of matrix A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of matrix B: ");
    scanf("%d%d", &r2, &c2);

    if (r1 < 1 || r1 > 3 || c1 < 1 || c1 > 3 ||
        r2 < 1 || r2 > 3 || c2 < 1 || c2 > 3)
    {
        printf("Invalid dimensions. Maximum size is 3x3.\n");
        return 0;
    }

    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter elements of matrix A:\n");

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");

    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    printf("Matrix A:\n");

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");

    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for (k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Resultant matrix:\n");

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
