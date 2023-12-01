#include "reader.h"

Reader::Reader(std::string f_name, std::string l_name)
{
    first_name=f_name;
    last_name=l_name;
    book_lented=0;
}  

void Reader::get_name()
{
    std::cout<<"Name: "<<first_name<< " " <<last_name<<std::endl;
}

void Reader::output_red_books()
{
    for(int i=0;i<books_red.size();i++)
    {
        std::cout<<"Book "<<books_red[i]->book_name<<"\tAuthor: "<<books_red[i]->author_name<<std::endl;
    }
}

Reader::~Reader()
{

}