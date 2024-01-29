#include <stdio.h>

// Main
int main (int argc, char *argv[]) {
    // Declaring integer to save the number of characters used
    int numChar = argc;
    // Declaring the word that the user will input, with the max of 50 characters
    char word[50];

    // Ask user to print a word and save it to char
    printf("\nWelcome!\nEnter the word you want to be encrypted:\n");
    scanf("%s", word);

    // Check for every letter in the word that the user entered
    for (int i=0; word[i] != '\0'; i++) {
        char currentChar = word[i]; // The current letter in the word
        int charInt = currentChar; // Converting the current letter into an integer by ASCII
        // The corresponding letter in the alphabet will be the number of the current letter + the number of characters passed as an argument
        int newCharInt = charInt + numChar;
        char newChar = newCharInt; // Converting the number of the letter back to char
        printf("%c", newChar); // Printing the char
    }

    // After printing the entire word encrypted, the program stops
    printf("\n\nExiting program...");
    return 0;
}