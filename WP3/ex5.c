// (C) David, group: 3 (2024)
// Work package -
// Excersise -

//includes
#include <stdio.h>
#include <stdlib.h>

//declarations
#define MAX 100

void fillWithRandom(int* array);

//main
int main(int argc, char *argv[]) {

    //initializing variables
    int* array = malloc(MAX*sizeof(int));
    fillWithRandom(array);


    printf("The value of the address of the array (pointer) is: %p\n", array);
    printf("First integer in the array is (array[0]): %d\n", *array);
    printf("The last integer in the array is: %d\n", array[MAX-1]);
    printf("The size of an integer (number of bytes) is: %d\n", sizeof(int));
    printf("The size of the whole array in bytes is: %d\n", MAX*sizeof(int));

    int* ptr = array;
    for (size_t i = 0; i < MAX; i++)
    {
        printf("value: %d, value times two: %d\n", *ptr, *ptr*2);
        ptr++;
    }
    
    //code



    free(array);
    //return
    return 0;

}


//functions
void fillWithRandom(int* array) {
    int* ptr = array;
    for (int i = 0; i < MAX; i++)
    {
        int random = (rand() % (MAX-1)) + 1;
        *ptr = random;
        ptr++;
    }
}