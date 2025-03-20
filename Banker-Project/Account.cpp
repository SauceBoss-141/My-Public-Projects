#include "Account.h"
#include <iostream>
#include <vector>
#include "fund.h"
#include "transaction.h"
using namespace std;
Account::Account(const string name, const int id)
{
    name_ = name;
    account_number = id;
    //Create 10 fund. Put into vector below
    account_funds.push_back(fund("Money Market"));
    account_funds.push_back(fund("Prime Money Market"));
    account_funds.push_back(fund("Long Term Bond"));
    account_funds.push_back(fund("Short Term Bond"));
    account_funds.push_back(fund("500 Index"));
    account_funds.push_back(fund("Captial Value"));
    account_funds.push_back(fund("Growth Equity"));
    account_funds.push_back(fund("Growth Index"));
}
bool Account::withdrawl(const int amount_, const int fund_ ,  transaction &temp)
{   if(fund_ == 0){
        if(account_funds[0].Withdrawl(amount_, temp)){
            return true;
        }else{
            int neededAmount = amount_-account_funds[0].getTotal();
            if(account_funds[1].getTotal()>= neededAmount){
                transaction newTransaction= transaction(temp.getTransactionType(), temp.getID(), 0, account_funds[0].getTotal());
                newTransaction.ifFail(false);
                account_funds[0].Withdrawl(account_funds[0].getTotal(),newTransaction);
                newTransaction.ifFail(false);
                newTransaction= transaction(temp.getTransactionType(), temp.getID(), 1, neededAmount);
                account_funds[1].Withdrawl(neededAmount, newTransaction);
                return true;
                
            }
            return false;
        }
    }else if(fund_ == 1){
        if(account_funds[1].Withdrawl(amount_, temp)){//Add the reverse logic from fund
            return true;
        }else{
            int neededAmount = amount_-account_funds[1].getTotal();
            if(account_funds[0].getTotal()>= neededAmount){
                transaction newTransaction= transaction(temp.getTransactionType(), temp.getID(), 1, account_funds[1].getTotal());
                newTransaction.ifFail(false);
                account_funds[1].Withdrawl(account_funds[1].getTotal(),newTransaction);
                newTransaction.ifFail(false);
                newTransaction= transaction(temp.getTransactionType(), temp.getID(), 0, neededAmount);
                account_funds[0].Withdrawl(neededAmount, newTransaction);
                return true;
                
            }
            return false;
            
        }
    }else if(fund_==2){
        if(account_funds[2].getTotal()>= amount_){
            account_funds[2].Withdrawl(amount_, temp);
            return true;
        }else{
            int neededAmount = amount_-account_funds[2].getTotal();
            if(account_funds[3].getTotal()>= neededAmount){
                transaction newTransaction= transaction(temp.getTransactionType(), temp.getID(), 2, account_funds[2].getTotal());

                account_funds[2].Withdrawl(account_funds[2].getTotal(),newTransaction);
                newTransaction= transaction(temp.getTransactionType(), temp.getID(), 3, neededAmount);
                account_funds[3].Withdrawl(neededAmount, newTransaction);
                return true;
                
            }
            return false;
        }
    }else if(fund_==3){
        if( account_funds[3].getTotal()>=amount_){
            account_funds[3].Withdrawl(amount_, temp);
            return true;
        }else{
            int neededAmount = amount_-account_funds[3].getTotal();
            if(account_funds[2].getTotal()>= neededAmount){
                transaction newTransaction= transaction(temp.getTransactionType(), temp.getID(), 3, account_funds[3].getTotal());
                account_funds[3].Withdrawl(account_funds[3].getTotal(),newTransaction);
                newTransaction= transaction(temp.getTransactionType(), temp.getID(), 2, neededAmount);
                account_funds[2].Withdrawl(neededAmount, newTransaction);
                return true;
                
            }
            return false; 
        }
    }else if(fund_==4){
        return (account_funds[4].Withdrawl(amount_, temp));  
    }else if(fund_==5){
        return (account_funds[5].Withdrawl(amount_, temp));  
    }else if(fund_==6){
        return (account_funds[6].Withdrawl(amount_, temp));  
    }else if(fund_==7){
        return (account_funds[7].Withdrawl(amount_, temp));
    }
    return false;
}
bool Account::deposit(const int amount_, const int fund_,  transaction &temp)
{
    if(fund_ == 0){
        return(account_funds[0].Deposit(amount_, temp));  
    }else if(fund_ == 1){
        return(account_funds[1].Deposit(amount_, temp ));  
    }else if(fund_==2){
        return(account_funds[2].Deposit(amount_, temp ));   
    }else if(fund_==3){
        return(account_funds[3].Deposit(amount_, temp));
    }else if(fund_==4){
        return(account_funds[4].Deposit(amount_, temp));
    }else if(fund_==5){
        return(account_funds[5].Deposit(amount_, temp )); 
    }else if(fund_==6){
        return(account_funds[6].Deposit(amount_, temp));
    }else if(fund_==7){
        return(account_funds[7].Deposit(amount_, temp ));       
    }
    return false;
}
int Account::getTotal() const
{
    int amount=0;
    for(int i =0; i <account_funds.size(); i++){
        amount += account_funds[i].getTotal();
    }
    return amount;
}
int Account::getAccountNum() const
{
    return account_number;
}
string Account::getName() const
{
    return name_;
}
string Account::getFund(const int num)const 
{
    return account_funds[num].getFund();
}
int Account::getFundAmmount(const int fund_) const
{
    return account_funds[fund_].getTotal();
}
void Account::addTransaction(const int fundnum, transaction &temp)
{
    account_funds[fundnum].addTransaction(temp);
}
void Account::printTranasctionHistory() const
{cout<<"Transaction History for "<<name_<<" by fund."<<endl;
for(int i = 0; i< account_funds.size(); i++){
    cout<<account_funds[i]<<endl;
    account_funds[i].printTransactionHistory();
    
}
cout<<"\n";
}
void Account::printTransactionType(const int type) const
{ cout<<"Transaction History for "<<name_<<" by "<< account_funds[type].getFund()<<endl;
  account_funds[type].printTransactionHistory();
  cout<<"\n";
}
bool Account::operator<(const Account &other) const
{   
    return this->account_number< other.account_number;
}
bool Account::operator<=(const Account &other) const
{
    return this->account_number<= other.account_number;
}
bool Account::operator>=(const Account &other) const
{
    return this->account_number>= other.account_number;
}
bool Account::operator>(const Account &other) const
{
    return this->account_number>other.account_number;
}
bool Account::operator==(const Account &other) const
{
    return account_number==other.account_number;
}
bool Account::operator!=(const Account &other) const
{
    return !(*this==other);
}
ostream &operator<<(ostream &stream, const Account &Account)
{
    stream << Account.name_<< " Account ID: "<< Account.account_number;
    for(int i =0; i < Account.account_funds.size(); i++){
        stream<< '\n'<< Account.account_funds[i];
    }
    return stream;
}