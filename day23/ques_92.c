#include <stdio.h>

int main() {
    char str[] = "test string";
    int count[256] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }

    char max_char = str[0];
    int max_count = 0;

    for (int i = 0; i < 256; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_char = (char)i;
        }
    }

    printf("Maximum occurring character is: '%c'\n", max_char);

    return 0;
}

