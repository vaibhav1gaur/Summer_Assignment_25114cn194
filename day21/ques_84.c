#include <stdio.h>

int main() {

    char s[] = "helloworld";

    for(int i=0; s[i]!='\0'; i++) {
        s[i] -= 32;
    }

    for(int i=0; s[i]!='\0'; i++) {
        printf("%c",s[i]);
    }


    return 0;
}