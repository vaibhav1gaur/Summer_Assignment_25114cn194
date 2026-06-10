#include <stdio.h>

int main() {
    
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i; j++) {
            printf(" ");
        }
        for(int j=0; j<i+1; j++) {
            printf("%d",j+1);
        }
        for(int j=i; j>0; j--) {
            printf("%d",j);
        }
        printf("\n");
    }
    
    return 0;
}