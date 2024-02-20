#include <stdio.h>
#include <string.h>

#define MAX_CHARACTERS 10

void generatePermutations(char** permutations, char* input, int characters);

int main(int argc, char *argv[]) {
    char** permutations = malloc(1000 * sizeof(char*)); // Allocating space for 1000 char pointers
    if (permutations == NULL) {
        printf("error");
        return 0;
    }

    for (int i = 0; i < 1000; i++) {
        permutations[i] = malloc(MAX_CHARACTERS * sizeof(char)); // Allocating space for each string
        if (permutations[i] == NULL) {
            printf("error");
            return 0;
        }
    }

    // Ensure only one argument is provided
    if (argc != 2) {
        printf("Invalid input: Please provide a single string argument.\n");
        return 0;
    }

    char *inputString = argv[1];
    // Check if the input string is too long
    if (strlen(inputString) > MAX_CHARACTERS) {
        printf("invalid");
        return 0;
    }

    int characters = strlen(inputString);
    generatePermutations(permutations, inputString, characters);

    while (permutations != NULL && permutations != '\0')
    {
        printf("%s", *permutations);
        *permutations++;
    }
    
    
    for (int i = 0; i < 1000; i++) {
        free(permutations[i]); // Freeing each string
    }

    free(permutations); // Freeing the array of pointers
    return 0;
}

void generatePermutations(char** permutations, char* input, int characters) {
    //printf(":D");
}