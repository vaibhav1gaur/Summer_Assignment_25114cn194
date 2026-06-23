#include <stdio.h>
#include <string.h>

void non_repeating(char s[], int l) {
    int count[256] = {0};

    for (int i = 0; i < l; i++) {
        count[(unsigned char)s[i]]++;
    }

    for (int i = 0; i < l; i++) {
        if (count[(unsigned char)s[i]] == 1) {
            printf("The first non-repeating character is: %c\n", s[i]);
            return;
        }
    }

    printf("All characters are repeating.\n");
}

int main() {
    char s[] = "helloworld";
    int l = strlen(s);
    
    non_repeating(s, l);

    return 0;
}
