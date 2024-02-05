// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 2
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>

// Enum for directions north, east, south, west
enum DIRECTION { N, E, S, W };

// Positions and the direction
typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

// Function for moving the robot to a certain position by coordinates and based on the direction
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

// Function to turn the robot
void turn(ROBOT *robot) {
    robot->dir = (robot->dir + 1) % 4;
}

// Main function
int main() {
    // New robot
    ROBOT robot;
    // Instructions given by the user
    char instruction;
    do {
        // User enters starting coordinates
        printf("Enter start position (x y): ");
        scanf("%d %d", &(robot.xpos), &(robot.ypos));
        robot.dir = N; // Starting direction is north

        // User choosed wheter they want to move, turn or stop the robot
        printf("Enter instruction (m/t, s to stop): ");
        scanf(" %c", &instruction);

        // When the instruction is not stop
        while (instruction != 's') {
            switch (instruction) {
                case 'm':
                    move(&robot); // Calls the move function
                    break;
                case 't': // Calls the turning function
                    turn(&robot);
                    break;
                default:
                    printf("Invalid instruction\n"); // Other instructions are not valid
                    break;
            }

            // Ask again until the user wants to stop
            printf("Enter next instruction (m/t, s to stop): ");
            scanf(" %c", &instruction);
        }

        // After stopping print the new position of the robot based on the instructions given by the user
        printf("New position: (%d, %d): ", robot.xpos, robot.ypos); // New position is saved in the xpos and ypos
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

    } while (instruction != 's'); // When the instruction is s the program stops

    return 0;
}
