// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 2
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

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
    srand(time(0));

    head = random_list();

    act_post = head;
    while (act_post != NULL) {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    head = add_first(head, 42);

    nr = 0;
    act_post = head;
    while (act_post != NULL) {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    // --- Free the allocated memory ---
    while ((act_post = head) != NULL) {
        head = act_post->next;
        free(act_post);
    }

    return 0;
}

// ==== End of main ======================================

REGTYPE* random_list(void) {
    int i;
    REGTYPE *top = NULL, *old, *item;

    for (i = 0; i < MAX; i++) {
        item = (REGTYPE *)malloc(sizeof(REGTYPE));

        if (item == NULL) {
            printf("Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        item->number = rand() % 101;
        item->next = NULL;

        if (top == NULL) {
            top = item;
        } else {
            old->next = item;
        }

        old = item;
    }

    return top;
}

//========================================================== 

REGTYPE* add_first(REGTYPE* temp, int data) {
    REGTYPE *new_node = (REGTYPE *)malloc(sizeof(REGTYPE));

    if (new_node == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    new_node->number = data;
    new_node->next = temp;

    return new_node;
}
