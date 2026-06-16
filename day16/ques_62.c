#include <stdio.h>

void max_frequency(int arr[], int n) {
    int max_count = 0;
    int max_element = arr[0];

    for(int i=0; i<n; i++) {
        int count = 1;
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }

    printf("Element with maximum frequency: %d (Frequency: %d)\n", max_element, max_count);
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    max_frequency(arr, n);

    return 0;
}