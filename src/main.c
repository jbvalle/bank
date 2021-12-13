#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    
    char owner[15];
    int transaction_number;
    int balance;

} accounts_t;

typedef struct{
    
    char bank_name[15];
    accounts_t account[10];
} bank_t;

int transfer(bank_t *bank, int amount, int reviever_index, int sender_index){
    
    bank->account[reviever_index].balance += amount;
    bank->account[reviever_index].transaction_number += 1;

    bank->account[sender_index].balance -= amount;
    bank->account[sender_index].transaction_number += 1;

    if(bank == NULL){
        printf("\nERROR: Invalid Parameter");
        exit(1);
    } else return 0;
}

int open_account(bank_t *bank, char *owner_name, int starting_balance, int *account_counter){
    //Assign name to account   
    strcpy(bank->account[*account_counter].owner, owner_name);
    //Set transaction num to zero
    bank->account[*account_counter].transaction_number = 0;
    //Set Starting 
    bank->account[*account_counter].balance = starting_balance;
    //Increment num of accoutns
    *account_counter += 1;

    if(bank == NULL){
        printf("\nERROR: Invalid Parameter");
        exit(1);
    } else return 0;
}
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

int show_accounts(bank_t *bank, int *account_counter){


    for(int i = 0; i < *account_counter; i++){

        printf("| Account Index: %2d | Owner: %8s | Balance: %6d | Total Transactions: %3d |", i, bank->account[i].owner,bank->account[i].balance,bank->account[i].transaction_number);
        printf("\n");
    }


    if((bank == NULL)||(account_counter == NULL)){
        printf("ERROR: Invalid Parameter");
        exit(1);
    }else return 0;
}
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

    while(strcmp(args[0],"exit") != 0){
        //Parse Input into args
        read_input(args);

        if(strcmp(args[0],"open_account")==0){
            open_account(bank, args[1], atoi(args[2]),&account_counter);     
            printf("\nAccount of %s opened | Current balance: %d \n\n", args[1], atoi(args[2]));
        }


        if(strcmp(args[0],"transfer")==0){
            transfer(bank, atoi(args[1]), atoi(args[2]), atoi(args[3]));
            printf("\n\nTransaction #%d from %8s to %8s #%d of Amount: €%6d\n\n ",bank->account[atoi(args[3])].transaction_number, bank->account[atoi(args[3])].owner,bank->account[atoi(args[2])].owner,bank->account[atoi(args[2])].transaction_number, atoi(args[1]));
        }

        if(strcmp(args[0],"show_accounts")==0){
            show_accounts(bank, &account_counter);
        }
    }

    free(args);args = NULL;
    free(bank);bank = NULL;

    return 0;

}

