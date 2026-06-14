#include <stdio.h>

int main() {

    int arr[] = {1, 2, 3, 4, 1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int freq = 0;
    int num;
    printf("Enter a number to find its frequency: ");
    scanf("%d", &num);

    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            freq++;
        }
    }

    printf("Frequency of %d is: %d\n", num, freq);

    return 0;
}