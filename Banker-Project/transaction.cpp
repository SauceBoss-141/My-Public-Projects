#include "transaction.h"

transaction::transaction()
{
}

transaction::transaction(char trans_action_type, int ID, int fund, int amount)
{

    account_id_ = ID;
    transaction_type_=trans_action_type;
    fund_=fund;
    amount_=amount;
}
transaction::transaction(char trans_action_type, int ID, int amount, string name)
{

    account_id_ = ID;
    transaction_type_=trans_action_type;
    amount_=amount;
    name_ = name;
}

transaction::transaction(char trans_action_type, int account_from, int fund_from, int account_num_too, int fund_too, int amount)
{
    account_id_ = account_from;
    fund_=fund_from;
    //Account that gets the moneyfrom the transfer
    acountnum2_= account_num_too;
    fund2_ = fund_too;

    transaction_type_=trans_action_type;
    amount_=amount;

}

char transaction::getTransactionType() const
{
    return transaction_type_;
}

int transaction::getID() const
{
    return account_id_;
}

int transaction::getSecondID() const
{
    return acountnum2_;
}

void transaction::ifFail(bool var)
{   if(var == true){
    fail=true;
}else{
    fail = false;
}
}
int transaction::getAmount()const
{
    return amount_;
}

int transaction::getFund() const
{
    return fund_;
}
int transaction::getSecondFund()
{
    return fund2_;
}
string transaction::getName() const
{
    return name_;
}
ostream &operator<<(ostream &stream, const transaction &transaction)
{   if(transaction.transaction_type_ == 'T'){
    if(transaction.fail == true){
    stream<< transaction.transaction_type_<<" "<< transaction.account_id_ << " "<< transaction.fund_<< " " <<transaction.acountnum2_<<" "<< transaction.fund2_<< " "<< transaction.amount_<< "(Transaction fail)";
    }else{
    stream<< transaction.transaction_type_<<" "<< transaction.account_id_ << " "<< transaction.fund_<< " " <<transaction.acountnum2_<<" "<< transaction.fund2_<< " "<< transaction.amount_;
    }
}else{
    if(transaction.fail == true ){
    stream<< transaction.transaction_type_<<" "<< transaction.account_id_<<" "<< transaction.fund_<<" "<< transaction.amount_<< "(Transaction fail)";
}else{
    stream<< transaction.transaction_type_<<" "<< transaction.account_id_<<" "<< transaction.fund_<<" "<< transaction.amount_;
}
}
    return stream;
}