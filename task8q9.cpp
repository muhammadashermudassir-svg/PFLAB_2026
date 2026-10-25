
#include <stdio.h>

int sumShelf(const int *shelf, int count) {
    int i, sum = 0;

    for (i = 0; i < count; i++) {
        sum = sum + *(shelf + i);
    }

    return sum;
}

int findLargestShelf(const int *counts, int shelves) {
    int i, largest = 0;

    for (i = 1; i < shelves; i++) {
        if (*(counts + i) > *(counts + largest)) {
            largest = i;
        }
    }

    return largest;
}

int main() {
    int shelfA[] = {101, 102, 103};
    int shelfB[] = {201, 202};
    int shelfC[] = {301, 302, 303, 304};

    int *shelves[] = {shelfA, shelfB, shelfC};
    int counts[] = {3, 2, 4};
    int i, largest;

    for (i = 0; i < 3; i++) {
        printf("Shelf %c total: %d\n",
               'A' + i,
               sumShelf(shelves[i], counts[i]));
    }

    largest = findLargestShelf(counts, 3);

    printf("Shelf with the most books: %c\n", 'A' + largest);
    printf("Number of books: %d\n", counts[largest]);

    return 0;
}
