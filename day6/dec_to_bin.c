#include <stdio.h>

int main() {

    int num, rem, bin = 0;

    printf("enter decimal number = ");
    scanf("%d",&num);

    while(num>0) {
        rem = num % 2;
        bin = bin * 10 + rem;
        num = num / 2;
    }

    printf("binary number = %d",bin);

    return 0;
}