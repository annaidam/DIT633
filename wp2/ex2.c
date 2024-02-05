#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5
#define MAXNUMBER 99

typedef struct q {
    int number;
    struct q* next;
    struct q* prev;
} REGTYPE;

REGTYPE* random_list(void) {
    int nr;
    REGTYPE* top = NULL, * old = NULL, * item = NULL;

    printf("Enter the number of elements in the list: \n");
    scanf("%d", &nr);

    for (int i = 0; i < nr; i++) {
        item = (REGTYPE*)malloc(sizeof(REGTYPE));
        item->number = rand() % (MAXNUMBER + 1);
        item->next = NULL;

        if (old != NULL) {
            old->next = item;
            item->prev = old;
        }

        old = item;

        if (top == NULL) {
            top = item;
        }
    }
    return top;
}

REGTYPE* add_first(REGTYPE* temp, int data) {
    REGTYPE* new_node = (REGTYPE*)malloc(sizeof(REGTYPE));

    new_node->number = data;
    new_node->next = temp;
    new_node->prev = NULL;

    if (temp != NULL) {
        temp->prev = new_node;
    }

    return new_node;
}

int main(int argc, char* argv[]) {
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); // Random seed
    head = random_list();
    act_post = head;

    printf("\nOriginal list:\n");
    while (act_post != NULL) {
        printf("Post nr %d : %d\n", nr++, act_post->number);
        act_post = act_post->next;
    }

    // Free the allocated memory
    // while ((act_post = head) != NULL) {
    //     head = act_post->next;
    //     free(act_post);
    // }

    // Add a new element at the beginning of the list using add_first()
    int data = 7; // New data for the first element
    head = add_first(head, data);

    // Display the updated list after adding a new element
    printf("\nUpdated list after adding element at the beginning:\n");
    nr = 0;
    act_post = head;
    while (act_post != NULL) {
        printf("Post nr %d : %d\n", nr++, act_post->number);
        act_post = act_post->next;
    }

    return 0;
}
