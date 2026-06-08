#include <stdio.h>

int main() {

    int num;
    printf("enter a number = ");
    scanf("%d",&num);

    for(int i=0; i<num; i++) {
        for(int j=0; j<=i; j++) {
            printf("%c",(char)(j+65));
            printf(" ");
        }
        printf("\n");   
    }

    return 0;
}