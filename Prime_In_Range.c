#include <stdio.h>

int main() {

    int lower, upper;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &lower, &upper);

    printf("Prime numbers between %d and %d are: ", lower, upper);
    for (int num = lower; num <= upper; num++) {
        if (num > 1) {
            int is_prime = 1; // Assume num is prime
            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    is_prime = 0; // num is not prime
                    break;
                }
            }
            if (is_prime) {
                printf("%d ", num);
            }
        }
    }

    printf("\n");

    return 0;
}