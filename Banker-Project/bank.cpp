#include "bank.h"
#include "Account.h"
#include "transaction.h"
void bank::file_in(const string file_name)
{
    ifstream file(file_name);
    if(!file.is_open()){
        cerr<< "Error: Could not open file "<< file_name<<endl;
        return;
    }
    string line;
    while(getline(file, line)){
        istringstream ss(line);
        char trans_type;
        ss>>trans_type;
        transaction trans;
        switch(trans_type){
            case 'O':{
            int id;
            string first_name, last_name;
            ss>>id>>first_name>>last_name;
            string full_name = first_name+ " "+ last_name;
            trans = transaction(trans_type, id, 0 , full_name);
            break;
        }
        case 'D':
        case 'W':{
            int id, fund, amount;
            ss>>id>>fund>>amount;
            trans = transaction(trans_type, id, fund, amount);
            break;
        }
        case 'T':{
            int from_id, from_fund, to_id, to_fund, amount;
            ss>>from_id>>from_fund>>to_id>>to_fund>>amount;
            trans= transaction(trans_type, from_id, from_fund, to_id, to_fund, amount);
            break;
        }
        case 'F':{
            int id, fund;
            ss>>id>>fund;
            trans = transaction(trans_type, id, fund, 0);
            break;
        }
        case 'A':{
            int id;
            ss>>id;
            trans = transaction(trans_type, id, 0,0);
            break;
        }
        default:
        cerr<<"Error: Invalid transaction type"<<endl;
        }
        incoming_transactions.push(trans);
    }
    file.close();
}
bool bank::withdaraw(Account & client_, const int fund_, const int amount_, transaction& current)
{   
    return(client_.withdrawl(amount_, fund_, current));
}

