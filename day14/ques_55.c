#include <stdio.h>

int main() {

    int arr[] = {1, 2, 3, 4, 1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int second_largest = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] > second_largest) {
            second_largest = arr[i];
        }
    }

    printf("Second largest element is: %d\n", second_largest);

    return 0;
}