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
void hexToBin(char* hexdec, char* binaryNum);
//macros
#define SET_BIT(buffer, index) ((buffer)[(index) / 8] |= (1 << ((index) % 8)))
#define CLEAR_BIT(buffer, index) ((buffer)[(index) / 8] &= ~(1 << ((index) % 8)))
#define GET_BIT(buffer, index) (((buffer)[(index) / 8] >> ((index) % 8)) & 1)


//main
int main(int argc, char *argv[]) {

    //initializing variables
    unsigned char* byte = malloc(1);
    int engine_on;
    int gear_pos;
    int key_pos;
    int brake1;
    int brake2;

    //argument check for -h or a valid case, if neither, return error
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
    {
        printf("Usage: have a hexadecimal in the parameters of this program, and the program outputs the decoded information\n");
        return 0;
    } else if (argc == 2)
    {
        char* hex = argv[1];
        char binaryNum[1000] = "0b";
        hexToBin(hex, binaryNum);

        //checks if the hex is valid by checking invalid bit combinations
        if (binaryNum[3] == '1' && (binaryNum[4] == '1' || binaryNum[5] == '1')) //gear_pos is value > 4
        {
            printf("Invalid input");
            return 2;//exit with error code 2
        } else if (binaryNum[6] == '1' && binaryNum[7] == '1') //key_pos is value 3
        {
            printf("Invalid input");
            return 2;//exit with error code 2
        }


        //7th bit
        if (binaryNum[2] == '1')
        {
            engine_on = 1;
        }
        else
        {
            engine_on = 0;
        }
        

        //6-4th bits
        int value = 0;
        if (binaryNum[3] == '1')
        {
            value += 4;
        } else if (binaryNum[4] == '1')
        {
            value += 2;
        } else if (binaryNum[5] == '1')
        {
            value += 1;
        }
        gear_pos = value;

        //3-2th bit
        value = 0;
        if (binaryNum[6] == '1')
        {
            value += 2;
        } else if (binaryNum[7] == '1')
        {
            value += 1;
        }
        key_pos = value;

        //1st bit
        if (binaryNum[8] == '1')
        {
            brake1 = 1;
        }
        else
        {
            brake1 = 0;
        }
        

        //0th bit
        if (binaryNum[9] == '1')
        {
            brake2 = 1;
        } else
        {
            brake2 = 0;
        }
        
        
        
        
    }
    else
    {
        perror("Error with arguments");
        return 2;//exit with error code 2
    }

    //printing the values
    printf("Name             Value\n");
    printf("----------------------\n");
    printf("Engine on:       %d\n", engine_on);
    printf("Gear position:   %d\n", gear_pos);
    printf("Key position:    %d\n", key_pos);
    printf("Brake 1:         %d\n", brake1);
    printf("Brake 2:         %d\n", brake2);


    //return
    return 0;

}


//functions


// function to convert Hexadecimal to Binary Number
void hexToBin(char* hexdec, char* binaryNum)
{

	//Skips "0x" if present
	size_t i = (hexdec[1] == 'x' || hexdec[1] == 'X')? 2 : 0;

	while (hexdec[i]) {

		switch (hexdec[i]) {
		case '0':
            strcat(binaryNum, "0000");
			break;
		case '1':
            strcat(binaryNum, "0001");
			break;
		case '2':
            strcat(binaryNum, "0010");
			break;
		case '3':
            strcat(binaryNum, "0011");
			break;
		case '4':
            strcat(binaryNum, "0100");
			break;
		case '5':
            strcat(binaryNum, "0101");
			break;
		case '6':
            strcat(binaryNum, "0110");
			break;
		case '7':
            strcat(binaryNum, "0111");
			break;
		case '8':
            strcat(binaryNum, "1000");
			break;
		case '9':
            strcat(binaryNum, "1001");
			break;
		case 'A':
		case 'a':
            strcat(binaryNum, "1010");
			break;
		case 'B':
		case 'b':
            strcat(binaryNum, "1011");
			break;
		case 'C':
		case 'c':
            strcat(binaryNum, "1100");
			break;
		case 'D':
		case 'd':
            strcat(binaryNum, "1101");
			break;
		case 'E':
		case 'e':
            strcat(binaryNum, "1110");
			break;
		case 'F':
		case 'f':
            strcat(binaryNum, "1111");
			break;
		case '.':
			printf(".");
		default:
			printf("\nInvalid hexadecimal digit %c",
				hexdec[i]);
		}
		i++;
	}
}

