// Implementation file for circular linked list class, contains basic CLL functions
// Tim Khal | Program #2

#include "list.h"

void list::insert(package* & ptr) // wrapper insert function
{
    insert(ptr, rear);
}

void list::insert(package* & ptr, node* & rear)
{
    if (!rear)
    {
        rear = new node;
        rear -> setData(ptr); // Is this right?

        rear -> setNext(rear);
        // to display: rear -> data -> display()    from package class
    }

    else
    {
        node* temp = new node;
        temp -> setData(ptr);
        temp -> setNext(rear -> getNext());
        rear -> setNext(temp);
    }

}
// ==================================    
int list::display() // Wrapper display function
{
    return w_display(rear);
}

int list::w_display(node* rear) // Helper display function
{
    if (!rear) return 0; // If list is empty
    
    if (!rear -> getNext())
    {
        cout << "\nThere's only one package:\n";
        cout << "\nName: " << rear -> getData() -> getName();
        cout << "\nAddress: " << rear -> getData() -> getAddress();
        cout << "\nContents: " << rear -> getData() -> getContents();

        return 1;
    }

    return display(rear -> getNext()); // If there's more than one node, then traverse through list and display

}

int list::display(node* rear) // Displays all nodes in the list
{
    if (rear == this -> rear) // At the last node, so display one more time then return
    {
        cout << "\nName: " << rear -> getData() -> getName();
        cout << "\nAddress: " << rear -> getData() -> getAddress();
        cout << "\nContents: " << rear -> getData() -> getContents();
        return 1;
    }

        cout << "\nName: " << rear -> getData() -> getName();
        cout << "\nAddress: " << rear -> getData() -> getAddress();
        cout << "\nContents: " << rear -> getData() -> getContents();


    display(rear -> getNext());
    return 1;
}

// ==================================    


int list::search(char* tempSearch) // Wrapper function for search
{
    return w_search(rear, tempSearch);
    return 1;
}

int list::w_search(node* rear, char* tempSearch) // Helper function for search, checks first nodes
{
    if (!rear) return 0; // If list is empty

    if (!rear -> getNext()) // Is there only one node?
    {
        if (strcmp(tempSearch, rear -> getData() -> getName()) == 0) // found a match!
            return 1;
        else
            return 0;
    }

    // If no match found, call function and recurse through list

    search(rear -> getNext(), tempSearch);
    return 1;
}

int list::search(node* rear, char* tempSearch)
{
    if (rear == this -> rear) // At the last node, so check again
    {
        if (strcmp(tempSearch, rear -> getData() -> getName()) == 0) // found a match!
            return 1;
        else
            return 0;
    }
     
    if (strcmp(tempSearch, rear -> getData() -> getName()) == 0) // found a match!
        return 1;

    search(rear -> getNext(), tempSearch);
    return 1;
}


// ==================================    


int list::remove(char* tempSearch)
{
    return w_remove(rear, tempSearch);
}

int list::w_remove(node* rear, char* tempSearch)
{
    if (!rear) return 0; // If list is empty

    if (!rear -> getNext()) // Is there only one node?
    {
        delete [] rear -> getData() -> getName();
        delete [] rear -> getData() -> getAddress();
        delete [] rear -> getData() -> getContents();
        delete rear;
        return 1;
    }
    // If no match found, call function and recurse through list

    return remove(rear, tempSearch);
    return 1;
}

int list::remove(node* rear, char* tempSearch)
{
    if (rear -> getNext() == this -> rear) // At the 2nd to last node
    { // Check if the last node is a search
        if (strcmp(rear -> getNext() -> getData() -> getName(), tempSearch) == 0) // Found a match, so delete rear -> next's data
        {
            delete [] rear -> getNext() -> getData() -> getName(); // Deleting all dynamic memory...
            delete [] rear -> getNext() -> getData() -> getAddress();
            delete [] rear -> getNext() -> getData() -> getContents();
            node* temp = rear -> getNext(); // Setting a temp ptr in the node to be deleted, so that we can reconnect the list
            rear -> setNext(temp -> getNext()); // Setting rear -> next = temp -> next
            delete temp;
            return 1;
        }
        else
            return 0;
    }

    // For every other instance

    if (strcmp(rear -> getNext() -> getData() -> getName(), tempSearch) == 0) // Found a match, so delete rear -> next's data
    {
        node* temp = rear -> getNext(); // Set temp ptr equal to node to be deleted
        delete [] rear -> getNext() -> getData() -> getName(); // Deleting all dynamic memory...
        delete [] rear -> getNext() -> getData() -> getAddress();
        delete [] rear -> getNext() -> getData() -> getContents();

        rear -> setNext(temp -> getNext()); // Setting rear -> next equal to temp -> next
        temp -> setNext(NULL); // setting temps next to NULL
        delete temp;
        return 1;
    }

    remove(rear -> getNext(), tempSearch);
    return 1;
}















