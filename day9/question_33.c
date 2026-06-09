#include <stdio.h>

int main() {

    int num;
    printf("enter a number = ");
    scanf("%d",&num);

    for(int i=0; i<num; i++) {
        for(int j=num-i; j>0; j--) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}