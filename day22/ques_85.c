#include <stdio.h>
#include <string.h>


int main() {

    char s[] = "racecar";
    int is_palindrome = 1;
    int l = strlen(s);

    for(int i=0; i<l/2; i++) {
        if(s[i] != s[l-1-i]) {
            is_palindrome = -1;
            break;
        }
    }

    if(is_palindrome == 1) {
        printf("palindrome");
    } else {
        printf("not-palindrome");
    }
 
    return 0;
}