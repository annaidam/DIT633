// (C) David Schön, Milena Mackowiak, Anna Mäkinen, group: 3 (2024)
// Work package 1
// Exercise 5
// Submission code: XXXXXX (provided by your TA-s)

//includes
#include <stdio.h>
#include <stdlib.h>

//global variables
#define MAX 50 //number of random numbers
#define MAXNUMBER 20 //max value of random number

//function declarations
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab );
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq );
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq );

//functions
void create_random(int *tab){
    for (size_t i = 0; i < MAX; i++)
    {
        *tab = rand() % MAXNUMBER;
        tab++;
    }
}

void count_frequency(int *tab, int *freq){

    //initializing freq table
    for (size_t i = 0; i < MAXNUMBER; i++)
    {
        *freq = 0;
        freq++;
    }

    //counting freq
    for (size_t i = 0; i < MAX; i++)
    {
        //resetting the freq pointer

        int value = *tab;
        for (size_t i = 0; i < value; i++)
        {
            freq++;
        }

        printf("tab: %d\n", *tab);
        *freq = *freq + 1;
        printf("freq: %d\n", *freq);
        tab++;
    }

}

//main
int main(int argc, char *argv[]) {

    //initializing variables
    int table[MAX], n;
    int frequency[MAXNUMBER];
    

    //code
    create_random(table);

    count_frequency(table, frequency);

    //print the freq table
    /*
    for (size_t i = 0; i < MAXNUMBER; i++)
    {
        printf("%d: ", i);
        printf("%d\n", *frequency);
    }
    */

    //return
    return 0;

}