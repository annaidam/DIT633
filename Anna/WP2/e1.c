// (C) David Schön, Milena Mackowiak, Anna Mäkinen, group: 3 (2024)
// Work package 2
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>

enum DIRECTION { N, E, S, W };

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void move(ROBOT *robot) {
    switch (robot->dir) {
        case N:
            (robot->ypos)++;
            break;
        case E:
            (robot->xpos)++;
            break;
        case S:
            (robot->ypos)--;
            break;
        case W:
            (robot->xpos)--;
            break;
    }
}

void turn(ROBOT *robot) {
    robot->dir = (robot->dir + 1) % 4;
}

int main() {
    ROBOT robot;

    char instruction;
    do {
        printf("Enter start position (x y): ");
        scanf("%d %d", &(robot.xpos), &(robot.ypos));
        robot.dir = N;

        printf("Enter instruction (m/t, s to stop): ");
        scanf(" %c", &instruction);

        while (instruction != 's') {
            switch (instruction) {
                case 'm':
                    move(&robot);
                    break;
                case 't':
                    turn(&robot);
                    break;
                default:
                    printf("Invalid instruction\n");
                    break;
            }

            printf("Enter next instruction (m/t, s to stop): ");
            scanf(" %c", &instruction);
        }

        printf("New position: (%d, %d): ", robot.xpos, robot.ypos);
        switch (robot.dir) {
            case N:
                printf("North\n");
                break;
            case E:
                printf("East\n");
                break;
            case S:
                printf("South\n");
                break;
            case W:
                printf("West\n");
                break;
        }

        printf("\nEnter 's' to stop or any other character to continue: ");
        scanf(" %s", &instruction);

    } while (instruction != 's');

    return 0;
}
