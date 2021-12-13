#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bank.h"

int transfer(bank_t *bank, int amount, int reciever_index, int sender_index){
    
    bank->account[reciever_index].balance += amount;
    bank->account[reciever_index].transaction_number += 1;

    bank->account[sender_index].balance -= amount;
    bank->account[sender_index].transaction_number += 1;
    printf("+----------------------------------------------------------------------+\n");
    printf("|Transaction #%3d from %10s to %10s #%3d of Amount: €%6d|\n",bank->account[sender_index].transaction_number, bank->account[sender_index].owner,bank->account[reciever_index].owner,bank->account[reciever_index].transaction_number, amount);
    printf("+----------------------------------------------------------------------+\n");

    if(bank == NULL){
        printf("\nERROR: Invalid Parameter");
        exit(1);
    } else return 0;
}
