// (C) David, group: 3 (2024)
// Work package -
// Excersise -

//includes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//function declarations
void packEngine(unsigned char* byte, int engine_on);
void packGearPos(unsigned char* byte, int gear_pos);
void packKeyPos(unsigned char* byte, int key_pos);
void packBrake1(unsigned char* byte, int brake1);
void packBrake2(unsigned char* byte, int brake2);
void BinaryToHex(unsigned char *byte);
void clearByte(unsigned char* byte);
//macros
#define SET_BIT(buffer, index) ((buffer)[(index) / 8] |= (1 << ((index) % 8)))
#define CLEAR_BIT(buffer, index) ((buffer)[(index) / 8] &= ~(1 << ((index) % 8)))
#define GET_BIT(buffer, index) (((buffer)[(index) / 8] >> ((index) % 8)) & 1)


//main
int main(int argc, char *argv[]) {

    //initializing variables
    unsigned char* byte = malloc(100*sizeof(char));
    int engine_on;
    int gear_pos;
    int key_pos;
    int brake1;
    int brake2;

    //argument check for -h or a valid case, if neither, return error
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
    {
        printf("Usage: this program prints the binary form of the number given, give the number as a parameter after the program: decimalToBinary.exe <number>\n");
        printf("note: this program can be used in conjunction with binaryToHex to instead be given the hexadecimal of the number: decimalToBinary.exe <number> | binaryToHex.exe\n");
        return 0;
    } else if (argc == 6)
    {
        for (size_t i = 1; i < argc; i++)
        {
            unsigned char *p = argv[i];
            while (*p != '\0') {
                if (!isdigit(*p)) {
                    perror("Invalid input");
                    return 2;//exit with error code 2
                }
                p++;
            }
        }
        
        engine_on = strtol(argv[1], NULL, 10);
        gear_pos = strtol(argv[2], NULL, 10);
        key_pos = strtol(argv[3], NULL, 10);
        brake1 = strtol(argv[4], NULL, 10);
        brake2 = strtol(argv[5], NULL, 10);
    }
    else
    {
        perror("Error with arguments");
        return 2;//exit with error code 2
    }
    
    clearByte(byte);
    //packing the bits
    
    packEngine(byte, engine_on);printf("\n");
    packGearPos(byte, gear_pos);printf("\n");
    packKeyPos(byte, key_pos);printf("\n");
    packBrake1(byte, brake1);printf("\n");
    packBrake2(byte, brake2);printf("\n");
    

    //printing the byte in hexadecimal
    BinaryToHex(byte);




    //return
    return 0;

}


//functions

void packEngine(unsigned char* byte, int engine_on) {
    //engine_on is 1 bit, MSB
    switch (engine_on)
    {
    case 1:
        printf("1");
        SET_BIT(byte, 7);
        break;
    case 0:
        printf("0");
        CLEAR_BIT(byte, 7);
        break;
    default:
        printf("Error with engine_on");
        break;
    }
}

void packGearPos(unsigned char* byte, int gear_pos) {
    //gear_pos is 3 bits, 6th, 5th, and 4th

    switch (gear_pos)
    {
    case 4:
        //100
        printf("100");
        SET_BIT(byte, 6);
        CLEAR_BIT(byte, 5);
        CLEAR_BIT(byte, 4);
        break;
    case 3:
        //011
        printf("011");
        CLEAR_BIT(byte, 6);
        SET_BIT(byte, 5);
        SET_BIT(byte, 4);
        break;
    case 2:
        //010
        printf("010");
        CLEAR_BIT(byte, 6);
        SET_BIT(byte, 5);
        CLEAR_BIT(byte, 4);
        break;
    case 1:
        //001
        printf("001");
        CLEAR_BIT(byte, 6);
        CLEAR_BIT(byte, 5);
        SET_BIT(byte, 4);
        break;
    case 0:
        //000
        printf("000");
        CLEAR_BIT(byte, 6);
        CLEAR_BIT(byte, 5);
        CLEAR_BIT(byte, 4);
        break;
    default:
        printf("Error with gear_pos");
        break;
    }
}
void packKeyPos(unsigned char* byte, int key_pos) {
    //key_pos is 2 bits, 3rd and 2nd
    switch (key_pos)
    {
    case 2:
        //10
        printf("10");
        SET_BIT(byte, 3);
        CLEAR_BIT(byte, 2);
        break;
    case 1:
        //01
        printf("01");
        CLEAR_BIT(byte, 3);
        SET_BIT(byte, 2);
        break;
    case 0:
        //00
        printf("00");
        CLEAR_BIT(byte, 3);
        CLEAR_BIT(byte, 2);
        break;
    default:
        printf("Error with key_pos");
        break;
    }
}
void packBrake1(unsigned char* byte, int brake1){
    //brake1 is 1 bit, 1st
    switch (brake1)
    {
    case 1:
        //1
        printf("1");
        SET_BIT(byte, 1);
        break;
    case 0:
        //0
        printf("0");
        CLEAR_BIT(byte, 1);
        break;
    default:
        printf("Error with brake1");
        break;
    }
}

void packBrake2(unsigned char* byte, int brake2) {
    //brake2 is 1 bit, LSB
    switch (brake2)
    {
    case 1:
        //1
        printf("1");
        SET_BIT(byte, 1);
        break;
    case 0:
        //0
        printf("0");
        CLEAR_BIT(byte, 1);
        break;
    default:
        printf("Error with brake2");
        break;
    }
}

void BinaryToHex(unsigned char *byte){
    char *hexData = malloc(3*sizeof(char));
    int hexIndex = 0;
    char *binaryData = malloc(9*sizeof(char));
    for (size_t i = 0; i < 8; i++)
    {
        if (GET_BIT(byte, i) == 1)
        {
            binaryData[i] = '1';
        } else
        {
            binaryData[i] = '0';
        }
    }
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
    printf("%s\n", hexData);
}

void clearByte(unsigned char* byte){
    for (size_t i = 0; i < 8; i++)
    {
        CLEAR_BIT(byte, i);
    }
}