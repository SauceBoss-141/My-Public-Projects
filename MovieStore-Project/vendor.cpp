#include "vendor.h"
#include "movie.h"
#include "movieFactory.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "customer.h"
#include "transaction2.h"
#include "avltree.h"


void vendor::readFile(string infile)
{

    
    ifstream file(infile);
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    while (getline(file, line)) {
        if (line.empty()) continue;
        

        // Check if the first character is a digit (Customer ID)
        if (isdigit(line[0])) {
            stringstream ss(line);
            int id;
            string last, first;
            ss >> id >> last >> first;

            // Validate and create the customer
            if (id > 0 && !last.empty() && !first.empty()) {
                createAccount(id, first, last);
            } else {
                cerr << "Invalid customer data: " << line << endl;
            }
            continue; // Move to the next line
        }

        // Otherwise, process it as a command
        processCommand(line);
    }

}

void vendor::processCommand(string line)
{   
     if(line[0]=='C'){
        stringstream ss(line);
        string temp, command, director, title, actor;
        int stock, month, year;
        getline(ss, command, ',');
        char type= command[0];
        getline(ss, temp, ',');
        stock = stoi(temp);
        getline(ss, director, ',');
        getline(ss, title, ',');

        string firstName, lastName;
        ss >> firstName >> lastName >> month >> year;
        actor = firstName + " " + lastName;

        transaction t(type, stock, director, title, actor, month, year);
        if (!createMovie(t)) {
            cerr << "Failed to create Classic movie." << endl;
        }
    }else if(line[0]=='F'|| line[0]=='D'){

        stringstream ss(line);
        string temp, command, director, title;
        int stock, year;
        char type = line[0];

        getline(ss, command, ',');  
        getline(ss, temp, ',');
        stock = stoi(temp);  

        getline(ss, director, ',');
        getline(ss, title, ',');
        ss >> year; 

        transaction t(type, stock, director, title, year);
    if (!createMovie(t)) {
        cerr << "Failed to create movie." << endl;
    }

    }else if(line[0]=='I'){
        printInventory();
    }else if(line[0]=='H'){
        stringstream ss(line);
        char temp;
        int id;
        ss>>temp>>id;
        printUserHistory(id);
        return;
    }else if(line[0]=='B'){
        stringstream ss(line);
        char command_type;
        ss >> command_type;
        int id;
        ss>>id;
        char temp;
        ss>>temp;
        if(temp != 'D'){
            cerr<<"Invalid Media type."<<endl;
            return;
        }
        char movie_type;
        ss >> movie_type;


        if (movie_type == 'C') {
            // Classic Movie
            int month, year;
            string actor;
            
            ss >> month >> year;
            getline(ss, actor);  // Read the actor's name
            
            if (month < 1 || month > 12 || year <= 0 || actor.empty()) {
                cerr << "Invalid Classic movie data!" << endl;
                return;
            }
            transaction t(command_type, id, 'D', movie_type, month, year, actor);
            
            borrowMovie(t);

        } else if ( movie_type == 'F') {
            // Drama or Comedy
            string title;
            int year;
            getline(ss, title, ',');  // Read title until the first comma
            ss >> year;
            
            if (title.empty() ||  year <= 0) {
                cerr << "Invalid movie data!" << endl;
                return;
            }
            // Drama
            transaction t(command_type, id, 'D', movie_type, title, year );
            borrowMovie(t);
               
            
        }else if(movie_type =='D'){
            // Drama or Comedy
            string title, director;
            
            getline(ss, director, ',');
            getline(ss, title,',');  // Read title until the first comma
            
            
            if (title.empty() || director.empty()) {
                cerr << "Invalid movie data!" << endl;
                return;
            }
            // Drama
            transaction t(command_type, id, 'D', movie_type, director, title );
            borrowMovie(t);

        }else{
            cerr<<"Invalid movie type"<<endl;
        }
        
    }else if(line[0]=='R'){
        stringstream ss(line);
        char command_type;
        ss >> command_type;
        int id;
        ss>>id;
        char temp;
        ss>>temp;
        if(temp != 'D'){
            cerr<<"Invalid Media type."<<endl;
            return;
        }
        char movie_type;
        ss >> movie_type;


        if (movie_type == 'C') {
            // Classic Movie
            int month, year;
            string actor;
            ss >> month >> year;
            getline(ss, actor);  // Read the actor's name
            
            if (month < 1 || month > 12 || year <= 0 || actor.empty()) {
                cerr << "Invalid Classic movie data!" << endl;
                return;
            }
            transaction t(command_type, id, 'D', movie_type, month, year, actor);

            returnMovie(t);

        } else if ( movie_type == 'F') {
            // Drama or Comedy
            string title;
            int year;
            getline(ss, title, ',');  // Read title until the first comma
            ss >> year;
            
            if (title.empty() ||  year <= 0) {
                cerr << "Invalid movie data!" << endl;
                return;
            }
            // Drama
            transaction t(command_type, id, 'D', movie_type, title, year );
            
            returnMovie(t);
               
            
        }else if(movie_type =='D'){
            // Drama or Comedy
            string title, director;
            
            getline(ss, director, ',');
            getline(ss, title,',');  // Read title until the first comma
            
            
            if (title.empty() || director.empty()) {
                cerr << "Invalid movie data!" << endl;
                return;
            }
            // Drama
            transaction t(command_type, id, 'D', movie_type, director, title );
            returnMovie(t);

        }
        else{
            cerr<<"Invalid movie type"<<endl;
        }

    }else{
        cerr<<"Invalid command."<<endl;
    }
}

