// (C) David, group: 3 (2024)
// Work package -
// Excersise -

//includes
#include <stdio.h>
#include <stdlib.h>

//function declarations
void BinaryToHex(char *binaryData, char *hexData);

#define SET_BIT(buffer, index) ((buffer)[(index) / 8] |= (1 << ((index) % 8)))
#define CLEAR_BIT(buffer, index) ((buffer)[(index) / 8] &= ~(1 << ((index) % 8)))
#define GET_BIT(buffer, index) (((buffer)[(index) / 8] >> ((index) % 8)) & 1)
//main
int main(int argc, char *argv[]) {

    //initializing variables
    const int bufferSize = 1024;
    char *binaryData = malloc(bufferSize);
    char *hexData = malloc(bufferSize/4);

    if (!binaryData) {
        perror("Memory allocation failed");
        return 1;
    }

    // Read binary data from stdin
    if (fgets(binaryData, bufferSize, stdin) == NULL) {
        perror("Failed to read from stdin");
        free(binaryData);
        return 1;
    }

    // checks that the previous program did not return 2
    if (binaryData[0] == '2') {
        printf("Invalid input\n");
        return 2;
    }

    // Convert binary data to hex
    BinaryToHex(binaryData, hexData);

    // Print the hex data
    printf("%s\n", hexData);

    //return
    return 0;
}

//functions
void BinaryToHex(char *binaryData, char *hexData){
    int hexIndex = 0;

    while (*binaryData != '\0')
    {
        if (*(binaryData + 1) == '\0' || 
            *(binaryData + 2) == '\0' || 
            *(binaryData + 3) == '\0') {
            break;
        }
        int value = 0;

        // Convert each nibble into a decimal value
        for (int i = 0; i < 4; i++) {
            value <<= 1; // Shift the value left by 1 bit
            if (binaryData[i] == '1') {
                value |= 1; // Set the least significant bit
            }
        }

        // Convert the value to a hexadecimal character
        if (value < 10) {
            hexData[hexIndex++] = '0' + value;
        } else {
            hexData[hexIndex++] = 'A' + (value - 10);
        }

        binaryData += 4; // Move to the next nibble
    }
    hexData[hexIndex++] = '\0'; // Add the null terminator
}