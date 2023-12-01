#include "library.h"
#include "reader.h"
#include "book.h"


int main()
{
    int choice, id;
    std::string f_name, l_name;
    std::string b_name, author_n;
    
    // creating instances
    Library library;
    Book *b=0;
    Reader *r=0;

    while (1)
    {
        std::cout<<"\n--------------------------------------- MENU --------------------------------------- \n";
        std::cout<<"Do you wish to perform an operation? Choose a number between 0-8.\n";
        std::cout<<"1. Add an reader.\n";
        std::cout<<"2. Delete reader.\n";
        std::cout<<"3. Print reader's books.\n";
        std::cout<<"4. Add new book.\n";
        std::cout<<"5. Delete book.\n";
        std::cout<<"6. Print all books available.\n";
        std::cout<<"7. Land a book.\n";
        std::cout<<"8. Return a book.\n";
        std::cout<<"0. Exit program.\n";

        std::cin>>choice;
        std::cin.ignore();

        if(choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            std::cout<<"----------------------------------------------- Add new reader ----------------------------------------------- \n";
            std::cout<<"Enter reader's first name: ";
            std::cin>>f_name;
            std::cin.ignore();

            std::cout<<"\nEnter reader's last name: ";
            std::cin>>l_name;
            std::cin.ignore();

            r=new Reader(f_name, l_name);
            library.add_reader(r);
            std::cout<<"------------------------------------------------------------------------------------------------------------- \n\n";
            break;

        case 2:

            std::cout<<"---------------------------------------------- Delete a reader ---------------------------------------------- \n";
            std::cout<<"Enter reader's ID: ";
            std::cin>>id;
            std::cin.ignore();
            
            library.delete_reader(id);
            id=0;
            std::cout<<"------------------------------------------------------------------------------------------------------------- \n\n";
            break;

        case 3:
            std::cout<<"Enter reader's ID: ";
            std::cin>>id;
            std::cin.ignore();

            std::cout<<"---------------------------------------------- Print a reader ---------------------------------------------- \n";
            library.print_all_books_for_reader(id);
            id=0;
            std::cout<<"------------------------------------------------------------------------------------------------------------- \n\n";
            break;

        case 4:
            std::cout<<"----------------------------------------------- Add new book ----------------------------------------------- \n";
            std::cout<<"Enter book name: ";
            std::getline(std::cin,b_name);

            std::cout<<"\nEnter author name: ";
            std::getline(std::cin,author_n);

            b=new Book(b_name, author_n);
            library.add_book(b);
            std::cout<<"------------------------------------------------------------------------------------------------------------- \n\n";
            break;
        case 5:
            std::cout<<"----------------------------------------------- Delete a book ----------------------------------------------- \n";
            std::cout<<"Enter book's ID: ";
            std::cin>>id;
            std::cin.ignore();
            
            library.delete_book(id);
            id=0;
            std::cout<<"------------------------------------------------------------------------------------------------------------- \n\n";
            break;

        case 6:
           
            std::cout<<"---------------------------------------------- Print all books ---------------------------------------------- \n";
            library.print_all_books();
            std::cout<<"------------------------------------------------------------------------------------------------------------- \n\n";
            break;

        case 7:
           
            std::cout<<"------------------------------------------------ Land a book ------------------------------------------------ \n";
            library.land_a_book();
            std::cout<<"------------------------------------------------------------------------------------------------------------- \n\n";
            break;

        case 8:
           
            std::cout<<"------------------------------------------------ Return a book ------------------------------------------------ \n";
            library.return_a_book();
            std::cout<<"------------------------------------------------------------------------------------------------------------- \n\n";
            break;

        default:
            break;
        }
    }

}