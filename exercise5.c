#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab ){
    for (int i = 0; i < MAX; i++){
    srand(time(0));
    tab[i] = rand() % (MAXNUMBER + 1);
    }
};
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq ){
    for (int i = 0; i < MAX; i++){
        int current = tab[i];
        freq[current]++;
    }
};
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq ){
    for (int i = 0; i < MAXNUMBER; i++){
      if (freq[i] > 0){
        printf("%d ", i);
        for (int j = 0; j < freq[i]; j++){
           printf("x");
        }
        printf("\n"); 
      } 
    }
};


// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program

int main (void){
int table[MAX];
int frequency[MAXNUMBER];

create_random(table);
count_frequency(table, frequency);
draw_histogram(frequency);
}
