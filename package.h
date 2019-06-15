// Header file for abstract base class, and all following derived classes

// Tim Khal | Program #2
#include <iostream>
#include <cstring>

class package // The info that is going to be contained wit
{
    public:
        package();
        package(const package & packageObj);
        virtual ~package();
        package(char* tempName, char* tempAddress, char* tempContents); // Constructor to a copy over all information from temp variables stored in main
                                                                        // protected data members

        virtual void display() = 0; // might change to display ____

        void setInfo(package* toAdd);
        char* getName(); // Getter for name
        char* getAddress(); // Getter for address
        char* getContents(); // Getter for contents
    protected:
        char* name; // Clients name
        char* address; // Clients address 
        char* contents; // Clients contents

};

class fragile:public package
{
    public:
        // add constructor
        fragile(); // Constructor
        ~fragile();
        fragile(char* tempName , char* tempAddress, char* tempContents, char* tempSign);
        void display();
        char* getSignature(char* ); // Function to get clients signature


    protected:
        char* sign; // Holds clients signature

};


class insured:public package
{
    public: 
        insured(); // Constructor
        insured(char* tempName, char* tempAddress, char* tempContents, char tempCheck); // Constructor with args, to copy values from inherited data members
        void display();

    protected:
        char check;
};    

class exp:public package
{
    public:
        exp();
        exp(char* tempName, char* tempAddress, char* tempContents, char tempTransport); // Constructor with args, to copy values from inherited data members
        void display();

    protected:
        char transport;
};





class food:public package
{
    public:
        food(); // Default constructor
        void display();
        food(char* tempName, char* tempAddress, char* tempContents, int tempTemp); // Constructor with args, to copy values from inherited data members

    protected:
        int temperature;



};


