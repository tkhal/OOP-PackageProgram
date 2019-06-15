// Implementation file for abstract base class + derived classes
// Tim Khal | Program #2

#include "list.h"

// ===============================================
// Package
package::package(){ // Default constructor
    name = NULL;
    address = NULL;
    contents  = NULL;
}

package::~package() // Destructor
{
    if (name)
        delete [] name;
    if (address)
        delete [] address;
    if (contents)
        delete [] contents;

}

void package::setInfo(package* toAdd) // Function to copy over user information into protected data members
{
    name = new char[strlen(toAdd -> name) + 1]; // Allocating memory
    strcpy(name, toAdd -> name);

    address = new char[strlen(toAdd -> address) + 1];
    strcpy(address, toAdd -> address);

    contents = new char[strlen(toAdd -> contents) + 1];
    strcpy(contents, toAdd -> contents);
}

char* package::getName(){ // Getter for name
    return name;
}
char* package::getAddress(){ // Getter for address
    return address;
}
char* package::getContents(){ // Getter for contents
    return contents;
}


package::package(char* tempName, char* tempAddress, char* tempContents) // Constructor to allocate memory for package fields
{
    name = new char[strlen(tempName + 1)];
    strcpy(name, tempName);

    address = new char[strlen(tempAddress + 1)];
    strcpy(address, tempAddress);

    contents = new char[strlen(tempContents + 1)];
    strcpy(contents, tempContents);
}




// ===============================================
// Fragile

fragile::fragile() // Default constructor for derived classes
{
    sign = NULL;
}

fragile::~fragile() // Destructor
{
    delete [] sign;
}

fragile::fragile(char* tempName, char* tempAddress, char* tempContents, char* tempSign):package(tempName, tempAddress, tempContents) // Copies over all fields for fragile
{
    sign = new char[strlen(tempSign + 1)];
    strcpy(sign, tempSign);
}

char* fragile::getSignature(char* tempSign)
{
    char temp[101];
    cin.get(temp, 101, '\n');
    cin.ignore(101, '\n');

    tempSign = new char[strlen(temp) + 1];
    strcpy(tempSign, temp);
    return tempSign;
}

void fragile::display()
{
    cout << name << endl;
}

// ===============================================
// Insured

insured::insured() // Constructor, to initialize values
{
    check = 0;
}


insured::insured(char* tempName, char* tempAddress, char* tempContents, char tempCheck):package(tempName, tempAddress, tempContents) // Constructor to copy values into inherited data members
{
    check = tempCheck; // Setting the users response of tempCheck into check
}

void insured::display() 
{}

// ===============================================
// Food

food::food() // default constructor
{
    temperature = 0;
}


food::food(char* tempName, char* tempAddress, char* tempContents, int tempTemp):package(tempName, tempAddress, tempContents) // Constructor to copy values into inherited data members
{
    temperature = tempTemp;
}

void food::display()
{}

// ===============================================
// expedited delivery
exp::exp() // Copy constructor
{
    transport = 0;
}

exp::exp(char* tempName, char* tempAddress, char* tempContents, char tempTransport):package(tempName, tempAddress, tempContents) // Constructor to copy values into inherited data members
{
    transport = tempTransport;
}

void exp::display()
{}





