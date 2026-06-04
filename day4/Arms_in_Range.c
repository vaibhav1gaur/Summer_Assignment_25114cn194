#include <stdio.h>

int main() {
    int lower, upper;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &lower, &upper);
    printf("Armstrong numbers between %d and %d are: ", lower, upper);
    for (int num = lower; num <= upper; num++) {
        int sum = 0, temp = num, digits = 0;
        while (temp > 0) {
            temp /= 10;
            digits++;
        }
        temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            sum += pow(digit, digits);
            temp /= 10;
        }
        if (sum == num) {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}