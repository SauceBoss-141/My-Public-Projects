#ifndef drama_H
#define drama_H
#include <string>
#include "movie.h"
#include "transaction2.h"
using namespace std;

// -------------------------------- Drama Class  -------------------------------------------------
// Description: Movie class is used to encapsulate a Drama Movie object
// Can be compared to other Drama movies 
// Child class of the movie class
// Can be printed out
// -----------------------------------------------------------------------------------------------
class Drama : public Movie{

    public:

	// -------------------------------- Drama Constructor  -------------------------------------------
    // Description: Regular construcotr for the Drama movie class. 
    // Takes in transaction object t
    // Sets data feilds
    // Object assumes data inputed is proper and correct
    // -----------------------------------------------------------------------------------------------
	Drama(transaction t);

	// -------------------------------- Drama operator overloads  --------------------------------------
    // Description: Used to compare a movie to another movie 
    // Returns a bool
    // Overloaded operators include >, <, >=, <=, ==, !=
    // Compared by director then title
    // -------------------------------------------------------------------------------------------------
    bool operator<(const Movie &other) const override;
	bool operator<=(const Movie &other) const override;
	bool operator>=(const Movie &other) const override;
	bool operator>(const Movie &other) const override;
	bool operator==(const Movie &other) const override;
	bool operator!=(const Movie &other) const override;

    private:
	
};
#endif