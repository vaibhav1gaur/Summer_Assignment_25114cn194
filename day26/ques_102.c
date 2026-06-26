#include <stdio.h>

int main() {

    int age;

    printf("=== Voting Eligibility System ===\n");
    printf("Enter your age: ");

    scanf("%d",&age);
    if(age >= 18) {
        printf("Yes! you are eligible");
    } else
    if(18 > age && age >= 0) {
        printf("No! you are not eligible");
    } else {
        printf("age can't be negative");
    }

    return 0;
}