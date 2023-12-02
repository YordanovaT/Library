#pragma once
#include <iostream>
#include "reader.h"
#include "book.h"

class Library
{
    public:
        Reader *readers_arr[50];
        Book *books[100];
        int readers_count;
        int books_count;

        Library();
        ~Library();

        void add_reader(Reader *reader);
        void add_book(Book *book);
        void delete_reader(int reader_id);
        void delete_book(int book_id);
        void print_all_books_for_reader(int id);
        void land_a_book();
        void return_a_book();
        void print_all_books();

};   