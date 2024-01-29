#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int binary;
    int remainder;
    int hexa = 0;
    int index = 1;

    while (binary != 0) {
        remainder = binary % 10;
        hexa = hexa + remainder * index;
        index = index * 2;
        binary = binary / 10;
    }

    printf("%X\n", hexa);

    return 0;
}