bool vendor::createAccount(int id, string first_name, string last_name)
{   
    if(customer_data_.find(id)!= customer_data_.end()){
        cerr<<"Customer ID already in use."<<endl;
        return false;
    }else{
        customer_data_.emplace(id, Customer(id, last_name, first_name));
        return true;

    }
    
}

void vendor::printInventory()
{
    if(!comedy_storage_.isEmpty()){
        cout<<""<<endl;
        cout<<"----Comedy storage:----"<<endl;
        for (auto i : comedy_storage_)
        {
            
            cout << i<< endl;
        }
        
    }
    
    cout<<" "<<endl;
    if(!drama_storage_.isEmpty()){
        cout<<"----Drama storage:----"<<endl;
        cout<<""<<endl;
        for (auto i : drama_storage_)
        {
            
            cout << i << endl;
        }
        
    }
    cout<<" "<<endl;
    
    if(!classic_storage_.isEmpty()){
        cout<<""<<endl;
        cout<<"----Classic storage:----"<<endl;
        for (auto i : classic_storage_)
        {
            
            cout << i << endl;
        }
        
    }
    cout<<" "<<endl;
    
}

bool vendor::printUserHistory(int id)
{   
    Customer *cus = findCustomer(id);
    if(cus!=nullptr){
        cus->printHistory();
        cout<<""<<endl;
        return true;
    }else{
        cerr<<"Customer not found";
        return false;
    }
}

bool vendor::createMovie(transaction t)
{   
    
    if (t.getStock() > 0) {
        Movie* mov = MovieFactory::createMovie(t);  // Use unique_ptr

        if (!mov){
            
            return false; 
        }  // Check if creation failed

        if (t.getMovieType() == 'C') { // Classic
            if (t.getMonth() < 1 || t.getMonth() > 12 || t.getYear() <= 0 ||
                t.getMajorActor().empty() || t.getTtitle().empty() || t.getDirector().empty()) {
                return false;
            }
            
            if(classicMovieExsists(t)){
                for (auto i : classic_storage_){   
                    if(i.getMonth() == t.getMonth() && i.getYear() == t.getYear()&& i.getDirector()==t.getDirector()&&i.getTittle()==t.getTtitle()){
                        Classic*  re_classic = classic_storage_.retrieve(i);
                        re_classic->addActor(t.getMajorActor());
                        for(int i =0; i <t.getStock();i++){
                            re_classic->incrimentStock();
                        }
                    }
                }
            }
            Classic* movie = dynamic_cast<Classic*>(mov);
            if (movie) {
                classic_storage_.insert(move(movie)); // Move ownership
                return true;
            }
        } else { // Drama or Comedy
            if (t.getYear() <= 0 || t.getTtitle().empty() || t.getDirector().empty()) {
                return false;
            }

            if (t.getMovieType() == 'D') { // Drama
                Drama* movie = dynamic_cast<Drama*>(mov);
                if (movie) {
                    drama_storage_.insert(move(movie));
                    return true;
                }
            } else if (t.getMovieType() == 'F') { // Comedy
                Comedy* movie = dynamic_cast<Comedy*>(mov);
                if (movie) {
                    comedy_storage_.insert(move(movie));
                    return true;
                }
            }
        }
        
    }
    return false;
    
}

