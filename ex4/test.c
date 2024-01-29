#include <stdio.h>
#include <stdlib.h>

char* intToBinaryString(int number) {
    // Assuming a 32-bit int for simplicity
    int bits = sizeof(int) * 8;
    char *binaryStr = (char*)malloc(bits + 1); // +1 for null terminator

    if (binaryStr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    binaryStr[bits] = '\0'; // Null-terminating the string

    for (int i = bits - 1; i >= 0; i--) {
        binaryStr[bits - 1 - i] = (number & (1 << i)) ? '1' : '0';
    }

    return binaryStr;
}

int main(int argc, char *argv[]) {
    int number = strtol(argv[1], NULL, 10);

    char *binaryStr = intToBinaryString(number);
    printf("Binary representation: %s\n", binaryStr);

    free(binaryStr); // Don't forget to free the allocated memory
    return 0;
}
