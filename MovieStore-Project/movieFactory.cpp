#include "movieFactory.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
using namespace std;

Movie* MovieFactory::createMovie(transaction t){
    
    //Classic Movie
    if(t.getMovieType()== 'C'){

        return  new Classic(t);
    }else if(t.getMovieType() == 'F'){
        //Comedy
        return new Comedy(t);
    }else if(t.getMovieType()== 'D'){
        return new Drama(t);
    }
    return nullptr;
}

