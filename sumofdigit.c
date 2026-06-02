#include <stdio.h>

int main() {

    int numb;
    int rem;
    int sum = 0;

    scanf("%d",&numb);

    while(numb>0) {
        rem = numb % 10;
        sum = sum + rem;
        numb = numb/10;
    }

    printf("%d",sum);

    return 0;
}