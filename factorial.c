#include <stdio.h>

int main() {

    int numb;
    int fact = 1;

    scanf("enter the number : %d",&numb);

    for(int i=1; i<=numb; i++) {
        fact = fact * i;
    }

    printf("factorial is : %d",fact);

    return 0;
}