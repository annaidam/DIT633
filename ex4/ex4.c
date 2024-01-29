// (C) David, group: 3 (2024)
// Work package -
// Excersise -

//includes
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//function declarations
int longToBinary(int number);
int BinaryToHex(int number);


//main
int main(int argc, char *argv[]) {

    //initializing variables
    long MAX = LONG_MAX;
    int input = strtol(argv[1], NULL, 10);



    //code



    //return
    return 0;

}


//functions
int longToBinary(int number){

    int binaryNumber = 0;
    int remainder, i = 1;

    while (number != 0)
    {
        remainder = number % 2;
        number = number / 2;
        binaryNumber += remainder * i;
        i = i * 10;
    }

    return binaryNumber;
}

int BinaryToHex(int number){

    int hexNumber = 0xFFFF;
    int remainder, i = 1;

    while (number != 0)
    {
        remainder = number % 2;
        number = number / 2;
        hexNumber += remainder * i;
        i = i * 10;
    }

    return hexNumber;
}