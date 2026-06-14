#include <stdio.h>

int main() {

    int size;
    int arr[size];
    int positiveCount = 0;
    int negativeCount = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 == 0 && arr[i] != 0) {
            positiveCount++;
        } else if(arr[i] % 2 != 0) {
            negativeCount++;
        }
    }

    printf("The number of positive elements in the array is: %d\n", positiveCount);
    printf("The number of negative elements in the array is: %d\n", negativeCount);

    return 0;
}