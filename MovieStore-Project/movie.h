#ifndef movie_H
#define movie_H
#include <string>
#include "transaction2.h"
using namespace std;

// ----------------------------------------- Movie Class  -------------------------------------------
// Description: Move class is used to encapsulate a movie object
// Can be compared to other movies 
// Can be printed out
// Can incirment and decrment its stock
// --------------------------------------------------------------------------------------------------
class Movie{

    public:
    
    // -------------------------------- Movie Constructor  -------------------------------------------
    // Description: Default constrcutor for the movie. 
    // -----------------------------------------------------------------------------------------------
    Movie();

    // -------------------------------- Movie Constructor  -------------------------------------------
    // Description: Regular construcotr for the movie class. 
    // Takes in transaction object t
    // Sets data feilds
    // Object assumes data inputed is proper and correct
    // -----------------------------------------------------------------------------------------------
    Movie(transaction t );

    // -------------------------------- Movie De-Constructor  ----------------------------------------
    // Description: Deconstructor, only needed to satify the complete class requeirment for another method
    // -----------------------------------------------------------------------------------------------
    virtual ~Movie();

    // -------------------------------- Movie Get stock  -----------------------------------------------
    // Description: returns an int that represents the movies current stock
    // -------------------------------------------------------------------------------------------------
    virtual int getStock()const;

    // -------------------------------- Movie Get Year  ------------------------------------------------
    // Description: returns an int that represents the movies year
    // -------------------------------------------------------------------------------------------------
    virtual int getYear()const;

    // -------------------------------- Movie Get Director  --------------------------------------------
    // Description: returns a string that represenst the movies directory
    // -------------------------------------------------------------------------------------------------
    virtual string getDirector()const;

    // -------------------------------- Movie Get Title  -----------------------------------------------
    // Description: returns a string that represents the movies title
    // -------------------------------------------------------------------------------------------------
    virtual string getTittle()const;

    // ------------------------------- Movie Get Movie Type --------------------------------------------
    // Description: returns a char that represnets the Movie type
    // -------------------------------------------------------------------------------------------------
    virtual char getMovieType()const;

    // -------------------------------- Movie Get Media Type  ------------------------------------------
    // Description: returns a char that represnets the Movie media type
    // -------------------------------------------------------------------------------------------------
    virtual char getMediaType()const;
   
    // -------------------------------- Movie Incriment stock  -----------------------------------------
    // Description: Used to add to the movies stock by 1
    // Returns a bool
    // -------------------------------------------------------------------------------------------------
    virtual  bool incrimentStock();

    // -------------------------------- Movie Decrement stock  -----------------------------------------
    // Description: Used to decrement the movies stock by 1 if it has the available stock
    // Returns a bool
    // -------------------------------------------------------------------------------------------------
    virtual  bool decrementStock();

    // -------------------------------- Movie operator overloads  --------------------------------------
    // Description: Used to compare a movie to another movie 
    // Returns a bool
    //  Overloaded operators include >, <, >=, <=, ==, !=
    // Compared by title, director, year
    // -------------------------------------------------------------------------------------------------
    virtual bool operator<(const Movie &other) const;
    virtual bool operator<=(const Movie &other) const;
    virtual bool operator>=(const Movie &other) const;
    virtual bool operator>(const Movie &other) const;
    virtual bool operator==(const Movie &other) const;
    virtual bool operator!=(const Movie &other) const;

    // -------------------------------- Movie OStream overload ------------------------------------------
    // Description: Creates an OStream for the Movie class
    // Returns stream
    // --------------------------------------------------------------------------------------------------
    friend ostream& operator<<(ostream& stream, const Movie& mvoie);
    
    private:
    char movie_type_='C';
    char media_type_='D' ;//Dvd or vieo streaming
    string title_="";
    int stock_=0;
    int year_made_=0;
    string director_=" ";
};
#endif