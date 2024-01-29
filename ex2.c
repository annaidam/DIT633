// (C) David, group: 3 (2024)
// Work package 1
// Excersise 2
// Submission code: XXXXXX (provided by your TA-s)
#include <stdio.h>
#include <stdlib.h>

void encrypt(char *pointer, int key);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Please provide a cypher key as an argument.\n");
        return 1;
    }

    int cypherKey = strtol(argv[1], NULL, 10);
    int exit = 0;
    char input[100];

    while (exit != 1)
    {
        scanf("%s", input);

        if (*input == EOF)
        {
            exit = 1;
            break;//i think the exit + the break is a bit redundant but idk
        }
        
        char *cPointer=input;


        //encrypting input one letter at a time
        while (*cPointer != '\0')
        {
            encrypt(cPointer, cypherKey);
            cPointer++;
        }
        printf("%s\n", input);

        
    }
    

}

//ceaser cypher
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