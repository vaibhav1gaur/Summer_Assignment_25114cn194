#include <stdio.h>

int main() {
    
    int size;
    int arr[size];
    int avg;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    avg = sum / size;

    printf("The average of the array elements is: %d\n", avg);
    printf("The sum of the array elements is: %d\n", sum);

    return 0;
}