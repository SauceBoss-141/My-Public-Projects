#ifndef movieFactory_H
#define movieFactory_H
#include <string>
#include "transaction2.h"
#include "movie.h"
#include <memory>
using namespace std;

// ---------------------------------------- Movie Factory -------------------------------------------
// Description: Factory pattern class
// Can create three different movie objects 
// Drama, Comedy, or Classic
// --------------------------------------------------------------------------------------------------
class MovieFactory{

    public:

    // ---------------------------------------- Movie Factory -------------------------------------------
    // Description: Factory pattern class
    // Can create three different movie objects 
    // Drama, Comedy, or Classic
    // --------------------------------------------------------------------------------------------------
    static Movie* createMovie(transaction t);//Will create the 3 types of movies
};
#endif