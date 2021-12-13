_____________________________________________________

+****************************+
|Author: John Bryan Valle    |
|Jahrgang: IC21              |
|Project: bank               |
+****************************+

This Project aimes to demonstrate structs and emulates a bank database which is able to add accounts, transfer balances and shows total entries.

- the project is implemented in a basic file system:
/bank:
|
+-----> /bank/src: *.c, .exe/.elf, Makefile (Important for Build!)
|               |
|               +----> /bank/src/obj: *.o
|
+-----> README.txt
|
|
+-----> /bank/include: *.h

Features:
1. Input is a terminal based environment
2. Adding Account, transfering balances and displaying database entries with:
open_account NAME AMOUNT | transfer AMOUNT RECIEVER_INDEX SENDER_INDEX | show_accounts

+*****Building Process & Execution:***********************+
|                                                         |
| 1. Build Project from bank/src/ directory:              |
| :$ make                                                 |
|                                                         |
| 2. Execute main program :                               |
| :$ ./main                                               |
+*********************************************************+  

3. Apply operations:

-> add new account with starting amount
+--------------------------+
| open_account NAME AMOUNT |
+--------------------------+
i.e. open_account Richart 4580

-> transfer money between owners
+---------------------------------------------+
| transfer AMOUNT RECIEVER_INDEX SENDER_INDEX |
+---------------------------------------------+
i.e. transfer 350 0 1
(TIPP: use show_accounts to display all owners and indeces)

-> Display all Owners and bank entries, use this to display indeces for transfer
+---------------+
| show_accounts |
+---------------+
i.e. transfer 350 0 1

