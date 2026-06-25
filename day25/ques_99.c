#include <stdio.h>
#include <string.h>

int main() {

    char name[5][20] = {"amit","harsh","sumit","aman","namit"};
    int n = 5;
    char temp[20];

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(strcmp(name[i],name[j])>0) {
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
        }
    }

    printf("Names in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", name[i]);
    }

    return 0;
}