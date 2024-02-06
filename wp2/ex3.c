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
PERSON input_record(void){ 
    PERSON person;
    printf("Enter the first name (max 20 letters): \n");
    scanf("%s", person.firstname);
 
    printf("Enter family name: (max 20 letters): \n");
    scanf("%s", person.famname);

    printf("Enter personnummer: \n");
    scanf("%12s", person.pers_number);

    return person;
};

// Creates a file and writes the first record
void write_new_file(PERSON *inrecord){
    FILE *file = fopen("person", "wb");

    if (file == NULL){
       printf("Cannot open.\n");
       return;
    }
    fwrite(inrecord, sizeof(PERSON), 1, file);
    fclose(file);
};

// Prints out all persons in the file
void printfile(void){
    FILE *file = fopen("person", "rb");

    if (file == NULL) {
       printf("Cannot open the file.\n");
       return;
    }

    PERSON person;

    while (fread(&person, sizeof(PERSON), 1, file) == 1) {
       printf("First name: %s, family name: %s, personnummer: %s \n", person.firstname, person.famname, person.pers_number);
    }
    
    fclose(file);
    
}; 

// Prints out the person if in list
void search_by_firstname(char *name){
    FILE *file = fopen("person", "rb");
    PERSON person;
    int found = 0;

    while(fread(&person, sizeof(PERSON), 1, file) == 1){
        if(strcmp(person.firstname, name) == 0){
            printf("Person: %s, %s, %s \n", person.firstname, person.famname, person.pers_number);
            found = 1;
        }
    }

    if (found == 0) {
       printf("No person with the name %s found.\n", name);
    }
    
    fclose(file);

};

// appends a new person to the file
void append_file(PERSON *inrecord){
    FILE *file = fopen("person", "ab");

    if (file == NULL) {
       printf("Cannot open the file.\n");
       return;
    }
    
    fwrite(inrecord, sizeof(PERSON), 1, file);
    fclose(file);

}; 


int main(void){
PERSON ppost;
int choice_nr;

printf("Choose one of the options:\n");
printf("1. Create a new and delete the old file.\n");
printf("2. Add a new person to the file.\n");
printf("3. Search for a person in the file.\n");
printf("4. Print out all in the file.\n");
printf("5. Exit the program.\n");
scanf("%d", &choice_nr);

switch (choice_nr){
    case 1:
        ppost = input_record();
        write_new_file(&ppost);
        break;

    case 2:
        ppost = input_record();
        append_file(&ppost);
        break;
    case 3:
        printf("Enter the first name: ");
        char name[20];
        scanf("%s", name);    
        search_by_firstname(name);
        break;

    case 4:
        printfile();
        break;

    case 5:
        return 0;
        break;

    default:
        printf("Not implemented yet.\n");
        break;
    }
}
