#include <stdio.h>

int main() {

    int numb;
    int rem;
    int prod = 1;

    scanf("%d",&numb);

    while(numb>0) {
        rem = numb % 10;
        prod = prod * rem;
        numb = numb / 10;
    }

    printf("%d",prod);

    return 0;
}