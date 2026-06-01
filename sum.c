#include <stdio.h>

int main() {

    int numb;
    int sum=0;

    scanf("%d",&numb);

    for(int i=0; i<=numb; i++) {
        sum = sum + i;
    }

    printf("%d",sum);

    return 0;
}