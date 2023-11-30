#include "reader.h"

Reader::Reader(std::string f_name, std::string l_name)
{
    first_name=f_name;
    last_name=l_name;
    count_of_books=0;
}  

void Reader::get_name()
{
    std::cout<<"Name: "<<first_name<< " " <<last_name<<std::endl;
}

Reader::~Reader()
{

}