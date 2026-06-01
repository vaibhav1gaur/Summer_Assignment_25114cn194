#include <stdio.h>

int main() {

    int num;

    printf("eneter num = ");
    scanf("%d",&num);

    int result = 0;

    while(num>0) {
        int rem = num%10;
        result = result*10+rem;
        num = num/10;
    }

    printf("answer is %d",result);

    return 0;
}