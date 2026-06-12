#include <stdio.h>

int armstrong(int num) {
    int original_num = num;
    int sum = 0;
    
    while(num > 0) {
        int digit = num % 10;
        sum += digit * digit * digit;
        num /= 10;
    }
    
    return original_num == sum;
}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    if(armstrong(num)) {
        printf("%d is an Armstrong number.", num);
    } else {
        printf("%d is not an Armstrong number.", num);
    }

    return 0;
}