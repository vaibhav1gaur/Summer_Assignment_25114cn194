#include <stdio.h>

int main() {

    int numb;
    int count = 0;

    scanf("%d",&numb);

    while(numb>0) {
        numb = numb/10;
        count++;
    }

    printf("%d",count);

    return 0;
}