#include <stdio.h>

int perfect_number(int num) {
    int sum = 0;
    
    for(int i = 1; i < num; i++) {
        if(num % i == 0) {
            sum += i;
        }
    }
    
    return sum == num;
}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    if(perfect_number(num)) {
        printf("%d is a perfect number.", num);
    } else {
        printf("%d is not a perfect number.", num);
    }

    return 0;
}