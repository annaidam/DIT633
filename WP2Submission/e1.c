// (C) Milena Mackowiak, Anna Mäkinen, David Schön, group: 3 (2024)
// Work package 2
// Exercise 1
// Submission code: 31299177

// gcc -Wall -o WP2/ex1.exe WP2/ex1.c
// gcc -Wall -o ex1.exe ex1.c    
#include <stdio.h>
#include <string.h>

enum DIRECTION { N, E, S, W};

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void move(ROBOT* robot){
    switch (robot->dir){
        case N: 
            robot->ypos = robot->ypos + 1;
            break;
        case S:
             robot->ypos = robot->ypos - 1;
            break;
        case E:
            robot->xpos = robot->xpos + 1;
            break;
        case W:
            robot->xpos = robot->xpos - 1;
            break;
    }
};

void turn(ROBOT* robot){
    // Rotate the robot 90 degrees clockwise.
    robot->dir = (robot->dir + 1) % 4;
};

int main(int argc, char *argv[]){
    ROBOT robot;
    int x;
    int y;
    char instructions[150];

    printf("Provide x-coordinate for the robot (0-99): \n");
    scanf("%d", &x);
    if(x < 0 || x > 99){
        printf("Invalid input. Try again.\n");
        return 0;
    } else {
        robot.xpos = x;
    }

    printf("Provide y-coordinate for the robot (0-99): \n");
    scanf("%d", &y);
     if(y < 0 || y > 99){
        printf("Invalid input. Try again.\n");
        return 0;
    } else {
        robot.ypos = y;
    }

    printf("Provide instructions for the robot (ending with '#'): \n");
    scanf("%s", instructions);

    robot.dir = N;
    
    for (int i = 0; instructions[i] != '#'; i++) {
       char currentInst = instructions[i];
       if (currentInst == 'm') {
        move(&robot);
       } else if (currentInst == 't') {
        turn(&robot);
       }
    }

    printf("New position of the robot: %d, %d.\n", robot.xpos, robot.ypos);
}