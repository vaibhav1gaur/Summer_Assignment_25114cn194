#include <stdio.h>

void binary_search(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        
        if (arr[m] == x) {
            printf("Element found at index %d\n", m);
            return;
        }

        
        if (arr[m] < x) {
            l = m + 1;
        }
        
        else {
            r = m - 1;
        }
    }

    
    printf("Element not found in array\n");
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    printf("Array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    binary_search(arr, 0, n - 1, x);
    return 0;
}