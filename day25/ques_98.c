#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "bella";
    char str2[] = "hello";
    
    int n = 5, m = 5;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(str1[i]==str2[j]) {
                printf("%c ",str1[i]);
                str2[j] = '#';
                break;
            }
        }
    }
    printf("\n");

    return 0;
}
