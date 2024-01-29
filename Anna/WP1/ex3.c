#include <stdio.h>
#include <stdlib.h>

// A function for the actual guessing
int guessingGame() {
    // num creates a random number at max 100 using rand() from stdlib
    int num = rand() % 101;
    int guess;
    int numOfGuesses = 0;

    // While the guess is incorrect and the number of guesses is less than 16
    do {
        printf("Your guess: ");
        scanf("%d", &guess);
        numOfGuesses++; // After every guess the number of guesses grows by one

        // If the guess is correct
        if (guess == num) {
            printf("\nYou have guessed %d times and your guess is correct :)\n", numOfGuesses);
        } else if (guess < num) { // If the guess is too low
            printf("\nYou have guessed %d times and your guess is too low :(\n", numOfGuesses);
        } else { // If the guess is too high
            printf("\nYou have guessed %d times and your guess is too high :(\n", numOfGuesses);
        }
    } while ((guess != num) && (numOfGuesses < 16));

    return 0;
}

int main() {
    // User's answer to question if they want to play again
    int ans;

    printf("Welcome to the Guessing Game!\n");
    printf("I have created a number between 1–100, try to guess it within 15 guesses.\n");

    // Call the guessingGame function until the user answers 1 to the question
    do {
        guessingGame();

        printf("\nDo you want to play again (1) or exit the game? (9)\n");
        scanf("%d", &ans);
    } while (ans == 1);

    return 0;

}