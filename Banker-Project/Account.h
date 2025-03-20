#ifndef Account_H_
#define Account_H_
#include <iostream>
#include <vector>
#include "fund.h"
using namespace std;

class Account{
    public:
    Account(const string name, const int id);
    bool withdrawl(const int ammout, const int fund,  transaction &temp);
    bool deposit(const int amount, const int fund,  transaction &temp);
    int getTotal()const;
    int getAccountNum()const;
    string getName()const;
    string getFund(const int num)const;
    int getFundAmmount(const int fund_)const;
    void addTransaction(const int fundnum, transaction &temp);
    void printTranasctionHistory()const;
    void printTransactionType(const int type)const;
    bool operator<(const Account &other) const;//Only ID
	bool operator<=(const Account &other) const;
	bool operator>=(const Account &other) const;
	bool operator>(const Account &other) const;
	bool operator==(const Account &other) const;
	bool operator!=(const Account &other) const;
    friend ostream& operator<<(ostream& stream, const Account& Account);

    private:
    string name_;
    int account_number;
    vector<fund> account_funds;
};
#endif

