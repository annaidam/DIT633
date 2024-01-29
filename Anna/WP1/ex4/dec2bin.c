#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert the decimal to binary
void convert_binary(int number) {
    // Printing the entered number and the beginning of the binary number
    printf("Number: %d\nBinary: ", number);

    // If the entered number is 0, then the binary is also just 0
    if (number == 0) {
        printf("0");
    }

    long binary[64]; // Array to store the binary representation
    int i = 0; 
    int counter = 0;

    // Check for every number of the decimal
    for (int i = 0; number > 0; i++) {
        binary[i] = number % 2; // Set the number to the remainder
        number = number / 2; // Divide the number by 2
        counter++;
    }

    // Check which number of bits should be used
    if (counter > 32) {
        for(int i = 63; i >= 0; i--)    {
            printf("%ld", binary[i]); 
        } 
    } else if (counter > 16) {
        for(int i = 31; i >= 0; i--)    {
            printf("%ld", binary[i]); 
        } 
    } else if (counter > 8) {
        for(int i = 15; i >= 0; i--)    {
            printf("%ld", binary[i]); 
        } 
    } else {
      for(i = 7; i >= 0; i--) { 
            printf("%ld", binary[i]); 
        }
    }
}


int main(int argc, char *argv[]) {
    int isNum = 1;
    char *arg = argv[1];

    if (argc < 2) {
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        return 0;
    }

    // Check if all characters in the argument are numbers
    for (int i = 0; arg[i] != '\0'; i++) {
        if (!isdigit(arg[i])) {
            isNum = 0;
            break;
        }
    }
    // If not all of the characters are numbers
    if (!isNum) {
        printf("Error: Invalid number.\n");
        return 0;
    }

    // Converting the argument to long
    long number = atoi(arg);

    // If the passed argument is less than 0
    if (number < 0) {
        printf("\nYou have to enter one positive number\n");
    } else { // If not, call the function
        convert_binary(number);
    }

    return 0;
}
