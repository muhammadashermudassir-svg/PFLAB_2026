
#include <stdio.h>

int square(int x) {
    return x * x;
}

int negate(int x) {
    return -x;
}

int isEven(int x) {
    return x % 2 == 0;
}

int isPositive(int x) {
    return x > 0;
}

void applyToArray(int *arr, int n, int (*fn)(int)) {
    int i;

    for (i = 0; i < n; i++) {
        arr[i] = fn(arr[i]);
    }
}

int countIf(const int *arr, int n, int (*pred)(int)) {
    int i, count = 0;

    for (i = 0; i < n; i++) {
        if (pred(arr[i])) {
            count++;
        }
    }

    return count;
}

void printGeneric(void *data, char type, int n) {
    int i;

    if (type == 'i') {
        int *p = (int *)data;

        for (i = 0; i < n; i++) {
            printf("%d ", p[i]);
        }
    }
    else if (type == 'f') {
        float *p = (float *)data;

        for (i = 0; i < n; i++) {
            printf("%.2f ", p[i]);
        }
    }
    else if (type == 'c') {
        char *p = (char *)data;

        for (i = 0; i < n; i++) {
            printf("%c ", p[i]);
        }
    }
    else {
        printf("Invalid type character");
    }

    printf("\n");
}

int main() {
    int arr[5] = {3, -2, 8, -5, 6};
    int n;

    do {
        printf("Enter n (1-50): ");
        scanf("%d", &n);

        if (n < 1 || n > 50) {
            printf("Invalid size\n");
        }
    } while (n < 1 || n > 50);

    if (n > 5) {
        printf("Array contains only 5 elements. Using n = 5.\n");
        n = 5;
    }

    printf("\nOriginal array: ");
    printGeneric(arr, 'i', n);

    printf("Even numbers: %d\n", countIf(arr, n, isEven));
    printf("Positive numbers: %d\n", countIf(arr, n, isPositive));

    applyToArray(arr, n, square);
    printf("After squaring: ");
    printGeneric(arr, 'i', n);

    applyToArray(arr, n, negate);
    printf("After negating: ");
    printGeneric(arr, 'i', n);

    {
        float values[] = {1.5f, 2.5f, 3.5f};
        char letters[] = {'A', 'B', 'C'};

        printf("Float values: ");
        printGeneric(values, 'f', 3);

        printf("Character values: ");
        printGeneric(letters, 'c', 3);
    }

    return 0;
}
