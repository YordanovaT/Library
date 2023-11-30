#pragma once
#include <iostream>
#include "reader.h"

class Library
{
    public:
        Reader *readers_arr[50];
        int readers_count;

        Library();
        ~Library();

        void add_reader(Reader *reader);
        void delete_reader(int reader_id);
        int check_for_readers();
        void print_all_books();

};   