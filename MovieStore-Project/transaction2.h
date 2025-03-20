#ifndef transaction2_H
#define transaction2_H
#include <string>
#include <iostream> 
using namespace std;

// ---------------------------------------- Transaction ---------------------------------------------
// Description: Checks to find if a customer exsists using their ID
// Takes in int id
// Return customer pointer if found
// Returns Nullptr if not found
// --------------------------------------------------------------------------------------------------
class transaction{
    public:

    // ---------------------------------- Transaction Constructor ---------------------------------------
    // Description: transaction constructor for a move in the class of Drama of Comedy
    // Takes in Char movie_type, int for stock, string director, string title, and int date (year)
    // --------------------------------------------------------------------------------------------------
    transaction(char movie_type, int stock, string director, string title, int date);

    // ---------------------------------- Transaction Constructor ---------------------------------------
    // Description: transaction constructor for a move in the class of Classic
    // Takes in Char movie_type, int for stock, string director, string title, string major actor, 
    // int month, and iint year
    // --------------------------------------------------------------------------------------------------
    transaction(char movie_type, int stock, string director, string title, string major_actor, int date_month, int date_year);

    // ---------------------------------- Transaction Constructor ---------------------------------------
    // Description: transaction constructor for a borrow or return for Comedy
    // Takes in char t for command type, int user id, char media type, char movie type, string title, 
    // and int year. 
    // --------------------------------------------------------------------------------------------------
    transaction(char t, int user_id, char media_type, char movie_type, string title, int year);

    // ---------------------------------- Transaction Constructor ---------------------------------------
    // Description: transaction constructor for a borrow or return for Drama
    // Takes in char t for command type, int user id, char media type, char movie type, string director, 
    // and string title
    // --------------------------------------------------------------------------------------------------
    transaction(char t, int user_id, char media_type, char movie_type, string dreictor, string title);

    // ---------------------------------- Transaction Constructor ---------------------------------------
    // Description: transaction constructor for a borrow or return for Classic
    // Takes in char t for command type, int user id, char media type, int month, int year, and string major actor 
    // --------------------------------------------------------------------------------------------------
    transaction(char t, int user_id, char media_type, char movie_type, int month, int year, string majoractor);

    // -------------------------------- Transaction get Transaction Type --------------------------------
    // Description: returns the transaction type char 
    // Returns Char
    // --------------------------------------------------------------------------------------------------
    char getTransactionType()const;

    // -------------------------------- Transaction get Movie Type --------------------------------------
    // Description: returns the movie type char 
    // Returns Char
    // --------------------------------------------------------------------------------------------------
    char getMovieType()const;

    // -------------------------------- Transaction get Media Type --------------------------------------
    // Description: returns the media type char 
    // Returns Char
    // --------------------------------------------------------------------------------------------------
    char getMediaType()const;

    // -------------------------------- Transaction get Stock -------------------------------------------
    // Description: returns the current stock of the transaction
    // Returns int 
    // --------------------------------------------------------------------------------------------------
    int getStock()const;

    // -------------------------------- Transaction get Director ----------------------------------------
    // Description: returns the director of the movie invloved in the transaction
    // Returns string
    // --------------------------------------------------------------------------------------------------
    string getDirector()const;

    // -------------------------------- Transaction get Title -------------------------------------------
    // Description: returns the Title of the movie involved
    // Returns string
    // --------------------------------------------------------------------------------------------------
    string getTtitle()const;

    // -------------------------------- Transaction get Major Actor -------------------------------------
    // Description: returns the Major actor of the transaction involved
    // Returns string
    // --------------------------------------------------------------------------------------------------
    string getMajorActor()const;

    // -------------------------------- Transaction get Month -------------------------------------------
    // Description: returns the month of the movie's date involved in the transaction
    // Returns int
    // --------------------------------------------------------------------------------------------------
    int getMonth()const;

    // -------------------------------- Transaction get Year --------------------------------------------
    // Description: returns the year of the movie's date involved in the transaction
    // Returns int
    // --------------------------------------------------------------------------------------------------
    int getYear()const;

    // -------------------------------- Transaction get Id ----------------------------------------------
    // Description: returns the Id of the customer involved in the transaction
    // Returns int
    // --------------------------------------------------------------------------------------------------
    int getID()const;

    // -------------------------------- Transaction add Title --------------------------------------------
    // Description: adds a movie title to a transaction. For instance if a command wants to borrow a movie
    // and doesnt have a title, we can add the title to the transaction to make sure it is accurate
    // --------------------------------------------------------------------------------------------------
    void addTitle(string title);

    // -------------------------------- Transaction add Director ----------------------------------------
    // Description: adds a movie director to a transaction. For instance if a command wants to borrow a movie
    // and doesnt have a director, we can add the director to the transaction to make sure it is accurate
    // --------------------------------------------------------------------------------------------------
    void addDirector(string director);

    // -------------------------------- Transaction OStream overload ------------------------------------
    // Description: Creates an OStream for the transaction class
    // Returns stream
    // --------------------------------------------------------------------------------------------------
    friend ostream& operator<<(ostream& stream, const transaction& transaction);

    private:

    // -------------------------------- Transaction Set Transaction Type --------------------------------
    // Description: Given a char representation of the transacton type. Returns the string representation 
    // Returns string
    // --------------------------------------------------------------------------------------------------
    string setTransactionType(char t);
    
    char t_type_=' ';
    int user_id_ =0;
    char media_type_=' ';
    char movie_type_=' ';
    int stock_=0;
    string director_="";
    string title_;
    string major_actor_="";
    int month_=0;
    int year_=0;

};
#endif