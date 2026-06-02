#include <stdio.h>

int main() {

    int numb;
    int rem;
    int pal = 0;
    int temp;

    scanf("%d",&numb);

    temp = numb;

    while(numb>0) {
        rem = numb % 10;
        pal = pal*10 + rem;
        numb = numb/10;
    }

    if(pal==temp) {
        printf("number is palindrome");
    } else {
        printf("number is not palidrome");
    }

    return 0;
}