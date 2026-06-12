#include <stdio.h>

int palindrome(int num) {
    int original_num = num;
    int reversed_num = 0;
    
    while(num > 0) {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }
    
    return original_num == reversed_num;
}

int main() {
    
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    
    if(palindrome(num)) {
        printf("%d is a palindrome number.", num);
    } else {
        printf("%d is not a palindrome number.", num);
    }
    
    return 0;
}