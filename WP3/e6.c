// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 3
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)


#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20

void copyString(char file[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        file[i] = src[i];
        i++;
    }
    file[i] = '\0';
}

int main(int argc, char *argv[]) {
    
    char input[MAX_LENGTH];
    char copied[MAX_LENGTH];

    if (argc == 2 && strcmp(argv[1], "-f") == 0) {
        // Read from redirected input file
        fgets(input, MAX_LENGTH, stdin);
        // Remove newline character if present
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';
    } else {
        // Read from keyboard
        printf("Enter a string (max 20 characters): ");
        fgets(input, MAX_LENGTH, stdin);
        // Remove newline character if present
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';
    }

    // Using library function strcpy
    strcpy(copied, input);
    printf("Using strcpy: %s\n", copied);

    // Using custom function
    copyString(copied, input);
    printf("Using custom function: %s\n", copied);

    return 0;
}
