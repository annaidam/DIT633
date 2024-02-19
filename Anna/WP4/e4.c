// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 4
// Exercise 4
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>

// function declarations
int search_number(int number, int tab[], int size);
void sort(int tab[], int size);

int main() {
    // the test array
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    // number to search for
    int number;

    // ask user to enter the number they want to search for
    printf("Enter a number you want to search for: ");
    scanf("%d", &number);

    // save the result of the search_number function to a variable
    int result = search_number(number, test, 10);

    // check if the result is -1 i.e. if the number is in the array or not
    if (result == -1) {
        // print that the number was not part of the array
        printf("\nNumber %d is not part of the given array\n", number);
    } else {
        // print in which index the given number was first found
        printf("\nThe index of %d is %d\n", number, result);
    }

    // sort the array by calling the function
    sort(test, 10);

    // print the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", test[i]);
    }
    printf("\n");

    return 0;
}

// function for searching a number in the array
int search_number(int number, int tab[], int size) {
    // check for every number in the array
    for (int i = 0; i < size; i++) {
        // if the number in slot i is the same as the given number return the index of the number
        if (tab[i] == number) {
            return i;
        }
    }
    // in any other case return -1
    return -1;
}

// function for sorting the array
void sort(int tab[], int size) {
    // two for loops to check for two slots of the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // if the value in slot j is bigger than the value in the next slot
            if (tab[j] > tab[j + 1]) {
                // swap elements cause they are in the wrong order
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}
