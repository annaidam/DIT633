#include <stdio.h>

int main () {
    int num;

    // While the number is not 1–5, keep showing a corresponding sentence
    do {
        printf("\nWrite a number between 1–5: ");
        scanf("%d", &num);

        if (num == 1) {
            printf("\nWombat's poops are cubes\n");
        } else if (num == 2) {
            printf("\nBeluga whales' head is squishy\n");
        } else if (num == 3) {
            printf("\nQuokkers are the happiest animals cause they don't have any threats\n");
        } else if (num == 4) {
            printf("\nIn Finnish 'hirvi' means a moose but in Estonian it means a deer\n");
        } else if (num == 5) {
            printf("\nHamsters die funny\n");
        } else {
            printf("Exiting program...");
        }
    } while (num == 1 || num == 2 || num == 3 || num == 4 || num == 5);
}