
#include <stdio.h>

#define ROWS 5
#define COLS 5

void nextGeneration(int grid[ROWS][COLS]) {
    int i, j, x, y, neighbours;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            neighbours = 0;

            for (x = i - 1; x <= i + 1; x++) {
                for (y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < ROWS &&
                        y >= 0 && y < COLS &&
                        (x != i || y != j)) {
                        neighbours += grid[x][y] & 1;
                    }
                }
            }

            if (grid[i][j] & 1) {
                if (neighbours == 2 || neighbours == 3) {
                    grid[i][j] |= 2;
                }
            } else {
                if (neighbours == 3) {
                    grid[i][j] |= 2;
                }
            }
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] >>= 1;
        }
    }
}

void display(int grid[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[ROWS][COLS];
    int i, j, generations;

    printf("Enter the initial grid (0 = dead, 1 = alive):\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter number of generations: ");
    scanf("%d", &generations);

    printf("\nGeneration 0:\n");
    display(grid);

    for (i = 1; i <= generations; i++) {
        nextGeneration(grid);

        printf("\nGeneration %d:\n", i);
        display(grid);
    }

    return 0;
}
