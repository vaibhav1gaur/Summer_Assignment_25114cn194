#include <stdio.h>

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int right_shift = 2;

    for(int i=0; i<right_shift; i++) {
        int temp = arr[size-1];
        for(int j=size-1; j>0; j--) {
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }

    printf("Array after right rotation: ");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}