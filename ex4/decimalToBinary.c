// (C) David, group: 3 (2024)
// Work package -
// Excersise -

//includes
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


#define SET_BIT(buffer, index) ((buffer)[(index) / 8] |= (1 << ((index) % 8)))
#define CLEAR_BIT(buffer, index) ((buffer)[(index) / 8] &= ~(1 << ((index) % 8)))
#define GET_BIT(buffer, index) (((buffer)[(index) / 8] >> ((index) % 8)) & 1)


//function declarations
void findBitsAndBytes(int number);
void fillBuffer(int number, unsigned char *buffer);
void printBuffer(unsigned char *buffer);

//global variables
int input;
int global_bits;
int global_bytes;

//main
int main(int argc, char *argv[]) {

    //initializing variables
    long MAX = LONG_MAX;
    int number = strtol(argv[1], NULL, 10);

    //check that the input is valid in various ways
    /*
    //check that the input is not too big or too small
    if (number > MAX || number < 0) {
        printf("Invalid input\n");
        return 2;
    }
    //check that there is only one input
    if (argc != 2) {
        printf("Invalid input\n");
        return 2;
    }
    //check that the input is a number
    for (size_t i = 0; i < sizeof(argv[1]); i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9') {
            printf("Invalid input\n");
            return 2;
        }
    }

    */

    findBitsAndBytes(number);
    unsigned char *buffer = malloc(global_bytes);//this is a pointer to the first byte of the buffer
    if (buffer == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // fill the buffer
    fillBuffer(number, buffer);

    // Print the buffer
    printBuffer(buffer);

    //return
    return 0;

}


//functions


//finds the minimum amount of bytes needed to represent a number
//(bit = 1 or 0, bytes = 8 bits)
void findBitsAndBytes(int number){
    //defines function variables
    int bits = 0;
    int bytes = 0;


    //finds the amount of bits needed to represent the number
    while (number != 0)
    {
        number = number / 2;
        bits++;
    }

    //saves the bits in the global variable
    global_bits = bits;

    //rounds the bits up to the nearest byte
    while (bits % 8 != 0)
    {
        bits++;
    }

    //converts the bits to bytes, and saves it in the global variable
    global_bytes = bits / 8;

    //prints bits and bytes
    //printf("bits: %d\n", global_bits);
    //printf("bytes: %d\n", global_bytes);
}

void fillBuffer(int number, unsigned char *buffer) {
    int totalBits = global_bytes * 8;
    int offset = totalBits - global_bits;

    // Zeroes the buffer
    for (size_t i = 0; i < totalBits; i++) {
        CLEAR_BIT(buffer, i);
    }

    // Fills the buffer with the binary representation of the number
    int i = totalBits - 1;
    while (number != 0)
    {
        if (number % 2 == 1) {
            SET_BIT(buffer, i);
        }
        number = number / 2;
        i--;
    }
}

void printBuffer(unsigned char *buffer) {
    int totalBits = global_bytes * 8;

    // Prints the buffer
    for (size_t i = 0; i < totalBits; i++) {
        printf("%d", GET_BIT(buffer, i));
    }
    printf("\0");
    printf("\n");
}