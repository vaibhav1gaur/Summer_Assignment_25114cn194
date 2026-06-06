#include <stdio.h>

int main() {

    int n, x, pow = 1;

    printf("enter base = ");
    scanf("%d",&x);

    printf("enter exponent = ");
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        pow = pow * x;
    }

    printf("result = %d",pow);


    return 0;
}