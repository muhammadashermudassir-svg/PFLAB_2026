#include <stdio.h>

int determinant(int a[5][5], int n)
{
    int m[5][5], i, j, k, r, c;
    int sign = 1, det = 0;

    if (n == 1)
        return a[0][0];

    if (n == 2)
        return a[0][0] * a[1][1] -
               a[0][1] * a[1][0];

    for (j = 0; j < n; j++)
    {
        r = 0;

        for (i = 1; i < n; i++)
        {
            c = 0;

            for (k = 0; k < n; k++)
            {
                if (k != j)
                    m[r][c++] = a[i][k];
            }

            r++;
        }

        det += sign * a[0][j] * determinant(m, n - 1);
        sign = -sign;
    }

    return det;
}

int main()
{
    int a[5][5], b[5][5], power[5][5], result[5][5];
    int rows, cols, rows2, cols2;
    int i, j, k, p, det, allZero, equal = 1;

    int zero = 1, identity = 1, diagonal = 1;
    int scalar = 1, upper = 1, lower = 1;
    int symmetric = 1, skew = 1;
    int idempotent = 1, nilpotent = 0;

    printf("Enter rows and columns of first matrix (maximum 5): ");
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > 5 || cols < 1 || cols > 5)
    {
        printf("Invalid dimensions!\n");
        return 0;
    }

    printf("Enter first matrix elements:\n");

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (rows2 < 1 || rows2 > 5 || cols2 < 1 || cols2 > 5)
    {
        printf("Invalid dimensions!\n");
        return 0;
    }

    printf("Enter second matrix elements:\n");

    for (i = 0; i < rows2; i++)
        for (j = 0; j < cols2; j++)
            scanf("%d", &b[i][j]);

    if (rows == rows2 && cols == cols2)
    {
        for (i = 0; i < rows; i++)
            for (j = 0; j < cols; j++)
                if (a[i][j] != b[i][j])
                    equal = 0;

        if (equal)
            printf("12. Equal Matrices\n");
        else
            printf("12. Matrices are not equal\n");
    }
    else
    {
        printf("12. Matrices are not equal (different dimensions)\n");
    }

    if (rows == cols)
        printf("1. Square Matrix\n");
    else
        printf("2. Rectangular Matrix\n");

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (a[i][j] != 0)
                zero = 0;

    if (zero)
    {
        printf("3. Zero Matrix\n");
        printf("15. Null Matrix\n");
    }

    if (rows == 1)
        printf("13. Row Matrix\n");

    if (cols == 1)
        printf("14. Column Matrix\n");

    if (rows == cols)
    {
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (i != j && a[i][j] != 0)
                {
                    diagonal = 0;
                    identity = 0;
                }

                if (i == j && a[i][j] != 1)
                    identity = 0;

                if (i > j && a[i][j] != 0)
                    upper = 0;

                if (i < j && a[i][j] != 0)
                    lower = 0;

                if (a[i][j] != a[j][i])
                    symmetric = 0;

                if (a[i][j] != -a[j][i])
                    skew = 0;
            }
        }

        for (i = 1; i < rows; i++)
            if (a[i][i] != a[0][0])
                scalar = 0;

        if (identity)
            printf("4. Identity Matrix\n");

        if (diagonal)
            printf("5. Diagonal Matrix\n");

        if (diagonal && scalar)
            printf("6. Scalar Matrix\n");

        if (upper)
            printf("7. Upper Triangular Matrix\n");

        if (lower)
            printf("8. Lower Triangular Matrix\n");

        if (symmetric)
            printf("9. Symmetric Matrix\n");

        if (skew)
            printf("10. Skew-Symmetric Matrix\n");

        det = determinant(a, rows);

        if (det == 0)
            printf("11. Singular Matrix\n");
        else
            printf("11. Non-Singular Matrix\n");

        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < rows; j++)
            {
                result[i][j] = 0;

                for (k = 0; k < rows; k++)
                    result[i][j] += a[i][k] * a[k][j];
            }
        }

        for (i = 0; i < rows; i++)
            for (j = 0; j < rows; j++)
                if (result[i][j] != a[i][j])
                    idempotent = 0;

        if (idempotent)
            printf("16. Idempotent Matrix\n");

        for (i = 0; i < rows; i++)
            for (j = 0; j < rows; j++)
                power[i][j] = a[i][j];

        for (k = 1; k <= rows; k++)
        {
            allZero = 1;

            for (i = 0; i < rows; i++)
                for (j = 0; j < rows; j++)
                    if (power[i][j] != 0)
                        allZero = 0;

            if (allZero)
            {
                nilpotent = 1;
                break;
            }

            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < rows; j++)
                {
                    result[i][j] = 0;

                    for (p = 0; p < rows; p++)
                        result[i][j] += power[i][p] * a[p][j];
                }
            }

            for (i = 0; i < rows; i++)
                for (j = 0; j < rows; j++)
                    power[i][j] = result[i][j];
        }

        if (nilpotent)
            printf("17. Nilpotent Matrix\n");
    }

    return 0;
}