#include <stdio.h>
#include <string.h>

char findFirstRepeating(char *str) {
    int visited[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];
        
        if (visited[ch] == 1) {
            return ch;
        }
        
        visited[ch] = 1;
    }
    
    return '\0'; 
}

int main() {
    char str[] = "abcdefba";
    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("The first character to repeat itself is: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}
