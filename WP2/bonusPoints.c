// (C) David, group: 3 (2024)
// Work package -
// Excersise -

//includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//function declarations

enum days {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

//main
int main(int argc, char *argv[]) {

    //initializing variables
    enum days day = Monday;
    int week = 1;
    char weekInput[10];
    char dayInput[10];

    //asks for input
    printf("Provide starting week: ");
    fgets(weekInput, sizeof(weekInput), stdin);
    printf("Provide starting day: ");
    fgets(dayInput, sizeof(dayInput), stdin);
    week = atoi(weekInput);
    day = atoi(dayInput);
    day = day - 1;//because the codegrader has 1 as the beginning of the week

    //check if inputs are valid
    if (week < 1 || week > 5)
    {
        printf("invalid week\n");
        return 0;
    }
    if (day < 0 || day > 6)
    {
        printf("invalid day\n");
        return 0;
    }
    
    //each loop is a day, contiues until the end of the week 5
    while (week < 6) {
        //prints the week
        printf("Week %d, ", week);

        //prints the day
        switch (day) {
            case Monday:
                printf("Monday\n");
                break;
            case Tuesday:
                printf("Tuesday\n");
                break;
            case Wednesday:
                printf("Wednesday\n");
                break;
            case Thursday:
                printf("Thursday\n");
                break;
            case Friday:
                printf("Friday\n");
                break;
            case Saturday:
                printf("Saturday\n");
                break;
            case Sunday:
                printf("Sunday\n");
                break;
            default:
                printf("Error\n");
                break;
        }

        //increments the day
        day++;

        //increments the week if the day is sunday, and resets to the beginning of the week
        if (day > 6) {
            day = Monday;
            week++;
        }

        //sleeps for 1 second
        sleep(1);
    }

    //return
    return 0;

}


//functions