#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bank.h"


int show_accounts(bank_t *bank, int *account_counter){

    int summe = 0;
    //Output all accounts' owners, balances, total transactions
    for(int i = 0; i < *account_counter; i++){
        printf("+-----------------------------------------------------------------------------------+\n");
        printf("| Account Index: %2d | Owner: %10s | Balance: %6d | Total Transactions: %3d |\n", i, bank->account[i].owner,bank->account[i].balance,bank->account[i].transaction_number);
        printf("+-----------------------------------------------------------------------------------+\n");
    }printf("\n");
    
    //Calculate Total Sum of all balances
    for(int i = 0; i < *account_counter; i++)summe += bank->account[i].balance;

    //Output Sum
    printf("+----------------------------+\n");
    printf("|Total Accounts' Sum: %7d|\n",summe);
    printf("+----------------------------+\n");
    if((bank == NULL)||(account_counter == NULL)){
        printf("ERROR: Invalid Parameter");
        exit(1);
    }else return 0;
}
