// (C) David Schön, Milena Mackowiak, Anna Mäkinen, group: 3 (2024)
// Work package 3
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)

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
// Reads a person’s record.
PERSON input_record(void) {
    PERSON newPerson;

    printf("Write first name: ");
    scanf("%s", newPerson.firstname);

    printf("Write family name: ");
    scanf("%s", newPerson.famname);

    printf("Write personal number (yyyymmddnnnc): ");
    scanf("%s", newPerson.pers_number);

    return newPerson;
}

// Program creates a new file with the specified filename (hardcoded, fixed) and writes a first dummy record to the file and then close it. 
void write_new_file(PERSON *inrecord) {
    char *filename = "random.txt";
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        perror("Cannot open the file\n\n");
        return;
    }

    fwrite(inrecord, sizeof(PERSON), 1, file);

    fclose(file);
}

// Prints out all persons in the file
void printfile(void) {
    char *filename = "random.txt";
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        perror("Cannot open the file\n\n");
        return;
    }

    PERSON placeholderPerson;

    while (fread(&placeholderPerson, sizeof(PERSON), 1, file) == 1) {
        printf("\nFirst name is %s\n", placeholderPerson.firstname);
        printf("Family name is %s\n", placeholderPerson.famname);
        printf("Personal number is %s\n\n", placeholderPerson.pers_number);
    }

    fclose(file);
    
}

// Gives you an opportunity to search for all persons with either a specified first name or
// family name (by choice). The program prints out all persons with that name.
void search_by_firstname(char *name) {
    char *filename = "random.txt";
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        perror("Cannot open the file\n\n");
        return;
    }

    PERSON placeholderPerson;

    while (fread(&placeholderPerson, sizeof(PERSON), 1, file) == 1) {
        if (strcmp(placeholderPerson.firstname, name) == 0 || strcmp(placeholderPerson.famname, name) == 0) {
            printf("\nFound them!\n");
            printf("First name is %s\n", placeholderPerson.firstname);
            printf("Family name is %s\n", placeholderPerson.famname);
            printf("Personal number is %s\n\n", placeholderPerson.pers_number);
            fclose(file);
            return;
        }
    }

    printf("Person with the name '%s' was not found\n\n", name);
    fclose(file);
}

// Gives an opportunity to put in one new person to a temp record and then add this record in
// the end of the file.
void append_file(PERSON *inrecord) {
    char *filename = "random.txt";
    FILE *file = fopen(filename, "ab");

    if (file == NULL) {
        perror("Cannot open the file\n\n");
        return;
    }

    fwrite(inrecord, sizeof(PERSON), 1, file);
    fclose(file);
}

// main
int main(void){
    PERSON ppost;    

    int option;
    do {
        printf("1 Create a new and delete the old file.\n2 Add a new person to the file.\n3 Search for a person in the file.\n4 Print out all in the file.\n5 Exit the program.\n\n");
        scanf(" %d", &option);

        switch (option) {
            case 1:
                ppost = input_record();
                write_new_file(&ppost);
                break;

            case 2:
                ppost = input_record();
                append_file(&ppost);
                break;

            case 3:
                printf("Write the name you want to search for: ");
                char searchName[20];
                scanf("%s", searchName);
                search_by_firstname(searchName);
                break;

            case 4:
                printfile();
                break;

            case 5:
                printf("Exiting the program...\n\n");
                break;

            default:
                printf("Invalid option\n\n");
            break;
        }

    } while (option != 5);
    
    return 0;
}