
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

if (argc == 1)
{
  printf("No argument provided. Choose a number between 1-5.\n");
} else if (argc > 2){
        printf("Too many argumnets provided, choose one between 1-5.\n");
    } else if (strcmp(argv[1], "1") == 0){
        printf("Cows have best friends.\n");
    } else if(strcmp(argv[1], "2") == 0){
        printf("Bananas are berries.\n");
    } else if(strcmp(argv[1], "3") == 0){
        printf("Antarctica is world's biggest desert.\n");
    }else if(strcmp(argv[1], "4") == 0){
        printf("A group of flamingos is called a \"flamboyance.\"\n");
    }else if(strcmp(argv[1], "5") == 0){
        printf("Goats have rectangular pupils.\n");
    } else {
        printf("Provided wrong argument, please choose from numbers 1-5.");
    }
    
    return 0;
}