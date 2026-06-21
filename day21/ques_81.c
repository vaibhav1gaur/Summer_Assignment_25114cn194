#include <stdio.h>

int main() {

    char s[] = "hello world";
    int length = 0;
    

    for(int i=0; s[i]!='\0'; i++) {
        length++;
    }

    printf("the size of string is : %d",length);

    return 0;
}