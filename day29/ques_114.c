#include <stdio.h>

int main() {
    int arr[100];
    int size = 0;
    int choice, i, element, pos;

    while (1) {
        // Display Menu
        printf("\n--- Array Operations ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting... Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                if (size >= 100) {
                    printf("Array is full!\n");
                } else {
                    printf("Enter element to insert: ");
                    scanf("%d", &element);
                    printf("Enter index position (0 to %d): ", size);
                    scanf("%d", &pos);

                    if (pos < 0 || pos > size) {
                        printf("Invalid position!\n");
                    } else {
                        for (i = size; i > pos; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[pos] = element;
                        size++;
                        printf("Element inserted!\n");
                    }
                }
                break;

            case 2:
                if (size == 0) {
                    printf("Array is empty!\n");
                } else {
                    printf("Enter index position to delete (0 to %d): ", size - 1);
                    scanf("%d", &pos);

                    if (pos < 0 || pos >= size) {
                        printf("Invalid position!\n");
                    } else {
                        for (i = pos; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        printf("Element deleted!\n");
                    }
                }
                break;

            case 3:
                if (size == 0) {
                    printf("Array is empty!\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
