#include <stdio.h>

int main() {

    const int STORED_PIN = 1234;
    double balance = 10000.00;
    int pin_attemptes = 3;
    int entered_pin;
    int choice;
    double amount;

    while (pin_attemptes > 0) {
        printf("Enter Your 4-digit PIN : ");
        if(scanf("%d", &entered_pin) != 1) {
            printf("Invalid Input.");
            while(getchar() != '\n');
            continue;
        }

        if(entered_pin == STORED_PIN) {
            printf("\nlogin successful! Welcome to the ATM.\n");
            break;
        } else {
            pin_attemptes--;
            printf("Incorrect PIN. You have %d attemptes left.\n",pin_attemptes);
        }
    }

    if(pin_attemptes==0) {
        printf("Too many Incorrect attemptes. Your card is temporary locked\n");
        return 0;
    }

    while(1) {
        printf("\n========================\n");
        printf("       ATM MAIN MENU    \n");
        printf("========================\n");
        printf("1. Check Balance\n");
        printf("2. Deposite Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("\nSelect Option From (1-4): ");

        if(scanf("%d", &choice) != 1) {
            printf("Invalid choice! Pleae Entered a Number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {

            case 1: 
                printf("\nYour current balance is : $%.2f\n",balance);
                break;

            case 2:
                printf("\nEnter amount to deposit : $");
                if(scanf("%lf", &amount) != 1) {
                    printf("Invalid format. Transaction cancelled.\n");
                    while(getchar() != '\n');
                    break;
                }
                if(amount > 0) {
                    balance += amount;
                    printf("Success ! Your deposit : $%.2f\n",amount);
                    printf("New balance : $%.2f\n",balance);
                } else {
                    printf("Error ! Deposit amount must be greater than zero.\n");
                }
                break;

            case 3:
               printf("\nEntered amount to withdraw : $");
               if(scanf("%lf", &amount) != 1) {
                printf("Invalid format. transaction cancelled.\n");
                while(getchar() != '\n');
                break;
               }
               if(amount > 0) {
                if(amount <= balance) {
                    balance -= amount;
                    printf("success! Please collect your cash : $%.2f\n",amount);
                    printf("Remaining balance: $%.2f\n",balance);
                } else {
                    printf("Error: Insufficient fund.\n");
                }
               } else {
                printf("Error: Withdrawl amount must be greater than zero.\n");
               }
               break;

            case 4:
                printf("\nThanks for using the ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select an option between 1 and 4.\n");
        }
 
   }


    return 0;
}