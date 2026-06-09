#include <stdio.h>

int main() {
    int num;
    printf("enter a number = ");
    scanf("%d",&num);

    for(int i=0; i<num; i++) {
        for(int j=1; j<=num-i; j++) {
            printf("%d ",j);
        }
        printf("\n");
    }


    return 0;
}