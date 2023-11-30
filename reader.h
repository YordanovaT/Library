#pragma once
#include <iostream>
#include <string.h>

class Reader{
    private:
        std::string first_name;
        std::string last_name;
    public:
        int count_of_books;
        Reader();
        Reader(std::string f_name, std::string l_name);
        ~Reader();
        void get_name();
};