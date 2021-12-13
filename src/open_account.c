#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bank.h"
int open_account(bank_t *bank, char *owner_name, int starting_balance, int *account_counter){
    //Assign name to account   
    strcpy(bank->account[*account_counter].owner, owner_name);
    //Set transaction num to zero
    bank->account[*account_counter].transaction_number = 0;
    //Set Starting 
    bank->account[*account_counter].balance = starting_balance;
    //Increment num of accoutns
    *account_counter += 1;

    printf("\nAccount of %s opened | Current balance: %d \n\n", owner_name, starting_balance);

    if(bank == NULL){
        printf("\nERROR: Invalid Parameter");
        exit(1);
    } else return 0;
}
