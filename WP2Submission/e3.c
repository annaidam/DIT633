// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 3
// Exercise 3
// Submission code: 31299177

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Create a person's record (information)
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

// Create a new file with the specified filename and write a record to the file and close it
void write_new_file(PERSON *inrecord) {
    char *filename = "newFile.txt";
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        perror("File doesn't exist\n\n");
        return;
    }

    if (fwrite(inrecord, sizeof(PERSON), 1, file)) {
        printf("\nSuccesfully created file.\n");
    }

    fclose(file);
}

// Print all records in the file
void printfile(void) {
    char *filename = "newFile.txt";
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        perror("File doesn't exist\n\n");
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

// Search for people with specific first or last name
void search_by_firstname(char *name) {
    char *filename = "newFile.txt";
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        perror("File doesn't exist\n\n");
        return;
    }
    PERSON placeholderPerson;

    // Print everyone with the matching name
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

    // If no people found with the searched name
    printf("Person with the name '%s' was not found\n\n", name);
    fclose(file);
}

// Put new person to a temporary record and then add it to the end of it
void append_file(PERSON *inrecord) {
    char *filename = "newFile.txt";
    FILE *file = fopen(filename, "ab");

    if (file == NULL) {
        perror("File doesn't exist\n\n");
        return;
    }

    fwrite(inrecord, sizeof(PERSON), 1, file);
    fclose(file);
}

// main function
int main(void){
    PERSON ppost;    

    int option;
    do {
        printf("\n1 Create a new and delete the old file.\n2 Add a new person to the file.\n3 Search for a person in the file.\n4 Print out all in the file.\n5 Exit the program.\n\n");
        scanf(" %d", &option);

        switch (option) {
            case 1:
                write_new_file(&ppost);
                break;

            case 2:
                ppost = input_record();
                append_file(&ppost);
                break;

            case 3:
                printf("\nWrite the name you want to search for: ");
                char searchName[20];
                scanf("%s", searchName);
                search_by_firstname(searchName);
                break;

            case 4:
                printfile();
                break;

            case 5:
                printf("\nExiting the program...\n\n");
                break;

            default:
                printf("\nInvalid option\n\n");
            break;
        }

    } while (option != 5);
    
    return 0;
}