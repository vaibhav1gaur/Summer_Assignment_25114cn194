#include <stdio.h>

int main() {
    
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=0+1; j<=i; j++) {
            printf(" ");
        }
        for(int j=n; j>i; j--) {
            printf("*");
        }
        for(int j=n-1; j>i; j--) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}