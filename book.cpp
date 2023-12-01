#include "book.h"

Book::Book()
{
    
}

Book::Book(std::string book, std::string author)
{
    book_name=book;
    author_name=author;
    returned_books=0;
    land=0;
}

void Book::land_book()
{
    
    std::cout<<"You have lented: "<<book_name<<"\tby "<<author_name<<std::endl;
    //int land=1;
    
}

void Book::return_book()
{
    
    std::cout<<"You have returned: "<<book_name<<"l\tby "<<author_name<<std::endl;
    int land=0;
    
}

void Book::output()
{
    std::string res;
    if(land)
        res="yes";
    else
        res="no";

    std::cout<<"\tBook: "<<book_name<<" by "<<author_name<<"\tLanded: "<<res<<std::endl;
}

Book::~Book()
{

}