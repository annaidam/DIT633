// Include statements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 7

// Main entry point for the program.
int main() {
    // Create an array of size MAX.
    int array[MAX];
    // Create a pointer and point it to the firstv element of the array.
    int *ptr = array;

   // Seed for the random number generator.
    srand(time(0));
    // For loop to iterate through all the elements fo the array.
    for (int i = 0; i < MAX; i++) {
        // Assign a random number to the current element of the array.
        array[i] = rand() % 99 + 1;
    }

    // Print out the address of the array (pointer)
    printf("The value of the address of the array (pointer) is: %p\n", ptr);

    // Print out the first integer in the array
    printf("First integer in the array is (array[0]): %d\n", *ptr);

    // Print out the last integer in the array
    printf("The last integer in the array is: %d\n", *(ptr + MAX - 1));

    // Print out the size of an integer (number of bytes)
    printf("The size of an integer (number of bytes) is: %d\n", (int) sizeof(int));

    // Print out the size of the whole array in bytes
    printf("The size of the whole array in bytes is: %d\n", (int) sizeof(array));

    // Print out each integer value and its value multiplied by two
    for (int i = 0; i < MAX; i++) {
        printf("Integer value: %d, Multiplied by 2: %d\n", *(ptr + i), 2 * *(ptr + i));
    }

    return 0;
}