Customer *vendor::findCustomer(int id)
{
    if(customer_data_.find(id)== customer_data_.end()){
        
        return nullptr;
    }else{
        Customer* customer = &(*customer_data_.find(id)).second;
        
        return customer;
    }
}

Movie *vendor::findMovie(transaction t)
{
    if(t.getMovieType()=='C'){//Classic
       string temp_string = t.getMajorActor();
        for (auto i : classic_storage_)
        {   
            //cout<<i.hasActor(temp_string)<<endl;
            if(i.getMonth() == t.getMonth() && i.getYear() == t.getYear() &&!i.hasActor(temp_string)){
                
                Classic*  re_classic = classic_storage_.retrieve(i);
                return re_classic;
            }
        }
    }else if(t.getMovieType()=='D'){//Drama

        for (auto i : drama_storage_)
        {
            if(i.getDirector()==t.getDirector()&& i.getTittle() == t.getTtitle()){
                
                Drama*  re_drama = drama_storage_.retrieve(i);
                return re_drama;
            }
        }
    }else if( t.getMovieType()=='F'){//Comedy
        for (auto i : comedy_storage_)
        {
            if( i.getTittle() == t.getTtitle()&&i.getYear()==t.getYear()){
                
                Comedy*  re_comedy = comedy_storage_.retrieve(i);
                return re_comedy;
            }
        }
    }
        return nullptr;
    
}

bool vendor::borrowMovie(transaction t)
{   
    Movie * mov = findMovie(t);
    Customer * custom = findCustomer(t.getID());
    if(custom==nullptr){
        cerr<<"Cannot find customer"<<endl;
        return false;
    }
    if(mov == nullptr){
        cerr<<"Cannot find movie"<<endl;
        return false;
    }else{
        if(mov->decrementStock()){
            if(t.getMovieType()=='C'){
                t.addTitle(mov->getTittle());
            }
            if(t.getMovieType()=='F'){
                t.addDirector(mov->getDirector());
            }
            custom->addTransaction(t);
            return true;
        }else{
            cerr<<"Movie: "<< mov->getTittle()<<" does not have enough stock."<<endl;
            return false;
        }
    }
    
    return false;
}

bool vendor::returnMovie(transaction t)
{
    Movie * mov = findMovie(t);
    Customer * custom = findCustomer(t.getID());
    if(custom==nullptr){
        cerr<<"Cannot find customer"<<endl;
        return false;
    }
    if(mov == nullptr){
        cerr<<"Cannot find movie"<<endl;
        return false;
    }else{
        if(mov->incrimentStock()){
            if(t.getMovieType()=='C'){
                t.addTitle(mov->getTittle());
            }
            if(t.getMovieType()=='F'){
                t.addDirector(mov->getDirector());
            }
            custom->addTransaction(t);
            return true;
        }
    }
    
    return false;
}


void vendor::printUserBase()
{
    cout << "Customer List:" << endl;

    for (const auto& pair : customer_data_) {
        int id = pair.first;
       const  Customer* customer = &pair.second;

        if (customer) { // Ensure the pointer is valid
            cout << "ID: " << id << ", Name: " << customer->getFirstName()
                 << " " << customer->getLastName() << endl;
        }
    }
}

bool vendor::classicMovieExsists(transaction t)
{
    for (auto i : classic_storage_)
    {   
        if(i.getMonth() == t.getMonth() && i.getYear() == t.getYear()&& i.getDirector()==t.getDirector()&&i.getTittle()==t.getTtitle()){
            
            
            return true;
        }
    }
    return true;
}
