#include <stdio.h>

int main() {

    char s[] = "h e l l o";    
    int i=0, j=0;
    
    while(s[i] != '\0') {
        if(s[i] != 32) {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
    
    printf("after removing spaces the string is : ");
    for(int i=0; s[i]!='\0'; i++) {
        printf("%c",s[i]);
    }

    return 0;
}