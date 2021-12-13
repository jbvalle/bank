#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bank.h"


int show_accounts(bank_t *bank, int *account_counter){


    for(int i = 0; i < *account_counter; i++){

        printf("| Account Index: %2d | Owner: %8s | Balance: %6d | Total Transactions: %3d |", i, bank->account[i].owner,bank->account[i].balance,bank->account[i].transaction_number);
        printf("\n\n");
    }


    if((bank == NULL)||(account_counter == NULL)){
        printf("ERROR: Invalid Parameter");
        exit(1);
    }else return 0;
}
