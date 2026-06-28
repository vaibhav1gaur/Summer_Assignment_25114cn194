#include <stdio.h>

int main() {
    int accountNumber = 1001;
    double balance = 500.0;
    int choice;
    double amount;

    while (1) {
        printf("\n--- MY BANK ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Account %d Balance: $%.2f\n", accountNumber, balance);
        } 
        else if (choice == 2) {
            printf("Enter deposit amount: ");
            scanf("%lf", &amount);
            balance += amount;
            printf("Deposited $%.2f. New Balance: $%.2f\n", amount, balance);
        } 
        else if (choice == 3) {
            printf("Enter withdrawal amount: ");
            scanf("%lf", &amount);
            if (amount > balance) {
                printf("Error: Insufficient funds!\n");
            } else {
                balance -= amount;
                printf("Withdrew $%.2f. New Balance: $%.2f\n", amount, balance);
            }
        } 
        else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
