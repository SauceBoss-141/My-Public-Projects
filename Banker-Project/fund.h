#ifndef fund_H_
#define fund_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class transaction;
class fund{
    public:
    fund(string name);//Constructor
    bool Deposit(int input, transaction &trans);//deosit into the fund
    bool Withdrawl(int input, transaction& trans);//Withdraw from the fund
    int getTotal()const;//Return the total of the fund
    void addTransaction(transaction &trans);//Add a transaction to our storage
    void printTransactionHistory()const; // Print All  Transactions 
    string getFund()const;
    friend ostream& operator<<(ostream& stream, const fund & fund);
    fund(const fund&) = default;             // Copy constructor
    fund(fund&&) = default;                  // Move constructor
    fund& operator=(const fund&) = default;  // Copy assignment
    fund& operator=(fund&&) = default;       // Move assignment
    ~fund() = default;

    private:
    int total_;
    string fund_type;
    vector<transaction> transaction_history_;
};
#endif