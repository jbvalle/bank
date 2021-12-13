#ifndef OPEN_ACCOUNT_H
#define OPEN_ACCOUNT_H
#include "../include/bank.h"

int open_account(bank_t *bank, char *owner_name, int starting_balance, int *account_counter);

#endif

