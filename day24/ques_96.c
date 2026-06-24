#include <stdio.h>

int main() {
    char str[] = "programming";
    int writeIndex = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        int isDuplicate = 0;

        for (int j = 0; j < writeIndex; j++) {
            if (str[i] == str[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if (isDuplicate == 0) {
            str[writeIndex] = str[i];
            writeIndex++;
        }
    }

    str[writeIndex] = '\0';

    printf("Result: %s\n", str);

    return 0;
}
