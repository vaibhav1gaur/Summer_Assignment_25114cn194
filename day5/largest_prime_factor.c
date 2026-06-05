#include <stdio.h>

int main() {

    int num;
    int lar=0;
    printf("enter number = ");
    scanf("%d",&num);
    
    for(int i=2; i<=num/2; i++) {
        if(num%i==0) {
            if(i%2!=0) {
                lar = i;
            }
        }
    }
    printf("largest prime factor = %d",lar);

    return 0;
}