#include <stdio.h>
#include <stdlib.h>

void show_menu() {
    printf("\n--- Menu-Driven Calculator ---\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        show_menu();
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 5) {
            printf("Exiting calculator... Goodbye!\n");
            break;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter first number: ");
            if (scanf("%lf", &num1) != 1) {
                printf("Invalid number!\n");
                while (getchar() != '\n');
                continue;
            }

            printf("Enter second number: ");
            if (scanf("%lf", &num2) != 1) {
                printf("Invalid number!\n");
                while (getchar() != '\n');
                continue;
            }

            switch (choice) {
                case 1:
                    result = num1 + num2;
                    printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                    break;
                case 2:
                    result = num1 - num2;
                    printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                    break;
                case 3:
                    result = num1 * num2;
                    printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                    break;
                case 4:
                    if (num2 == 0) {
                        printf("Error! Division by zero is not allowed.\n");
                    } else {
                        result = num1 / num2;
                        printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                    }
                    break;
            }
        } else {
            printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    }

    return 0;
}
