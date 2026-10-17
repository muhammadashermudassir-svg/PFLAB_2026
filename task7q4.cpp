#include <stdio.h>

int main()
{
    int A[3][3][3];
    int i, j, k;
    int layerTotal, overallTotal = 0;
    int largest = 0, smallest = 0;
    int count = 0;

    printf("Enter 27 elements of the 3D array:\n");

    for (i = 0; i < 3; i++)
    {
        printf("Layer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &A[i][j][k]);

                if (count == 0)
                {
                    largest = A[i][j][k];
                    smallest = A[i][j][k];
                }

                if (A[i][j][k] > largest)
                    largest = A[i][j][k];

                if (A[i][j][k] < smallest)
                    smallest = A[i][j][k];

                count++;
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        layerTotal = 0;

        printf("\nLayer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("%d ", A[i][j][k]);
                layerTotal += A[i][j][k];
            }

            printf("\n");
        }

        printf("Layer total = %d\n", layerTotal);
        overallTotal += layerTotal;
    }

    printf("\nOverall total = %d\n", overallTotal);
    printf("Number of elements = %d\n", count);
    printf("Average = %.2f\n", (float)overallTotal / count);
    printf("Largest element = %d\n", largest);
    printf("Smallest element = %d\n", smallest);

    return 0;
}