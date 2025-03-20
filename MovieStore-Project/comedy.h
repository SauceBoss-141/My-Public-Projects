#ifndef comedy_H
#define comedy_H
#include <string>
#include "movie.h"
#include "transaction2.h"
using namespace std;

// -------------------------------- Comedy Class  -------------------------------------------------
// Description: Movie class is used to encapsulate a Comedy Movie object
// Can be compared to other Drama movies 
// Child class of the movie class
// Can be printed out
// ------------------------------------------------------------------------------------------------
class Comedy: public Movie{
    public:

	// -------------------------------- Comedy Constructor  ------------------------------------------
    // Description: Regular construcotr for the Comedy movie class. 
    // Takes in transaction object t
    // Sets data feilds
    // Object assumes data inputed is proper and correct
    // -----------------------------------------------------------------------------------------------
	Comedy(transaction t);

	// -------------------------------- Comedy operator overloads  ------------------------------------
    // Description: Used to compare a movie to another movie 
    // Returns a bool
    // Overloaded operators include >, <, >=, <=, ==, !=
    // Compared by title then year
    // -------------------------------------------------------------------------------------------------
    bool operator<(const Comedy &other) const;
	bool operator<=(const Comedy &other) const;
	bool operator>=(const Comedy &other) const;
	bool operator>(const Comedy &other) const;
	bool operator==(const Comedy &other) const;
	bool operator!=(const Comedy &other) const;

    private:

};
#endif