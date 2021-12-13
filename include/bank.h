#ifndef BANK_H
#define BANK_H

typedef struct{
    
    char owner[15];
    int transaction_number;
    int balance;

} accounts_t;

typedef struct{
    
    char bank_name[15];
    accounts_t account[10];
} bank_t;


#endif

