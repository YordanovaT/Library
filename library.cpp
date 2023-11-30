#include "library.h"

Library::Library()
{
    readers_count=0;
}

int Library::check_for_readers()
{
    int result;
    if(readers_count>50)
    {
        std::cout<<"Sorry. You have reached the max capacity. Try deleting some readers.\n";
        return 0;
    }
    if(readers_count==0)
    {
        std::cout<<"Sorry. There are no readers. Try adding some.\n";
        return 0;
    }
    

    return 1;

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

void Library::print_all_books()
{
    for(int i=0; i<readers_count; i++)
    {
        std::cout<<i+1<<"\t";
        readers_arr[i]->get_name();
    }
}

Library::~Library()
{
    
    for(int i=0; i<readers_count; i++)
    {
        delete readers_arr[i];
    }
}