#include <stdio.h>

int main() {

    char s[] = "hello world";
    int count = 1;

    for(int i=0; s[i]!='\0'; i++) {
        if(s[i]==32) {
            count++;
        }
    }

    printf("the word in sentence is : %d",count);

    return 0;
}