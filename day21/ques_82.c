#include <stdio.h>

int main() {

    char s[] = "hello";
    int n=5;

    for(int i=0; i<n/2; i++) {
        int tem = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = tem;
    }
    
    printf("the reverse is : ");

    for(int i=0; i<n; i++) {
        printf("%c ",s[i]);
    }

    return 0;
}