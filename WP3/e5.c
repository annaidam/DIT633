// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 3
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 7

int main() {
    int array[MAX];
    int *ptr = array;

    // Fill the array with random integers from 1 to 99
    srand(time(0));
    for (int i = 0; i < MAX; i++) {
        array[i] = rand() % 99 + 1;
    }

    // Print out the address of the array (pointer)
    printf("The value of the address of the array (pointer) is: %p\n", ptr);

    // Print out the first integer in the array
    printf("First integer in the array is (array[0]): %d\n", *ptr);

    // Print out the last integer in the array
    printf("The last integer in the array is: %d\n", *(ptr + MAX - 1));

    // Print out the size of an integer (number of bytes)
    printf("The size of an integer (number of bytes) is: %lu\n", (int) sizeof(int));

    // Print out the size of the whole array in bytes
    printf("The size of the whole array in bytes is: %lu\n", (int) sizeof(array));

    // Print out each integer value and its value multiplied by two
    for (int i = 0; i < MAX; i++) {
        printf("Integer value: %d, Multiplied by two: %d\n", *(ptr + i), 2 * *(ptr + i));
    }

    return 0;
}