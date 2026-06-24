#include <stdio.h>
#include <string.h>

int main() {
    char sentence[] = "Coding in C is incredibly powerful and fun";
    char currentWord[50];
    char longestWord[50] = "";
    int offset = 0;
    int bytesRead;

    while (sscanf(sentence + offset, "%s%n", currentWord, &bytesRead) == 1) {
        
        if (strlen(currentWord) > strlen(longestWord)) {
            strcpy(longestWord, currentWord);
        }
        
        offset += bytesRead;
    }

    printf("Sentence:     %s\n", sentence);
    printf("Longest Word: %s\n", longestWord);

    return 0;
}

