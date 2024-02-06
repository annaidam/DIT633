// (C) David Schön, Milena Mackowiak, Anna Mäkinen, group: 3 (2024)
// Work package 1
// Exercise 5
// Submission code: 415678 (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        tab[i] = rand() % (MAXNUMBER + 1);
    }
}

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq ) {
    for (int i = 0; i < MAXNUMBER; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < MAX; i++) {
        freq[tab[i]]++;
    }
}

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq ) {
    for (int i = 0; i < MAXNUMBER; i++) {
        int count = 0;
        for (int j = 1; j < MAXNUMBER; j++) {
            if (freq[i] == freq[j]) {
                count++;
            }
        }
        if (count != 0) {
            printf("%d: ", i);

            for (int j = 0; j < count; j++) {
                printf("x");
            }

            printf("\n");
        }
    }
}

// ------ Function definitions ----------

// ------ Main --------------------------
// The main entry point for the program
int main (void) {
    int table[MAX], n ;
    int frequency[MAXNUMBER];

    create_random(table, MAX);
    count_frequency(table, frequency);
    draw_histogram(frequency);

    return 0;
}