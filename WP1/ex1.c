// (C) David Schön, Milena Mackowiak, Anna Mäkinen, group: 3 (2024)
// Work package 1
// Exercise 1
// Submission code: 415678 (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    // Array of five unique sentences
    const char* sentences[5] = {
        "The dog was red?!?!",
        "He was a good dog.",
        "One might say the goodest of boys.",
        "Furthermore, he was... BIG.",
        "His name is Clifford :)"
    };

    int input;
    int done = 0;

    while (!done)
    {
        printf("Please enter a number between 1 and 5: ");
        scanf("%d", &input);

        if (input < 1 || input > 5) {
            printf("exiting\n");
            done = 1;
        } else {
            printf("%s\n", sentences[input - 1]);
        }
    }
    return 0;

}

