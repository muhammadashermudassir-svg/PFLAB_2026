
#include <stdio.h>

void computeTotals(int (*marks)[3], int rows, int totals[]) {
    int i, j;

    for (i = 0; i < rows; i++) {
        totals[i] = 0;

        for (j = 0; j < 3; j++) {
            totals[i] = totals[i] + *(*(marks + i) + j);
        }
    }
}

int findTopper(const int *totals, int rows) {
    int i, top = 0;

    for (i = 1; i < rows; i++) {
        if (*(totals + i) > *(totals + top)) {
            top = i;
        }
    }

    return top;
}

int main() {
    int marks[3][3];
    int totals[3];
    int i, j, topper;

    for (i = 0; i < 3; i++) {
        printf("Enter marks for student %d:\n", i + 1);

        for (j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    computeTotals(marks, 3, totals);

    printf("\nStudent Totals:\n");

    for (i = 0; i < 3; i++) {
        printf("Student %d: %d\n", i + 1, totals[i]);
    }

    topper = findTopper(totals, 3);

    printf("\nTopper: Student %d\n", topper + 1);
    printf("Highest Total: %d\n", totals[topper]);

    return 0;
}
