#ifndef classic_H
#define classic_H
#include <string>
#include "movie.h"
#include <vector>
#include "transaction2.h"
using namespace std;

// -------------------------------- Classic Class  -------------------------------------------------
// Description: Movie class is used to encapsulate a Classic Movie object
// Can be compared to other Classic movies 
// Child class of the movie class
// Can be printed out
// ------------------------------------------------------------------------------------------------
class Classic: public Movie{

    public:

    // -------------------------------- CLassic Constructor  -----------------------------------------
    // Description: Regular construcotr for the CLassic movie class. 
    // Takes in transaction object t
    // Sets data feilds
    // Object assumes data inputed is proper and correct
    // -----------------------------------------------------------------------------------------------
    Classic(transaction t);

    // -------------------------------- CLassic get Month  -------------------------------------------
    // Description: returns an the movies month as an int
    // Returns int
    // -----------------------------------------------------------------------------------------------
    int getMonth()const;

    // -------------------------------- CLassic get Num Actors  --------------------------------------
    // Description: Returns the number of major actors the movie has
    // Returns int 
    // -----------------------------------------------------------------------------------------------
    int getNumActors()const;

    // -------------------------------- CLassic has Actor  -----------------------------------------
    // Description: searches movies actor list for a target actor
    // Takes in a string ref
    // Returns bool
    // -----------------------------------------------------------------------------------------------
    bool hasActor(const string &actor)const;

    // -------------------------------- CLassic Add actor  -------------------------------------------
    // Description: Adds an actor to the movies major actor list
    // Takes in string actor
    // -----------------------------------------------------------------------------------------------
    void addActor(string actor);

    // -------------------------------- Classic get Major Actor ---------------------------------------
    // Description: returns a major actor from the list
    // Takes in an int for the index
    // Returns string
    // ------------------------------------------------------------------------------------------------
    string getMajorActor(int id)const;

    // -------------------------------- Classic operator overloads  -----------------------------------
    // Description: Used to compare a movie to another movie 
    // Returns a bool
    // Overloaded operators include >, <, >=, <=, ==, !=
    // Compared by year, month, and major actor
    // -------------------------------------------------------------------------------------------------
    bool operator<(const Classic &other) const;
	bool operator<=(const Classic &other) const;
	bool operator>=(const Classic &other) const;
	bool operator>(const Classic &other) const;
	bool operator==(const Classic &other) const;
	bool operator!=(const Classic &other) const;

    // -------------------------------- Classic OStream overload ----------------------------------------
    // Description: Creates an OStream for the Classi class
    // Returns stream
    // --------------------------------------------------------------------------------------------------
    friend ostream& operator<<(ostream& stream, const Classic& mvoie);
    
    private:
    int month_=1;
    int num_actors =0;
    vector<string> major_actor_=vector<string>();

};
#endif