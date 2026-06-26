#include <stdio.h>

int main() {

    char answer;
    int score = 0;

    printf("----WELCOME TO THE MINI QUIZ----\n\n");

    printf("1. What is the brain of computer system?\n");
    printf("A) RAM  B) Harddisk  C) CPU  D) GPU\n");
    printf("Your Answer(A/B/C/D): ");
    scanf(" %c", &answer);

    if(answer == 'C' || answer == 'c') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is C.\n");
    }

    printf("2. Which language is known for its simplicity?\n");
    printf("A) Java   B) C++   C) Python   D) Ruby\n");
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &answer);
    
    if (answer == 'C' || answer == 'c') {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong. The correct answer is C.\n\n");
    }

    printf("3. What does HTML stand for?\n");
    printf("A) Hyper Text Markup Language   B) High Text Machine Language\n");
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &answer);
    
    if (answer == 'A' || answer == 'a') {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong. The correct answer is A.\n\n");
    }

    printf("--------------------------------\n");
    printf("QUIZ OVER!\n");
    printf("Your Total Score: %d out of 3\n", score);
    printf("--------------------------------\n");

    return 0;
}