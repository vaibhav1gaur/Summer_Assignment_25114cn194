#include <stdio.h>

int main() {

    int size;
    int arr[size];
    int linearSearch;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &linearSearch);

    for(int i = 0; i < size; i++) {
        if(arr[i] == linearSearch) {
            printf("Element found at index: %d\n", i);
            break;
        }
        if(i == size - 1) {
            printf("Element not found in the array.\n");
        }
    }

    return 0;
}