#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 50

typedef struct {
    char name[30];
    char phone[15];
} Contact;

int main() {
    Contact directory[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    while (1) {
        printf("\n--- CONTACT MANAGEMENT SYSTEM ---\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (contactCount >= MAX_CONTACTS) {
                printf("Directory full! Cannot add more contacts.\n");
            } else {
                printf("\nEnter Name: ");
                fgets(directory[contactCount].name, sizeof(directory[contactCount].name), stdin);
                directory[contactCount].name[strcspn(directory[contactCount].name, "\n")] = '\0'; // Remove newline

                printf("Enter Phone Number: ");
                fgets(directory[contactCount].phone, sizeof(directory[contactCount].phone), stdin);
                directory[contactCount].phone[strcspn(directory[contactCount].phone, "\n")] = '\0'; // Remove newline

                contactCount++;
                printf("Contact added successfully!\n");
            }
        } 
        else if (choice == 2) {
            if (contactCount == 0) {
                printf("\nNo contacts found in your directory.\n");
            } else {
                printf("\n--- CONTACT LIST ---\n");
                for (int i = 0; i < contactCount; i++) {
                    printf("%d. Name: %s | Phone: %s\n", i + 1, directory[i].name, directory[i].phone);
                }
            }
        } 
        else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}
