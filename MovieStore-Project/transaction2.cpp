#include <string>
#include <iostream> 
#include "transaction2.h"
using namespace std;

transaction::transaction( char movie_type, int stock, string director, string title, int date)
{
    
    movie_type_ = movie_type;
    stock_= stock;
    director_ = director;
    title_ = title;
    year_= date;
}

transaction::transaction(char movie_type, int stock, string director, string title, string major_actor, int date_month, int date_year)
{
   
    movie_type_ = movie_type;
    stock_= stock;
    director_ = director;
    title_ = title;
    major_actor_ = major_actor;
    month_ = date_month;
    year_ = date_year;
}

transaction::transaction(char t, int user_id, char media_type, char movie_type, string title, int year)
{
    t_type_ = t;
    movie_type_ = movie_type;
    user_id_ = user_id;
    title_ = title;
    year_ = year;
}


transaction::transaction(char t, int user_id, char media_type, char movie_type, string dreictor, string title)
{
    t_type_ = t;
    movie_type_ = movie_type;
    user_id_ = user_id;
    title_ = title;
    director_ = dreictor;
}

transaction::transaction(char t, int user_id, char media_type, char movie_type, int month, int year, string majoractor)
{
    t_type_ = t;
    movie_type_ = movie_type;
    user_id_ = user_id;
    month_ = month;
    year_= year;
    major_actor_ = majoractor;
}


char transaction::getTransactionType()const
{
    return t_type_;
}
string transaction::setTransactionType(char t)
{
    switch (t) {
        case 'B': return "Borrow";
        case 'R': return "Return";
        case 'I': return "Inventory";
        case 'H': return "Histroy";
        default:  return "Adding/Removing Movie to storage";
    }
}

char transaction::getMovieType()const
{
    return movie_type_;
}

char transaction::getMediaType()const
{
    return media_type_;
}
    
int transaction::getStock()const
{
    return stock_;
}

int transaction::getID()const
{
    return user_id_;
}

string transaction::getDirector()const
{
    return director_;
}
string transaction::getTtitle()const
{
    return title_;
}
string transaction::getMajorActor()const
{
    return major_actor_;
}
    
int transaction::getMonth()const
{
    return month_;
}

int transaction::getYear()const
{
    return year_;
}

void transaction::addDirector(string director)
{
    director_=director;
}

void transaction::addTitle(string title)
{
    title_=title;
}

ostream& operator<<(ostream& stream, const transaction& transaction)
{
        if(transaction.getMovieType()!='C'){
            stream<<"Transaction: "<<transaction.getTransactionType()<<". Movie type: "<< transaction.getMovieType()<< ". Movie: "<<transaction.getTtitle()
            << ". Directed by: "<<transaction.getDirector() ; 
        }else{
            stream<<"Transaction: "<<transaction.getTransactionType()<<". Movie type: "<< transaction.getMovieType()<< ". Movie: "<<transaction.getTtitle()<<
        ". Major Actor: "<<transaction.getMajorActor() ;
        }
        
        return stream;
    
}


