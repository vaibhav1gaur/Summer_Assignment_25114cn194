#include <stdio.h>
#include <string.h>

int isRotation(char s1[], char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) {
        return 0;
    }

    char temp[100]; 

    strcpy(temp, s1);
    strcat(temp, s1);

    if (strstr(temp, s2) != NULL) {
        return 1;
    }

    return 0;
}

int main() {
    char string1[] = "ABCD";
    char string2[] = "CDAB";

    if (isRotation(string1, string2)) {
        printf("Yes, it is a rotation.\n");
    } else {
        printf("No, it is not a rotation.\n");
    }

    return 0;
}
