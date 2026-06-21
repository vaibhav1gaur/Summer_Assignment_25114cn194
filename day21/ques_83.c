#include <stdio.h>

int main() {

    char s[] = "hello world";
    int vow=0, con=0;
    
    for(int i=0; s[i]!='\0'; i++) {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
               vow++;
            } else {
               con++;
            }
        }
    }

    printf("number of vowel is : %d\nnumber of consonants is : %d",vow,con);

    return 0; 
}