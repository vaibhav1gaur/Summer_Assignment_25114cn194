#include <stdio.h>

int main() {

    int arr[] = {1, 2, 3, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int duplicate = -1;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                duplicate = arr[i];
                break;
            }
        }
        if (duplicate != -1) {
            break;
        }
    }

    printf("Duplicate element: %d\n", duplicate);

    return 0;
}