#ifndef vendor_H
#define vendor_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "movie.h"
#include "movieFactory.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "customer.h"
#include "transaction2.h"
#include "avltree.h"
#include <memory>
using namespace std;

// ---------------------------------------------- Vendor --------------------------------------------
// Description: Reads an input file
// Proceses commands from file
// Validates data
// Stores a map of customers and 3 AVL tree's of movies
// --------------------------------------------------------------------------------------------------
class vendor{

    public:

    // ------------------------------------ Vendor Read File----------------------------------------------
    // Description: Takes in name of the file as a string
    // If command is a new customer it will call the create custoem rmethod
    // If it is any other command it will send the line from the file to the procees command function
    // ---------------------------------------------------------------------------------------------------
    void readFile(string infile);

    // ------------------------------------ Vendor Process Command----------------------------------------
    // Description: Takes in a string line meant to be a command and its atrributes
    // Commands can be of the form: 'I' 'H' 'B' 'R' 'C' 'F' 'D'
    // if the command deviates from any of these, an error will be thrown and the function ends.
    // Depending on the command it will call the requiered method.
    // This function only input validates the input data for the movie for a user borrowing or returing.
    // The other functions do their own validations of input. If validation fails, errors will be thrown.
    // For instance the creation of a movie. Is placed isnide of an 'if' statment, if not valid move is created
    // and error is thrown.
    // ---------------------------------------------------------------------------------------------------
    void processCommand(string line);

    // ---------------------------------- Vendor Print User Base------------------------------------------
    // Description: This was a method I used to validate my program was working. 
    // However it will neatly display the ID and names of our customers. (For managerial purposues ) :)
    // ---------------------------------------------------------------------------------------------------
    void printUserBase();
    
    private:

    // ---------------------------------- Vendor Create Account-------------------------------------------
    // Description: Takes in an int Id, string first name, string last name
    // Will check to make sure no customer exsists using that ID
    // If no customer exsists it will create a customer object and store it in our hash table(map)
    //Reurns boolean if succesful or not. 
    // ---------------------------------------------------------------------------------------------------
    bool createAccount(int id, string first_name, string last_name);

    // ---------------------------------- Vendor Print inventory------------------------------------------
    // Description: Method used to display our current inventory. 
    // In the requiered order: Comedy, Drama, Classic
    // ---------------------------------------------------------------------------------------------------
    void printInventory();

    // ---------------------------------- Vendor Print User history---------------------------------------
    // Description: Method used to display users account history
    // Takes in an int id and returns boolean if succsesful or not
    // Will check to see if customer exsists first. If so, prints that users stored transaction list. 
    // ---------------------------------------------------------------------------------------------------
    bool printUserHistory(int id);

    // ---------------------------------- Vendor Return Movie--------------------------------------------
    // Description: Processes return movie commands. Takes in transaction object  
    // Checks for valid customer and movie.
    // If all is valid, it attempts to borrow movie. If successful adds transaction to users list 
    // Returns bool
    // --------------------------------------------------------------------------------------------------
    bool returnMovie(transaction t);

    // ---------------------------------- Vendor Borrow Movie--------------------------------------------
    // Description: Processes borrow movie commands. Takes in transaction object  
    // Checks for valid customer and movie.
    // If all is valid, it attempts to borrow movie. If successful adds transaction to users list 
    // Returns bool
    // --------------------------------------------------------------------------------------------------
    bool borrowMovie(transaction t);

    // ---------------------------------- Vendor Create Movie--------------------------------------------
    // Description: Creates a movie. Takes in a transaction object 
    // Validates movie info. Use's movie facotry to create movie objetcs and stores them in appropriate AVL
    // tree.
    // --------------------------------------------------------------------------------------------------
    bool createMovie(transaction t);

    // ------------------------------ Vendor Classic Movie exsists---------------------------------------
    // Description: Checks to see if a classic movie exsists. If it does, we must increase the count
    // And add the major actor when creating the movie
    // Helper method. Returns bool 
    // ---------------------------------------------------------------------------------------------------
    bool classicMovieExsists(transaction t);

    // ---------------------------------- Vendor Find Customer-------------------------------------------
    // Description: Checks to find if a customer exsists using their ID
    // Takes in int id
    // Return customer pointer if found
    // Returns Nullptr if not found
    // --------------------------------------------------------------------------------------------------
    Customer* findCustomer(int id);

    // ---------------------------------- Vendor Find Movie---------------------------------------------
    // Description: Checks to find if a movie using transaction details. 
    // Takes in int id
    // Return Movie pointer if found
    // Returns Nullptr if not found
    // --------------------------------------------------------------------------------------------------
    Movie* findMovie(transaction t);

    //Requiered hash map for the project.
    unordered_map<int,  Customer> customer_data_;

    //My Movies storages using an AVL tree. Curtousey of my desgin partner Aidan.
    AVLTree<Drama*> drama_storage_;
    AVLTree<Comedy*> comedy_storage_;
    AVLTree<Classic*> classic_storage_;
    
};
#endif