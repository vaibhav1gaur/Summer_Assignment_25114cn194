#include <stdio.h>

void union_arr(int arr1[], int arr2[], int n1, int n2, int arr3[], int *n3) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else if (arr1[i] > arr2[j]) {
            arr3[k++] = arr2[j++];
        } else {
            arr3[k++] = arr1[i++];
            j++;
        }
    }

    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    while (j < n2) {
        arr3[k++] = arr2[j++];
    }

    *n3 = k; // Update the size of the union array
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[n1 + n2]; // Maximum possible size of union
    int n3; // Size of the union array

    union_arr(arr1, arr2, n1, n2, arr3, &n3);

    printf("Union of the two arrays: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}