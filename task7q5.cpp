
#include <stdio.h>

int main()
{
    int a[3][3][3];
    int i, j, k, x, y;
    int same;

    printf("Enter 27 elements of the 3D array:\n");

    for (i = 0; i < 3; i++)
    {
        printf("Enter elements for Layer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    printf("\nThe three layers are:\n");

    for (i = 0; i < 3; i++)
    {
        printf("\nLayer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("%d ", a[i][j][k]);
            }

            printf("\n");
        }
    }

    printf("\nLayer Comparisons:\n");

    for (x = 0; x < 3; x++)
    {
        for (y = x + 1; y < 3; y++)
        {
            same = 1;

            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (a[x][i][j] != a[y][i][j])
                    {
                        same = 0;
                    }
                }
            }

            if (same == 1)
            {
                printf("Layer %d and Layer %d are IDENTICAL.\n",
                       x + 1, y + 1);
            }
            else
            {
                printf("Layer %d and Layer %d are DISTINCT.\n",
                       x + 1, y + 1);
            }
        }
    }

    return 0;
}
