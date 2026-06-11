#include <stdio.h>

int max(int num1, int num2) {
    if(num1>num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    
    printf("%d",max(62,48));
    
    return 0;
}