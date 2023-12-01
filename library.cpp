#include "library.h"

Library::Library()
{
    readers_count=0;
    books_count=0;
}

void Library::add_reader(Reader *reader)
{
    if(readers_count>50)
    {
        std::cout<<"Sorry. You have reached the max capacity. Try deleting some readers.\n";
        return;
    }
    readers_arr[readers_count]=reader;
    readers_count++;
}

void Library::delete_reader(int reader_id)
{
    int flag=0;
    if(readers_count==0)
    {
        std::cout<<"Sorry. There are no readers. Try adding some.\n";
        return;
    }

    for(int i=0; i<readers_count; i++)
    {
        if(reader_id==i+1)
        {
            readers_arr[i]=readers_arr[readers_count-1];
            readers_count--;
            flag=1;
        }
    }
    if(!flag)
    {
        std::cout<<"Error! Found no reader with the given ID. Try again.\n";
        return;
    }

}

void Library::print_all_books_for_reader(int id)
{
    for(int i=0; i<readers_count; i++)
    {
        if(id==i+1)
        {
            readers_arr[i]->get_name();
            std::cout<<"---------------------------------------------- Books lented ---------------------------------------------- \n";
            readers_arr[i]->output_red_books();

        }
    }
}

void Library::add_book(Book *book)
{
    if(books_count>100)
    {
        std::cout<<"Sorry. You have reached the max capacity. Try deleting some books.\n";
        return;
    }
    books[books_count]=book;
    books_count++;
}

void Library::delete_book(int book_id)
{
    int flag=0;
    if(books_count==0)
    {
        std::cout<<"Sorry. There are no books. Try adding some.\n";
        return;
    }

    for(int i=0; i<books_count; i++)
    {
        if(book_id==i+1)
        {
            books[i]=books[books_count-1];
            books_count--;
            flag=1;
        }
    }
    if(!flag)
    {
        std::cout<<"Error! Found no book with the given ID. Try again.\n";
        return;
    }
}

void Library::land_a_book()
{
    int id; int flag=0;

    std::string name_of_book, name_of_author;
    std::cout<<"Enter reader's ID: ";
    std::cin>>id;
    std::cin.ignore();

    for(int i=0; i<readers_count; i++)
    {
        if(id==i+1)
        {
            flag=1;

            if(readers_arr[i]->book_lented==3)
            {
                std::cout<<"Sorry, can't land this book. You still haven't returned the three books you last lented.\n";
                return;
            }

            std::cout<<"Enter author: ";
            std::getline(std::cin,name_of_author);
            
            std::cout<<"Enter book's name: ";
            std::getline(std::cin, name_of_book);            
            
            for(int j=0; j<books_count; j++)
            {
                if(name_of_book==books[j]->book_name && name_of_author==books[j]->author_name)
                {
                   
                    if(books[j]->land==1)
                    {
                        std::cout<<"Sorry, this book is already landed to someone alse. Try finding another one.\n";
                        return;
                    }
                    books[j]->land_book();
                    books[j]->land=1;
                    readers_arr[i]->books_red.push_back(books[j]);
                }              
            }
            readers_arr[i]->book_lented++;  
        }
    }
    if(!flag)
    {
        std::cout<<"Error! Found no reader with the given ID. Try again.\n";
        return;
    }
    
}

void Library::return_a_book()
{
    int id; int flag=0;
    std::string name_of_book, name_of_author;
    std::cout<<"Enter reader's ID: ";
    std::cin>>id;
    std::cin.ignore();
    for(int i=0; i<readers_count; i++)
    {
        if(id==i+1)
        {
            flag=1;

            if(readers_arr[i]->book_lented==0)
            {
                std::cout<<"You have no books to be returned.\n";
                return;
            }

            std::cout<<"Enter author: ";
            std::getline(std::cin,name_of_author);
            
            std::cout<<"Enter book's name: ";
            std::getline(std::cin, name_of_book);
            
            

            for(int i=0; i<books_count; i++)
            {
                if(name_of_book==books[i]->book_name && name_of_author==books[i]->author_name)
                {
                    if(books[i]->land==0)
                    {
                        std::cout<<"Sorry, you cannot return a book you haven't landed.\n";
                        return;
                    }
                    
                    books[i]->return_book();
                    books[i]->land=0;
                }
                
            }  
            readers_arr[i]->book_lented--; 
        }
    }
    if(!flag)
    {
        std::cout<<"Error! Found no reader with the given ID. Try again.\n";
        return;
    }
    
}

void Library::print_all_books()
{
    for(int i=0;i<books_count; i++)
    {
        std::cout<<i+1;
        books[i]->output();
    }
}
Library::~Library()
{
    
    for(int i=0; i<readers_count; i++)
    {
        delete readers_arr[i];
    }
    for(int i=0; i<books_count; i++)
    {
        delete books[i];
    }
}