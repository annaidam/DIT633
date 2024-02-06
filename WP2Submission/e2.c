// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 2
// Exercise 2
// Submission code: 31299177

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5

// ##### typedefs ####
typedef struct q {
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main(int argc, char *argv[]) {
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    srand(time(0));  // Create the random number with the current time

    // Create a random list with MAX number of elements
    head = random_list();

    // Show the original list
    act_post = head;
    while (act_post != NULL) {
        printf("\nNum in %d: %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    int newNum;
    printf("\n\nAdd new element: ");
    scanf("%d", &newNum);

    // Add a new element to the beginning of the list
    head = add_first(head, newNum);

    // Show the modified list
    nr = 0;
    act_post = head;
    while (act_post != NULL) {
        printf("\nNum in %d: %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    // --- Free the allocated memory ---
    while ((act_post = head) != NULL) {
        head = act_post->next;
        free(act_post);  // Free the memory allocated for each node
    }

    return 0;
}

// ==== End of main ======================================

// Function to create a random list of MAX numbr of elements
REGTYPE* random_list(void) {
    int i;
    REGTYPE *top = NULL, *old, *item;

    for (i = 0; i < MAX; i++) {
        item = (REGTYPE *)malloc(sizeof(REGTYPE));  // Allocate memory for a new node

        if (item == NULL) {
            printf("Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        item->number = rand() % 101;  // Assign a random number between 0 and 100
        item->next = NULL;

        if (top == NULL) {
            top = item;  // Set top to the first node
        } else {
            old->next = item;  // Link the previous node to the current node
        }

        old = item;  // Update old to the current node
    }

    return top;  // Return top
}

//========================================================== 

// Function to add a new element with data to the beginning of the list
REGTYPE* add_first(REGTYPE* temp, int data) {
    REGTYPE *new_node = (REGTYPE *)malloc(sizeof(REGTYPE));  // Allocate memory for the new node

    if (new_node == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    new_node->number = data;  // Assign the given data to the new node
    new_node->next = temp;    // Set next to the current head of the list

    return new_node;  // Return the new node to the new head of the list
}
