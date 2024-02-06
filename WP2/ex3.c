#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void); // Prints out all persons in the file
void search_by_firstname(char *name); // Prints out the person if in list
void append_file(PERSON *inrecord); // appends a new person to the file
void print_options(void); // Prints out the menu

// global variables

int main(void){
    PERSON ppost;
    int continueProgram = 1;
    char input[20];
    int choice;

    //main loop
    while (continueProgram)
    {
        print_options();
        scanf("%d", &choice);
        void print_options();
        if (choice < 1 || 5 < choice)
        {
            printf("ERROR, choice out of bounds\n");
        } else
        {
            switch (choice)
            {
            case 1:
                write_new_file(&ppost);
                break;
            case 2:
                ppost = input_record();
                append_file(&ppost);
                break;
            case 3:
                printf("Enter firstname of the person you wish to search for: ");
                fflush(stdin);
                fgets(input, sizeof(input), stdin);
                search_by_firstname(input);
                break;
            case 4:
                printfile();
                break;
            case 5:
                continueProgram = 0;
                break;
            default:
                printf("ERROR\n");
                continueProgram = 0;
                break;
            }
        }
    }
}


//functions
void write_new_file(PERSON *inrecord) { //this needs changes
    FILE *filePointer;
    // if the file already exists, delete it
    if (filePointer = fopen("database.bin", "r")) {
        fclose(filePointer);
        remove("database.bin");
        printf("File deleted\n");
    }

    //create a new file
    if (filePointer = fopen("database.bin", "wb")) {
        fwrite(inrecord, sizeof(PERSON), 1, filePointer);
        fclose(filePointer);
    } else {
        printf("Error opening file\n");
    }
}

void printfile(void) { //this feels pretty chill 
    FILE *filePointer;
    PERSON person;
    if (filePointer = fopen("database.bin", "rb")) {
        while (fread(&person, sizeof(PERSON), 1, filePointer)) {
            printf("%s", person.firstname);
            printf("%s", person.famname);
            printf("%s", person.pers_number);
            printf("\n");
        }
        fclose(filePointer);
    } else {
        printf("Error opening file\n");
    }
}

void search_by_firstname(char *name) { //this feels pretty chill
    FILE *filePointer;
    PERSON *personPointer;
    if (filePointer = fopen("database.bin", "rb")) {
        while (fread(personPointer, sizeof(PERSON), 1, filePointer)) {
            if (strcmp(personPointer->firstname, name) == 0) {
                printf("%s %s %s\n", personPointer->firstname, personPointer->famname, personPointer->pers_number);
            }
        }
        fclose(filePointer);
    } else {
        printf("Error opening file\n");
    }
}

void append_file(PERSON *inrecord) {
    FILE *filePointer;
    if (filePointer = fopen("database.bin", "ab")) {
        fwrite(inrecord, sizeof(PERSON), 1, filePointer);
        fclose(filePointer);
        inrecord++;
    } else {
        printf("Error opening file\n");
    }
}

PERSON input_record(void) {
    PERSON person;
    //reset input buffer
    fflush(stdin);
    printf("Enter firstname: ");
    fgets(person.firstname, sizeof(person.firstname), stdin);
    printf("Enter familyname: ");
    fgets(person.famname, sizeof(person.famname), stdin);
    printf("Enter personal number: ");
    fgets(person.pers_number, sizeof(person.pers_number), stdin);
    return person;
}

void print_options() {
    printf("1 Create a new and delete the old file.\n");
    printf("2 Add a new person to the file.\n");
    printf("3 Search for a person in the file.\n");
    printf("4 Print out all in the file.\n");
    printf("5 Exit the program.\n");
}

/*
if the file exists
if the list is empty
*/