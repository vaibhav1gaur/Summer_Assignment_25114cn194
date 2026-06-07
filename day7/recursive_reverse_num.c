#include <stdio.h>

int rev(int n) {
    int rev = 0,rem;
    while(n>0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    return rev;
}

int main() {
    int n;
    printf("reverse is %d",rev(823));
    return 0;
}