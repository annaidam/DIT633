// (C) David, group: 3 (2024)
// Work package 1
// Excersise 3

//includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//global variables
int MAX_NUMBER = 10;
int randomNumber;
int tries = 0;
int guess = 0;

//function declarations
void startRound();
int makeGuess();
int askNewRound();

//main
int main(int argc, char *argv[]) {

    int exit = 0;

    while (exit != 1)
    {
        //sets up variables for the round
        startRound();


        //the game itself
        while (guess != randomNumber)
        {
            //checks if the user has run out of tries
            if (tries == MAX_NUMBER)
            {
                printf("you ran out of tries\n");
                break;
            }

            //asks the user for a guess
            guess = makeGuess();
            tries++;


            //compares the guess to the random number
            if (guess > randomNumber)
            {
                printf("Your guess is too high\n");
            } else if (guess < randomNumber)
            {
                printf("Your guess is too low\n");
            } else
            {
                printf("You have guessed %d times and your guess is correct\n", tries);
            }
            
        }

        //does a new round if the user wants to
        exit = askNewRound();
    }

    //return
    return 0;

}


//functions
void startRound() {
    
    srand(time(NULL));
    // Generate a random number between 1 and 100
    randomNumber = (rand() % 100) + 1;
    printf("\n");
    tries = 0;
    guess = 0;
}

int makeGuess() {
    int guess;

    printf("Please enter a number between 1 and 100: ");
    scanf("%d", &guess);

    if (guess >= 1 && guess <= 100) {
        return guess;
    } else {
        printf("invalid input\n");
        return makeGuess();
    }
}

int askNewRound() {
    char input;
    scanf("%c", &input);//by putting this here it prevents the program from skipping the input from asking the y/n twice, i think its because the enter from the previous scanf is still in the buffer, maybe there is a more elegant way to do it
    printf("would you like to play a new round? (y/n)\n");
    scanf("%c", &input);

    if (input == 'y' || input == 'Y')
    {
        return 0;
    } else if (input == 'n' || input == 'N')
    {
        return 1;
    } else
    {
        printf("invalid input\n");
        return askNewRound();
    }
}