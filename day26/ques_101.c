#include <stdio.h>

int main() {
    int secret_number = 45;
    int guess;

    printf("Guess the secret number (between 1 and 100):\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess > secret_number) {
            printf("Too high! Try again.\n\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n\n");
        } else {
            printf("Correct! You win!\n");
            break;
        }
    }

    return 0;
}
