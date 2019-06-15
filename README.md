# OOP-PackageProgram
Project to practice object oriented programming. Circular Linked List data structure.

This program is meant to represent a list of packages being delivered. The client can select what kind of package they'd like, and their inputs will be stored in local temporary variables in main. Further prompts are dependent on the type of package they select. Once we gather all of the data, we will use upcasting to treat the base class pointer as a derived class, copy over all the data using derived class constructor, and pass the new pointer into the insert function. 

- Still need to update display function to support RTTI

list.cpp - Contains setters, getters, constructors, and destructors.
list.h - Interface for list and node class. 
main.cpp - Used to call call functions and control program
functions.cpp - Implementation file for circular linked list class, contains basic CLL functions
package.cpp - Implementation file for abstract base class + derived classes
package.h - Header file for abstract base class, and all following derived classes

