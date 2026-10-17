
#include <stdio.h>

int main() {
    int matrix[3][3], transpose[3][3], C[3][3],adjoint[3][3];
    float inverse[3][3];
    int i, j, x, y, r, c;
    int minor[2][2], det;

    printf("Enter 9 elements of the matrix:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display original matrix
    printf("\nOriginal Matrix:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose
    for(x = 0; x < 3; x++) {
        for(y = 0; y < 3; y++) {
            transpose[x][y] = matrix[y][x];
        }
    }

    printf("\nTransposed Matrix:\n");

    for(x = 0; x < 3; x++) {
        for(y = 0; y < 3; y++) {
            printf("%d\t", transpose[x][y]);
        }
        printf("\n");
    }

    // Cofactor
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            x = 0;

            for(r = 0; r < 3; r++) {
                if(r == i)
                    continue;

                y = 0;

                for(c = 0; c < 3; c++) {
                    if(c == j)
                        continue;

                    minor[x][y] = matrix[r][c];
                    y++;
                }
                x++;
            }

            C[i][j] = minor[0][0] * minor[1][1]
                    - minor[0][1] * minor[1][0];

            if((i + j) % 2 != 0) {
                C[i][j] = -C[i][j];
            }
        }
    }

    printf("\nCofactor Matrix:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    // Determinant
    det = 0;

    for(j = 0; j < 3; j++) {
        det = det + matrix[0][j] * C[0][j];
    }

    printf("\nDeterminant = %d\n", det);
    
       // Adjoint = transpose of cofactor matrix
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            adjoint[i][j] = C[j][i];
        }
    }

    printf("\nAdjoint Matrix:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", adjoint[i][j]);
        }
        printf("\n");
    }
//inverse

for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
        inverse[i][j] = (float)adjoint[i][j] / det; 
    }
} 

printf("\ninverse matrix\n");
for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
        printf("%.2f\t", inverse[i][j]);
    }
    printf("\n");
}



    return 0;
}

