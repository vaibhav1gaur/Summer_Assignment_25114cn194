#include <stdio.h>

int missing(int arr[], int sz) {

    int digit = 1;
    for(int i=0; i<sz; i++) {
        if(arr[i] != digit) {
            return digit;
        }
        digit++;
    }
    return digit;
}

int main() {

    int arr[] = {1, 2, 3, 5};
    int sz = sizeof(arr) / sizeof(arr[0]);

    int miss = missing(arr, sz);
    printf("Missing number is: %d\n", miss);

    return 0;
}