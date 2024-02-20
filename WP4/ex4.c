// (C) David, group: 3 (2024)
// Work package -
// Excersise -

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
    int num = 0;
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

    sort(69, test);

    printf("32, expecting -: ");
    search_number(32, test, 10);
    printf("\n");

    printf("1, expecting -: ");
    search_number(1, test, 10);
    printf("\n");

    printf("10, expecting -: ");
    search_number(10, test, 10);
    printf("\n");
    return 0;

}


//functions
int search_number(int number, int tab[], int size) {
    for (size_t i = 0; i < size; i++)
    {
        if (tab[i] == number) {
            printf((char)i);
            return i;
        }
    }
    return -1;
}

void sort(int number, int tab[]) {
    int* ptr = tab;
    int* minimum = tab;
    int* sorted = tab;
    
    while (*sorted != '\0')
    {
        while (*ptr != '\0') {
            if (*ptr < *minimum)
            {
                minimum = ptr;
            }
        }
        swap(sorted, minimum);
        sorted++;
        ptr = sorted;
    }
}

void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}