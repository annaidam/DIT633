#include <stdio.h>
#include <ctype.h>
#include <string.h>

void shiftName(char name[]) {
    int length = strlen(name);

    for (int i = 0; i < length; i++) {
        char letter = name[i];

        if (isalpha(letter)) {
            int ascii = (int)letter;

            if (ascii >= 'a' && ascii <= 'z') {
                ascii = ((ascii - 'a') + 13) % 26 + 'a';
            } else if (ascii >= 'A' && ascii <= 'Z') {
                ascii = ((ascii - 'A') + 13) % 26 + 'A';
            }

            name[i] = (char)ascii;
        }
    }
}

int main(int argc, char *argv[]) {

    shiftName(argv[1]);

    printf("%s\n", argv[1]);

    return 0;
}