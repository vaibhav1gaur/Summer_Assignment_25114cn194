#include <stdio.h>
#include <string.h>

void compressString(char src[], char dest[]) {
    int srcLen = strlen(src);
    int destIdx = 0;

    for (int i = 0; i < srcLen; i++) {
        dest[destIdx++] = src[i];

        int count = 1;
        while (i + 1 < srcLen && src[i] == src[i + 1]) {
            count++;
            i++;
        }

        destIdx += sprintf(&dest[destIdx], "%d", count);
    }

    dest[destIdx] = '\0';

    if (strlen(dest) >= srcLen) {
        strcpy(dest, src);
    }
}

int main() {
    char input[] = "AAAABBBCC";
    char compressed[100];

    compressString(input, compressed);

    printf("Original:   %s\n", input);
    printf("Compressed: %s\n", compressed);

    return 0;
}
