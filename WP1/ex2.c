// (C) David Schön, Milena Mackowiak, Anna Mäkinen, group: 3 (2024)
// Work package 1
// Exercise 2
// Submission code: 415678 (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *pointer, int key);

int main(int argc, char *argv[]) {

    //checks that there is an argument
    if (argc < 2) {
        printf("Please provide a cypher key as an argument.\n");
        return 1;
    }

    //converts the argument to an int
    int cypherKey = strtol(argv[1], NULL, 10);

    //asks for input to encrypt and stores it in input
    char input[100];
    printf("Enter a string to encrypt: ");
    scanf("%s", input);

    //creates a pointer to the first byte of the input
    char *cPointer=input;


    //encrypting input one letter at a time
    while (*cPointer != '\0')
    {
        encrypt(cPointer, cypherKey);
        cPointer++;
    }
    printf("%s\n", input);
    
    return 0;
}

//basically ceaser cypher on a single letter
void encrypt(char* pointer, int key) {

    // Check if the character is a letter
    if (('A' <= *pointer && *pointer <= 'Z') || ('a' <= *pointer && *pointer <= 'z')) {
        char base = 'A';  // Base character for uppercase
        if ('a' <= *pointer) {
            base = 'a';  // Base character for lowercase
        }

        // Shift the letter and wrap around the alphabet
        *pointer = (*pointer - base + key) % 26 + base;
    }
}