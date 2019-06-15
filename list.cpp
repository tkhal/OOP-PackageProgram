
// Tim Khal | Program #2
#include "list.h"

// =================================================
// Node

node::node(){ // Default constructor
    next = NULL;
}

node::~node()
{
    if (next)
        delete [] next;
    if (data)
        delete data;

}

void node::setNext(node* newNode) // Setter function for node
{
    next = newNode;
}

node* & node::getNext() // Getter function for node
{
    return next;
}


/*
node::node(package* ptr)
{
    package* a_package;
    a_package = ptr;

    
    fragile* new_fragile = dynamic_cast<fragile* >(a_package);
    if (new_fragile == NULL)
        data = new fragile(new_fragile);
    // Do this for all other derived objects

}
*/

void node::setData(package* & newPackage) // Setter for data pointer
{
    data = newPackage;

}
    

package* node::getData() // Returns the data's pointer
{
    return data;
}


// =================================================
// List
list::list(){
    rear = NULL;
}

list::~list(){
    if (rear)
        delete rear;

}

/*
list(const list & oldList) // Obviously change this
{
    if (!oldList.getRear())
        return 

}
*/



