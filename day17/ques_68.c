#include <stdio.h>

void common_elements(int arr1[], int arr2[], int n1, int n2, int arr3[], int *n3) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            arr3[k++] = arr1[i++];
            j++;
        }
    }

    *n3 = k; // Update the size of the common elements array
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[n1 < n2 ? n1 : n2]; // Maximum possible size of common elements
    int n3; // Size of the common elements array

    common_elements(arr1, arr2, n1, n2, arr3, &n3);

    printf("Common elements of the two arrays: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}