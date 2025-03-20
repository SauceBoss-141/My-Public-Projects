#ifndef customer_H
#define customer_H
#include <string>
#include <iostream>
#include <vector>
#include "transaction2.h"
using namespace std;

// -------------------------------- Customer Class  ----------------------------------------------
// Description: Customer class used to store information about a customer
// Contains an ID, first and last name
// Contains a list of transactions associated with the account 
// Can be printed out
// -----------------------------------------------------------------------------------------------
class Customer{

    public:

    // -------------------------------- Customer Constructor  ----------------------------------------
    // Description: takes in an int for id, string for last and first name
    // Sets data variables.
    // -----------------------------------------------------------------------------------------------
    Customer(int id, string last_Name, string first_name);

    // ------------------------------- Customer Print History  ---------------------------------------
    // Description: Prints the transaction history of the customer if any is present
    // Returns bool
    // -----------------------------------------------------------------------------------------------
    bool printHistory();

    // ------------------------------- Customer get ID  ---------------------------------------------
    // Description: returns the id in the form of int
    // Returns int
    // -----------------------------------------------------------------------------------------------
    int getID()const;

    // ------------------------------- Customer get First Name  --------------------------------------
    // Description: returns the first name of the customer
    // Returns string
    // -----------------------------------------------------------------------------------------------
    string getFirstName()const;

    // ------------------------------- Customer get Last Name  ---------------------------------------
    // Description: returns the last name of the customer
    // Returns string
    // -----------------------------------------------------------------------------------------------
    string getLastName()const;

    // ------------------------------- Customer OStream  ---------------------------------------------
    // Description: Prints first name, last name, ID number
    // Returns stream
    // -----------------------------------------------------------------------------------------------
    friend ostream& operator<<(ostream& stream, const Customer& customer);

    // ------------------------------- Customer add Transaction  -------------------------------------
    // Description: Takes in a transaction object
    // Adds transaction object to customers history vector
    // -----------------------------------------------------------------------------------------------
    void addTransaction(transaction t);

    private:
    int id_=0;
    string first_name_="";
    string last_name_="";
    vector<transaction> history_= vector<transaction>();
};
#endif