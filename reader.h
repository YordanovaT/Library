#pragma once
#include <iostream>
#include <string.h>
#include "book.h"
#include <vector>

class Reader{
    private:
        std::string first_name;
        std::string last_name;
        
    public:
        std::vector<Book *>books_red;
        int book_lented;
        Reader();
        Reader(std::string f_name, std::string l_name);
        ~Reader();
        void get_name();
        void output_red_books();
};