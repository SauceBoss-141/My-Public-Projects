#include "customer.h"

Customer::Customer(int id, string last_Name, string first_name)
{
    id_ = id;
    last_name_= last_Name;
    first_name_ = first_name;
}

bool Customer::printHistory()
{   if(history_.size()==0){
        return false;
    }else{
        cout<<"Transaction history for "<< last_name_<<", "<<first_name_<<endl;
        for(int i =0; i< history_.size();i++){
            cout<<history_[i]<<endl;
        }
        return true;
    }
    
}

int Customer::getID()const
{
    return id_;
}

string Customer::getLastName()const
{
    return last_name_;
}

void Customer::addTransaction(transaction t)
{
    history_.push_back(t);
}

string Customer::getFirstName()const
{
    return first_name_;
}

ostream &operator<<(ostream &stream, const Customer &customer)
{
    stream<<customer.getFirstName()<<" "<<customer.getLastName()<<". ID# "<<customer.getID();

    return stream;
}
