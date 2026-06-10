#include <stdio.h>

int main() {
    
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i; j++) {
            printf(" ");
        }
        for(int j=0; j<+i+1; j++) {
            printf("%c",(j+'A'));
        }
        for(int j=i; j>0; j--) {
            printf("%c",(j+'A'-1));
        }
        printf("\n");
    }
    
    return 0;
}