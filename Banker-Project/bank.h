#ifndef bank_H_
#define bank_H_
#include <iostream>
#include <string>
#include "BStree.h"
#include "transaction.h"
#include "Account.h"
#include <queue>
#include <fstream>
#include <sstream>
using namespace std;

class bank{

    public:
    void file_in(const string file_name);//Will read a file na dpopulate que for execution 
    void execute_();//execute commands such as deposit or withdraw. Searches data base for account
    bool deposit(Account &client_, const int fund_, const int amount_ ,transaction& current);//despit th emoney into
    bool withdaraw(Account &client_, const int fund_, const int amount_, transaction& current);//withdraws the emoney
    void create_account(const int ID, const string name );//Creates a new account and stores it in the data base
    void printFund(const Account & client, const int fund)const;
    void printHistory(const Account & client)const;

    private:

    int num_of_accounts_;
    queue<transaction> incoming_transactions;
    BStree<Account> accounts_;

};
#endif