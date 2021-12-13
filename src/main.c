#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bank.h"
#include "../include/open_account.h"
#include "../include/transfer.h"
#include "../include/read_input.h"
#include "../include/show_accounts.h"

int main(void){

    bank_t *bank = malloc(sizeof(bank_t));;
    int account_counter = 0;

    //Initialize arguments values -> input stream parsed to **args[0 - 2]
    char **args = malloc(4 * sizeof(char*));
    char arg1[20],arg2[20],arg3[20], arg4[20];

    args[0] = arg1;
    args[1] = arg2;
    args[2] = arg3;
    args[3] = arg4;


    show_accounts(bank, &account_counter);
    while(strcmp(args[0],"exit") != 0){
        //Parse Input into args
        read_input(args);

        if(strcmp(args[0],"open_account")==0){
            open_account(bank, args[1], atoi(args[2]),&account_counter);     
        }


        if(strcmp(args[0],"transfer")==0){
            transfer(bank, atoi(args[1]), atoi(args[2]), atoi(args[3]));
        }

        if(strcmp(args[0],"show_accounts")==0){
            show_accounts(bank, &account_counter);
        }
    }

    free(args);args = NULL;
    free(bank);bank = NULL;

    return 0;

}

