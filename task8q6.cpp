
#include <stdio.h>

int deposit(float *balance, float amount) {
    if (amount <= 0) {
        return 0;
    }

    *balance = *balance + amount;
    return 1;
}

int withdraw(float *balance, float amount) {
    if (amount <= 0 || amount > *balance) {
        return 0;
    }

    *balance = *balance - amount;
    return 1;
}

int main() {
    float balance = 1000.0, amount;
    int choice;

    do {
        printf("\n--- Bank Menu ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter deposit amount: ");
            scanf("%f", &amount);

            if (deposit(&balance, amount)) {
                printf("Deposit successful.\n");
            } else {
                printf("Invalid amount.\n");
            }
        }
        else if (choice == 2) {
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);

            if (withdraw(&balance, amount)) {
                printf("Withdrawal successful.\n");
            } else {
                printf("Invalid amount or insufficient balance.\n");
            }
        }
        else if (choice == 3) {
            printf("Current balance: %.2f\n", balance);
        }
        else if (choice == 4) {
            printf("Thank you for using the bank program.\n");
        }
        else {
            printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
