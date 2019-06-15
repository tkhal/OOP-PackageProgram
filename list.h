
// Tim Khal | Program #2
#include "package.h"
#include <iostream>
#include <cstring>

using namespace std;


class node
{
    public:
        node(); // Constructor
//        node(package* ); // second constructor, used for RTTI
        node(const node & obj); // Copy constructor
        ~node(); // Destructor

        
        void setNext(node* newNode); // Function to set the next pointer to the list
        node* & getNext(); // Returns the next node
        void setData(package* &);
        package* getData(); // Returns the data's pointer

    protected:
        node* next;
        package* data; // Each node is going to have information about a package
};



class list
{
    public:
        list(); // Default constructor
        list(const list & oldList); // copy constructor
        ~list(); // Destructor
        void insert(package* & ptr); // Function to insert a package
        int display(); // Function to display packages
        int search(char* tempSearch); // Function to search for a package
        int remove(char* tempSearch);


    protected:
        node* rear; // rear of the list
        void insert(package* & ptr, node* & rear); // Function to insert
        int display(node* rear); // function to display
        int w_display(node* rear); // Wrapper function for display
        int w_search(node* rear, char* tempSearch); // Function to search
        int search(node* rear, char* tempSearch); // Function to search
        int remove(node* rear, char* tempSearch);
        int w_remove(node* rear, char* tempSearch);

        //int insured_display(node* rear); // function to only display insured

};

