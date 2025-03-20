#include "comedy.h"

Comedy::Comedy(transaction t): Movie(t){}

bool Comedy::operator<(const Comedy &other) const
{   if(this->getTittle()<other.getTittle()){
        return true;
    }
    if(this->getTittle()==other.getTittle()){
        if(this->getYear()<other.getYear()){
            return true;
        }
    }
    return false;
}

bool Comedy::operator<=(const Comedy &other) const
{
    return (*this< other )||(*this == other);
}

bool Comedy::operator!=(const Comedy &other) const
{
    return !(*this== other);
}

bool Comedy::operator>=(const Comedy &other) const
{
    return (*this> other )||(*this == other);
}

bool Comedy::operator>(const Comedy &other) const
{
    if(this->getTittle()>other.getTittle()){
        return true;
    }
    if(this->getTittle()==other.getTittle()){
        if(this->getYear()>other.getYear()){
            return true;
        }
    }
    return false;
}

bool Comedy::operator==(const Comedy &other) const
{
    return (this->getTittle()== other.getTittle() && this->getYear() == other.getYear());
}

