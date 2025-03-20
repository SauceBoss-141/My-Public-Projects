#include "movie.h"
#include <iostream>
using namespace std;

Movie::Movie()
{

}
Movie::Movie(transaction t){
    media_type_ = t.getMediaType();
    stock_ = t.getStock();
    director_ = t.getDirector();
    title_ = t.getTtitle();
    year_made_ = t.getYear();
    movie_type_ = t.getMovieType();
}

Movie::~Movie(){
    
}
string Movie::getDirector()const
{
    return director_;
}

string Movie::getTittle()const
{
    return title_;
}

int Movie::getStock()const
{
    return stock_;
}

int Movie::getYear()const
{
    return year_made_;
}
bool Movie::incrimentStock(){
    stock_++;
    return true;
}
bool Movie::decrementStock(){
    if(stock_>0){
        stock_--;
        return true;
    }else{
        return false;
    }
}

bool Movie::operator<(const Movie &other)const{
    if(title_<other.getTittle()){
        if(director_<other.getDirector()){
            if(year_made_<other.getYear()){
                return true;
            }
        }
    }
    return false;
}

bool Movie::operator<=(const Movie &other) const
{
    return (*this< other )||(*this == other);
}


bool Movie::operator==(const Movie &other) const
{   if(movie_type_ == other.getMovieType()){
        if(title_ == other.getTittle()){
            if(year_made_ == other.getYear()){
                if(director_ == other.getDirector()){
                    return true;
                }
            }
        }
    }
    return false;
}

ostream& operator<<(ostream& stream, const Movie& movie)
{   
    string myString;

    
    myString = string(1, movie.getMovieType());
    
        stream<<"Movie type: "<< myString<< " Stcok: "<< movie.getStock()<<" Director: "<< movie.getDirector()<< ".  Title:"+movie.getTittle()<<".  Date Released: "<<movie.getYear();
    
    

    return stream;
}

bool Movie::operator>=(const Movie &other) const
{
    return (*this> other )||(*this == other);
}

bool Movie::operator>(const Movie &other) const
{
    if(title_>other.getTittle()){
        if(director_>other.getDirector()){
            if(year_made_>other.getYear()){
                return true;
            }
        }
    }
    return false;
}

bool Movie::operator!=(const Movie &other) const
{
    return !(*this==other);
}

char Movie::getMovieType() const
{
    return movie_type_;
}

char Movie::getMediaType() const
{
    return media_type_;
}

