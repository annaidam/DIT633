// (C) Anna Mäkinen, David Schön, Milena Maćkowiak, group: 3 (2024)
// Work package 3
// Exercise 6
// Submission code: 9IL6WF (provided by your TA-s)

#include <stdio.h>
#include <string.h>

// funcrtion to copy the string manually
void copyString(char copyF[], char input[]) {
    int i = 0;

    // while the input in i is not null
    while (input[i] != '\0') {
        // copy the character in input[i] to matching slot in copyF
        copyF[i] = input[i];
        // increase i by one
        i++;
    }
    // set the last character to end of the string
    copyF[i] = '\0';
}

// main function
int main () {
    char input[20]; // input by user
    char copyLib[20]; // string copied via library
    char copyF[20]; // string copied via function

    printf("Enter a string (between 1 and 20 characters): ");
    // check if the input is not empty
    if (scanf("%[^\n]", input) == 1) {
        strcpy(copyLib, input); // copy with library
        copyString(copyF, input); // copy with function
        // if the input is empty it's invalid
    } else {
        printf("\nInvalid input\n");
        return 1;
    }

    // print the strings
    printf("\nThe string copied with library is '%s'\n", copyLib);
    printf("The string copied with function is '%s'\n", copyF);

    return 0;
}