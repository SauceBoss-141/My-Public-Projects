#ifndef transaction_H_
#define transaction_H_
#include <iostream>
#include <string>
#include "fund.h"
using namespace std;


class transaction{
    public:
    transaction();
    transaction(char trans_action_type, int ID, int fund, int amount);//for  regular trnasaction
    transaction(char trans_action_type,int ID,  int amount, string name);//for opening an account
    transaction(char trans_action_type, int account_from, int fund_from, int account_num_too, int fund_too, int ammount );//for a transfer
    char getTransactionType()const;
    int getID()const;
    int getSecondID()const;
    void ifFail(bool var);
    int getAmount()const;
    int getFund()const;
    int getSecondFund();
    string getName()const;
    friend ostream& operator<<(ostream& stream, const transaction& transaction);

    private:
    int account_id_;
    char transaction_type_;
    int fund_ ;
    int amount_;
    string name_;
    //Transfer situation
    int acountnum2_;
    int fund2_;
    bool fail = false;
};
#endif