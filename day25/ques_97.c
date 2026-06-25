#include <stdio.h>

int main() {

    int arr1[] = {1,3,5,7};
    int arr2[] = {2,4,6,8};
    int arr[100];
    int n= 4;

    for(int i=0; i<n; i++) {
        arr[i] = arr1[i];
    }
    for(int i=0; i<n; i++) {
        arr[i+n] = arr2[i];
    }

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i=0; i<(n+n); i++) {
        printf("%d ",arr[i]);
    }

    return 0;
}