#include <stdio.h>

int main() {

    int size;
    int arr[size];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for(int i=0; i<size; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}