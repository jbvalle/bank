#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int read_input(char **args){

    char letter, temp[80];
    for(int i = 0; i < 80; i++)temp[i] = '\0';
    for(int i = 0; (letter = getchar()) != '\n'; i++){

        temp[i] = letter;
    }

    char delim[2] = " ";
    char *token;

    //delimit temp string into tokens
    token = strtok(temp,delim);

    for(int i = 0; (token != NULL)&&(i < 4); i++){
        strcpy(args[i],token);
        token = strtok(NULL,delim);
    }

   if(args == NULL){
        printf("\nERROR: Invalid Parameter");
        exit(1);
    } else return 0;
}
