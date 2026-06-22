#include <stdio.h>

int main() {

    char s[] = "hello world";
    int freq = 0;

    for(int i=0; s[i]!='\0'; i++) {
        if(s[i]==111) {
            freq++;
        }
    }

    printf("the frequency of character in word is : %d",freq);

    return 0;
}