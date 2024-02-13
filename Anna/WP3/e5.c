// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 3
// Exercise 5
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 8 // the max numbers in the array

int main() {
    int array[MAX];
    int* pointer = array;
    srand(time(0));

    for (int i = 0; i < MAX; i++) {
        array[i] = rand() % 99 + 1; // create a random number between 1 and 100 for every slot in the array
    }

    // print the address to the first element
    printf("The value of the address of the array (pointer) is: %p\n", array);

    // print the first integer in the array
    printf("First integer in the array is (array[0]): %d\n", array[0]);

    // print the last integer of the array
    printf("The last integer in the array is: %d\n", array[MAX-1]);

    // print the size of an integer array in bytes
    printf("The size of an integer (number of bytes) is: %d\n", (int) sizeof(int));

    // print the size of the array in bytes
    printf("The size of the whole array in bytes is: %d\n\n", (int) sizeof(array));

    for (int i = 0; i < MAX; i++) {
        // print the value in each slot and that value multiplied by 2
        printf("Value in %d is %d, which is %d multiplied by 2\n", i, *pointer, *pointer * 2);
        pointer++;
    }

    return 0;
}