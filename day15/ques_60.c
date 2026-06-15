#include <stdio.h>

int main() {

    int arr[] = {1, 2, 0, 3, 0, 4, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[size - 1] = 0;
            size--;
            i--;
        }
    }

    printf("Array after moving zeros to the end: ");
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}