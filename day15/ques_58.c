#include <stdio.h>

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    for(int i=0; i<d; i++) {
        int tem = arr[0];
        for(int j=0; j<sz-1; j++) {
            arr[j] = arr[j+1];
        }
        arr[sz-1] = tem;
    }

    printf("Array after left rotation: ");
    for(int i=0; i<sz; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}