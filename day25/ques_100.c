#include <stdio.h>
#include <string.h>

int main() {
    char words[4][20] = {"Elephant", "Cat", "Banana", "Ox"};
    int n = 4;
    char temp[20];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            
            if (strlen(words[i]) > strlen(words[j])) {
                
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    printf("Words sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (length: %lu)\n", words[i], strlen(words[i]));
    }

    return 0;
}
