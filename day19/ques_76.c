#include <stdio.h>

void diagonal_sum(int arr[3][3]) {
    int sum =0;
    for (int i = 0; i < 3; i++) {
        sum += arr[i][i];
    }
    printf("Sum of diagonal elements: %d\n", sum);
}

int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    diagonal_sum(arr);
    return 0;
}