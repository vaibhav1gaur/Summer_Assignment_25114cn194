#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkAnagram(char *str1, char *str2) {
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    int count[256] = {0};

    for (int i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char str1[] = "listen";
    char str2[] = "silent";

    if (checkAnagram(str1, str2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", str1, str2);
    }

    return 0;
}
