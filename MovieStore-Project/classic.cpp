#include "classic.h"

using namespace std;

Classic::Classic(transaction t) : Movie(t){
    major_actor_.push_back( t.getMajorActor());
    num_actors = 1;
    month_= t.getMonth();
}

int Classic::getMonth()const
{
    return month_;
}

string Classic::getMajorActor(int actor)const
{
    return major_actor_[actor];
}

ostream &operator<<(ostream &stream, const Classic &movie)
{
    string myString;

    
    myString = string(1, movie.getMovieType());
    stream<<"Movie type: "<< myString<< " Stock: "<< movie.getStock()<<" Title:"+movie.getTittle()<<".  Major Actor:";
    for(int i = 0; i <movie.major_actor_.size();i++){
        stream<< " "<<movie.getMajorActor(i);
    }
    stream<<".  Date Released: "<<movie.getMonth()<<" "<<movie.getYear();

    return stream;
}

bool Classic::operator<(const Classic &other) const
{   
    if(this->getYear()<other.getYear()){
        return true;
    }else if( this->getYear()==other.getYear()&& month_<other.getMonth()){
        return true;
    }else if(this->getYear()==other.getYear()&& month_==other.getMonth()){
        if(num_actors!=other.getNumActors()){
            return false;
        }
        for(int i = 0; i <major_actor_.size();i++){
            if (major_actor_[i] < other.getMajorActor(i)) {
                return false;
            }
        }
    }
    return false;
}

bool Classic::operator<=(const Classic &other) const
{
    return (*this< other )||(*this == other);
}

bool Classic::operator>(const Classic &other) const
{
    if(this->getYear()>other.getYear()){
        return true;
    }else if( this->getYear()==other.getYear()&& month_>other.getMonth()){
        return true;
    }else if(this->getYear()==other.getYear()&& month_==other.getMonth()){
        if(num_actors!=other.getNumActors()){
            return false;
        }
        for(int i = 0; i <major_actor_.size();i++){
            
            if (major_actor_[i] > other.getMajorActor(i)) {
                return false;
            }
        }
    }
    return false;
}

bool Classic::operator>=(const Classic &other) const
{
    return (*this> other )||(*this == other);
}

bool Classic::operator==(const Classic &other) const
{   
    // Check if the number of actors is different
    if (num_actors != other.getNumActors()) {
        return false;
    }

    // Check month and year
    if (this->getMonth() != other.getMonth()) {
        return false;
    }

    // Compare all major actors
    for (size_t i = 0; i < major_actor_.size(); i++) {
        if (major_actor_[i] != other.getMajorActor(i)) {
            return false;
        }
    }

    return true;
}

bool Classic::operator!=(const Classic &other) const
{
    return !(*this == other);
}

void Classic::addActor(string actor)
{
    major_actor_.push_back(actor);
    num_actors++;
}

int Classic::getNumActors() const
{
    return num_actors;
}

bool Classic::hasActor(const string &actor) const
{   
    for (const string& stored_actor : major_actor_) {
        if (stored_actor == actor) {  // Check if actor exists in list
            return true;
        }
    }
return false;
}

