// (C) David, group: 3 (2024)
// Work package -
// Exercise -

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void copyString(char* destination, char* source);

int main(int argc, char *argv[]) {
    // Initializing variables
    char input[256]; // Buffer to store input
    char string[21];
    char string2[21];

    // Read input
    if (fgets(input, sizeof(input), stdin) != NULL) {
        int count = 0;
        char* ptr = input;
        while (*ptr != '\n' && *ptr != '\0' && count < 20) { //copy input into the string variable
            string[count] = *ptr;
            count++;
            ptr++;
        }
        string[count] = '\0'; // Null-terminate the string
    } else {
        printf("No input read.\n");
        return 1;
    }

    // Copy string from 'string' to 'string2'
    copyString(string2, string);

    // Print both strings
    printf("String: %s\n", string);
    printf("String2: %s\n", string2);

    return 0;
}

// Functions
void copyString(char* destination, char* source) {
    while (*source != '\0') { //copying a character at a time, until the end of the source string
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; // adding null-terminatior
}
