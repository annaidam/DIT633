// (C) David, group: 3 (2024)
// Work package -
// Excersise -

//includes
#include <stdio.h>
#include <stdlib.h>

//enum declaration
enum DIRECTION {N, E, S, W};

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

//function declarations
void move(int *x, int *y, enum DIRECTION *dir);
void turn(enum DIRECTION *dir);


//main
int main(int argc, char *argv[]) {

    //initializing variables
    ROBOT robot;
    robot.dir = N; //default direction is north
    char input[100];
    int endChar = 1;
    unsigned char *cPointer;

    //asks for coordinate input, checks if input is valid
    printf("Provide starting coordinates, ranging between 0-99 (x, y): ");
    scanf("%d %d", &robot.xpos, &robot.ypos);
    if (robot.xpos < 0 || robot.xpos > 99 || robot.ypos < 0 || robot.ypos > 99)
    {
        printf("invalid coordinates\n");
        return 0;
    }

    while (endChar == 1)
    {    
        //asks for a string fo m and t, checks if input is valid
        printf("Provide a string of m's and t's, (Q is the end char to end the program): ");
        scanf("%s", input);
        cPointer = input;
        int invalid = 0; //resets the invalid flag
        while (*cPointer != '\0')
        {
            if (*cPointer == 'm' || *cPointer == 't' || *cPointer == 'M' || *cPointer == 'T' || *cPointer == 'Q' || *cPointer == 'q')
            {
                cPointer++;
            } else {
                printf("invalid string\n");
                invalid = 1;
                return 0;
            }
        }
        cPointer = input; //reset pointer to the beginning of the string


        if (invalid == 0) //if the string is invalid, the program will ask for a new string instead of moving the robot
        {
            while (*cPointer != '\0') //loops through the string and executes the commands based on the letters
            {
                if (*cPointer == 'm' || *cPointer == 'M')
                {
                    move(&robot.xpos, &robot.ypos, &robot.dir);
                } else if (*cPointer == 't' || *cPointer == 'T')
                {
                    turn(&robot.dir);
                } else if (*cPointer == 'Q' || *cPointer == 'q')
                {
                    endChar = 0;
                    break;
                }
                cPointer++;
            }
            cPointer = input; //reset pointer to the beginning of the string

            //prints the final position of the robot
            printf("Final position: (%d, %d)\n", robot.xpos, robot.ypos);
        }
    }

    



    //end of program
    return 0;
}


//functions
void start(int *x,int *y) {
    printf("Provide starting coordinates (x, y): ");
    scanf("%d %d", x, y);
    if (*x < 0 || *x > 99 || *y < 0 || *y > 99)
    {
        printf("invalid coordinates\n");
    }
}

void move(int *x,int *y,enum DIRECTION *dir) {
    switch (*dir) {
        case N:
            if ((*y+1) <= 99)
            {
                *y = *y + 1;
                break;
            }
            else
            {
                printf("invalid move north; out of bounds\n");
                break;
            }
        case E:
            if ((*x+1) <= 99)
            {
                *x = *x + 1;
                break;
            }
            else
            {
                printf("invalid move east; out of bounds\n");
                break;
            }
        case S:
            if ((*y-1) >= 0)
            {
                *y = *y - 1;
                break;
            }
            else
            {
                printf("invalid move south; out of bounds\n");
                break;
            }
        case W:
            if ((*x-1) >= 0)
            {
                *x = *x - 1;
                break;
            }
            else
            {
                printf("invalid move west; out of bounds\n");
                break;
            }
    }
}

void turn(enum DIRECTION *dir) {
    switch (*dir) {
        case N:
            *dir = E;
            break;
        case E:
            *dir = S;
            break;
        case S:
            *dir = W;
            break;
        case W:
            *dir = N;
            break;
    }
}