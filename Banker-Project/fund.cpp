#include "fund.h"
#include "transaction.h"
fund::fund(string name)
{
    fund_type = name;
    total_ = 0;
}
bool fund::Deposit(int input, transaction& trans)
{   if(input >0){
    total_+=input;
    addTransaction(trans);
    return true;
}else{
    trans.ifFail(true);
    addTransaction(trans);
}
    return false;
}
bool fund::Withdrawl(int input, transaction& trans)
{   if((input<= total_)){
        if(input >=0){
            total_-=input;
            addTransaction(trans);
            return true;
        }else{
            trans.ifFail(true);
            addTransaction(trans);
            return false;

        } 
}else{
    trans.ifFail(true);
    addTransaction(trans);
}
    return false;
}
int fund::getTotal() const
{
    return total_;
}
void fund::addTransaction(transaction & trans)
{
    transaction_history_.push_back(trans);
}
// Print All  Transactions 
void fund::printTransactionHistory() const {
    if(transaction_history_.size() ==0){
        cout<<"No transaction history available."<<endl;
    }else{
    for (const auto &trans : transaction_history_) {
        cout << trans << endl; 
    }
    }
}
string fund::getFund() const
{
    return fund_type;
}
ostream &operator<<(ostream &stream, const fund &fund)
{
    stream << fund.fund_type<< ": $"<<fund.total_;
    return stream;
}