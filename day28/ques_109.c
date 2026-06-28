#include <stdio.h>

int main() {
    char bookTitle[] = "The Great Gatsby";
    int isAvailable = 1;
    int choice;

    while (1) {
        printf("\n--- MINI LIBRARY ---\n");
        printf("Book: %s\n", bookTitle);
        printf("Status: %s\n", isAvailable ? "Available" : "Borrowed");
        printf("--------------------\n");
        printf("1. Borrow Book\n");
        printf("2. Return Book\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (isAvailable == 1) {
                isAvailable = 0;
                printf("Success! You borrowed the book.\n");
            } else {
                printf("Error: The book is already borrowed!\n");
            }
        } 
        else if (choice == 2) {
            if (isAvailable == 0) {
                isAvailable = 1;
                printf("Success! Book returned to the library.\n");
            } else {
                printf("The book is already in the library!\n");
            }
        } 
        else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
