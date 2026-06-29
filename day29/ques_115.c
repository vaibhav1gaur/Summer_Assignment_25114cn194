#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int choice;

    while (1) {
         printf("\n--- String Operations Menu ---\n");
        printf("1. Find Length of String\n");
        printf("2. Copy String\n");
        printf("3. Concatenate (Combine) Strings\n");
        printf("4. Compare Two Strings\n");
        printf("5. Reverse a String\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        getchar();

        if (choice == 6) {
            printf("Exiting program... Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                gets(str1);
                printf("Length of the string is: %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter source string: ");
                gets(str1);
                strcpy(str2, str1);
                printf("Copied! New string is: %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                gets(str1);
                printf("Enter second string: ");
                gets(str2);
                strcat(str1, str2);
                printf("Combined string: %s\n", str1);
                break;

            case 4:
                printf("Enter first string: ");
                gets(str1);
                printf("Enter second string: ");
                gets(str2);
                if (strcmp(str1, str2) == 0) {
                    printf("Both strings are exactly equal.\n");
                } else {
                    printf("Strings are not equal.\n");
                }
                break;

            case 5:
                printf("Enter a string: ");
                gets(str1);
                printf("Reversed string: ");
                for (int i = strlen(str1) - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}