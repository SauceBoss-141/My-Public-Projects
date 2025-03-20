#include "drama.h"

Drama::Drama(transaction t): Movie(t){}

bool Drama::operator<(const Movie &other) const
{   
    if(this->getDirector()<other.getDirector()){
        return true;
    }else{
        if(this->getDirector()==other.getDirector() && this->getTittle()<other.getTittle()){
            return true;
        }
    }
    return false;
}

bool Drama::operator<=(const Movie &other) const
{
    return (*this< other )||(*this == other);
}

bool Drama::operator>=(const Movie &other) const
{
    return (*this> other )||(*this == other);
}

bool Drama::operator>(const Movie &other) const
{
    if(this->getDirector()>other.getDirector()){
        return true;
    }else{
        if(this->getDirector()==other.getDirector() && this->getTittle()>other.getTittle()){
            return true;
        }
    }
    return false;
}

bool Drama::operator==(const Movie &other) const
{
    return (this->getDirector()==other.getDirector()&&this->getTittle()==other.getTittle());
}

bool Drama::operator!=(const Movie &other) const
{
    return !(*this==other);
}