void bank::create_account(const int ID, const string name)
{   Account * p_acount;
    if(ID <=0){
        cerr<<"Error: Cannot create an account with a negative ID number."<<endl;
    }else if(accounts_.Retrieve(ID,  p_acount)==true){
        cerr<<"Error: Account: " << ID<<" already exists"<<endl;
    }else{
        Account *newAccount = new Account(name, ID);
        
        accounts_.Insert(newAccount);
    }
}
void bank::printFund(const Account & client, const int fund) const
{
    client.printTransactionType(fund);
}
void bank::printHistory(const Account &client) const
{
    client.printTranasctionHistory();
}
void bank::execute_()
{
    while(!incoming_transactions.empty()){
        transaction current = incoming_transactions.front();
        if(current.getTransactionType() == 'O'){
            create_account(current.getID(), current.getName());
        }else if(current.getTransactionType() == 'D'){
            Account *client;
            
            if(accounts_.Retrieve(current.getID(), client)){
                if(current.getFund()>7|| current.getFund()<0){
                    cerr<<"Error: Fund doesnt exist. Please enter a valid fund. "<<endl;
                }else if(current.getAmount()<=0){
                    cerr<<"Error: Cannot deposit a non-postive number"<<endl;
                }else{
                deposit(*client, current.getFund(), current.getAmount(), current);
                }
            }else{
                cerr<<"Error: Account: " << current.getID()<<" not found"<<endl;
            }
        }else if(current.getTransactionType() == 'W'){
            Account*client;
            if(accounts_.Retrieve(current.getID(), client)){
                if(current.getFund()>7 || current.getFund()<0){
                    cerr<<"Error: Fund doesnt exist. Please enter a valid fund. "<<endl;
                }else if(current.getAmount()<=0){
                    cerr<<"Error: Cannot withdraw a non-postive number"<<endl;
                }else{
                    if(!withdaraw(*client,current.getFund(), current.getAmount(), current)){
                    cerr<<"Error: Cannot Withdrawl $" << current.getAmount() << " from account " << client->getName()<< " Fund: " << client->getFund(current.getFund())<<endl;
                }
                }
            }else{
                cerr<<"Error: Account: " << current.getID()<<" not found"<<endl;
            }
        }else if(current.getTransactionType() == 'T'){
            Account* client;
            Account* client2;
            if(current.getFund()>7 || current.getFund()<0 || current.getSecondFund()>7 || current.getSecondFund()<0){
                cerr<<"Error: Fund doesnt exist. Please enter a valid fund. "<<endl;
            }else if(current.getAmount()<0){
                    cerr<<"Error: Cannot transfer a non-postive number"<<endl;
            }else if(accounts_.Retrieve(current.getID(), client)&&(accounts_.Retrieve(current.getSecondID(), client2))){
                if(client->getAccountNum()==client2->getAccountNum()){
                    if(((current.getFund()==0)&&(current.getSecondFund()==1)) || ((current.getFund()==1)&&(current.getSecondFund()==0)) ){
                        if(current.getAmount()<=(client->getFundAmmount(current.getFund()))){
                                withdaraw(*client, current.getFund(),current.getAmount(), current);
                                deposit(*client2, current.getSecondFund(), current.getAmount(), current);
                                
                        }else{
                            cerr<<"Error: Cannot transfer $"<<current.getAmount()<<" from account "<<current.getID()<< " fund " << client->getFund(current.getFund())<<" to account "<<current.getSecondID()<< " fund "<<client2->getFund(current.getSecondFund())<<endl;
                            current.ifFail(true);
                            client->addTransaction(current.getFund(),current);
                        }
                    }else if(((current.getFund()==2)&&(current.getSecondFund()==3)) || ((current.getFund()==3)&&(current.getSecondFund()==2)) ){
                        if(current.getAmount()<=(client->getFundAmmount(current.getFund()))){
                                withdaraw(*client, current.getFund(),current.getAmount(), current);
                                deposit(*client2, current.getSecondFund(), current.getAmount(), current);
                                
                        }else{
                            cerr<<"Error: Cannot transfer $"<<current.getAmount()<<" from account "<<current.getID()<< " fund " << client->getFund(current.getFund())<<" to account "<<current.getSecondID()<< " fund "<<client2->getFund(current.getSecondFund())<<endl;
                            current.ifFail(true);
                            client->addTransaction(current.getFund(),current);
                        }
                    }else if((withdaraw(*client, current.getFund(),current.getAmount(), current))){
                        deposit(*client2, current.getSecondFund(), current.getAmount(), current);

                        }else{
                            cerr<<"Error: Cannot transfer $"<<current.getAmount()<<" from account"<<current.getID()<< " fund " << client->getFund(current.getFund())<<" to account "<<current.getSecondID()<< " fund "<<client2->getFund(current.getSecondFund())<<endl;
                        }
                    }
                else if(withdaraw(*client, current.getFund(),current.getAmount(), current)){
                    deposit(*client2, current.getSecondFund(), current.getAmount(), current);
                }else{
                    cerr<<"Error: Cannot transfer $"<<current.getAmount()<<" from account "<<current.getID()<< " fund " << client->getFund(current.getFund())<<" to account "<<current.getSecondID()<< " fund "<<client2->getFund(current.getSecondFund())<<endl;
                }
            }else{
                if(accounts_.Retrieve(current.getID(), client) == false){
                    cerr<<"Error: Account: "<< current.getID()<< " not found"<<endl;
                }else{
                    cerr<<"Error: Account: "<< current.getSecondID()<< " not found"<<endl;
                }
                }
            }else if(current.getTransactionType() == 'A'){
            Account *client;
            if(accounts_.Retrieve(current.getID(), client)){
                printHistory(*client);
            }else{
                cerr<<"Error: Account: " << current.getID()<<" not found"<<endl;
            }
        }else if(current.getTransactionType() == 'F'){
            Account *client;

            if(accounts_.Retrieve(current.getID(), client)){
                printFund(*client, current.getFund());
            }else{
                cerr<<"Error: Account: " << current.getID()<<" not found"<<endl;
            }
        }
        incoming_transactions.pop();
    }
    cout<<"Final Balances:"<<endl;
    cout<<accounts_<<endl;
}

bool bank::deposit(Account & client, const int fund_, const int amount_, transaction &current )
{   
    return(client.deposit(amount_, fund_, current));
}

