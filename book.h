#pragma once
#include <iostream>


class Book
{
    public:
        std::string book_name;
        std::string author_name;
        int land;

        Book();
        Book(std::string book, std::string author);
        ~Book();
        void land_book();
        void return_book();
        void output();
    
};