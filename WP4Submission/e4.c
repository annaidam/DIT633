// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 4
// Exercise 4
// Submission code: XXXXXX (provided by your TA-s)

//includes
#include <stdio.h>
#include <stdlib.h>

//function declarations
int search_number(int number, int tab[], int size);
void sort(int number, int tab[]);
void swap(int* p1, int* p2);


//main
int main(int argc, char *argv[]) {
    int test[] = {1,2,34,5,67,3,32,12,13,10};
    printf("32, expecting 6: ");
    search_number(32, test, 10);
    printf("\n");

    printf("1, expecting 0: ");
    search_number(1, test, 10);
    printf("\n");

    printf("10, expecting 9: ");
    search_number(10, test, 10);
    printf("\n");

    printf("99, expecting -1: ");
    search_number(99, test, 10);
    printf("\n");

    printf("before sorting:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", test[i]);
        printf("\n");
    }

    sort(10, test);
    printf("after sorting:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", test[i]);
        printf("\n");
    }
    
    printf("32, expecting 7: ");
    search_number(32, test, 10);
    printf("\n");

    printf("1, expecting 0: ");
    search_number(1, test, 10);
    printf("\n");

    printf("10, expecting 4: ");
    search_number(10, test, 10);
    printf("\n");
    return 0;

}


//functions
int search_number(int number, int tab[], int size) {
    for (int i = 0; i < size; i++)
    {
        if (tab[i] == number) {
            printf("%d", i);
            return i;
        }
    }
    printf("%d", -1);
    return -1;
}

void sort(int number, int tab[]) {
    for (int i = 0; i < number - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < number; j++) {
            if (tab[j] < tab[min_idx]) {
                min_idx = j;
            }
        }
        swap(&tab[i], &tab[min_idx]);
    }
}

void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
