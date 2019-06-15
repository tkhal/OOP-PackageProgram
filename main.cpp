// Client file, used to call call functions and control program
// Tim Khal | Program #2
#include "list.h"

void showMethods(); // Shows the methods of delivery options
char* copy(char* array); // Function used to copy user input

int main()
{
    list operate; // Object of list, used to call functions
    fragile fragileDelivery; // Object of fragile delivery, used to call signature function

    //package personal; // Creating an object of package, containing personal info 
    char response; // Used to hold user response of menu

    do {

        cout << "\n\n----- MENU ----- \n\n";
        cout << "1) Add a package\n";
        cout << "2) Display packages\n";
        cout << "3) Search for a name\n";
        cout << "4) Delete a package\n";

        // ...
        cout << "7) End\n";
        cin >> response;
        cin.ignore(100, '\n');

        switch (response)
        {
            case '1':
                {
                    // First, get data members for abstract class
                    char* tempName = NULL;
                    char* tempAddress = NULL;
                    char* tempContents = NULL;

                    cout << "\nEnter name of recipient:\n";
                    tempName = copy(tempName);

                    cout << "\nEnter Address of recipient:\n";
                    tempAddress = copy(tempAddress);

                    cout << "\nEnter contents of package:\n";
                    tempContents = copy(tempContents);

                    // Now that we have our data members, ask the client which delivery method they'd like to proceed with
                    char method; // User response for 
                    cout << "\nInformation recorded!\n";
                    cout << "\nWhich delivery would you like to proceed with?\n";
                    showMethods(); // Case 1 for fragile, 2 for insured, 3 for expedited, 4 for food 

                    cin >> method;
                    cin.ignore(100, '\n');
                    switch (method)
                    {
                        case '1': // Case for fragile delivery  
                            {
                                char* tempSign = NULL;
                                cout << "\nYou've selected 'Fragile Delivery'\nPlease sign for the package:\n";
                                tempSign = fragileDelivery.getSignature(tempSign);

                                package* ptr = new fragile(tempName, tempAddress, tempContents, tempSign); // Set all info into ptr

                                operate.insert(ptr); // Now, pass all info into insert function. rear -> data will be pointing at ptr
                                cout << "\nFragile delivery added!\n";
				delete [] tempSign; // Deallocating memory for char* tempSign

                                break;
                            }
                        case '2': // Case for insured delivery
                            {
                                char tempCheck; // A temporary variable used to store users check
                                cout << "\nYou've selected 'Insured Delivery'\nDo you agree to make the insurance payment of $15? (Y/N)\n";

                                cin >> tempCheck;
                                tempCheck = tolower(tempCheck);
                                cin.ignore(100, '\n');

                                if (tempCheck != 'y'){
                                    cout << "\nInsurance declined\n";
                                    break;
                                }

                                package* ptr = new insured(tempName, tempAddress, tempContents, tempCheck);

                                operate.insert(ptr);
                                cout << "\nInsured delivery added!\n";
                                break;
                            }

                        case '3':
                            {
                                char tempTransport; // temp variable to store users response of transport

                                cout << "\nYou've selected 'Expedited Delivery'\nWhich method of delivery would you like?\n";
                                cout << "1) Airplane\n";
                                cout << "2) Train\n";
                                cout << "3) Helicopter\n";
                                cin >> tempTransport; // User has stored response into tempTransport, now store into base class ptr
                                cin.ignore(100, '\n');

                                if (tempTransport != '1' || tempTransport != '2' || tempTransport != '3') // Making sure we're within bounds
                                {
                                    cout << "Invalid entry\n";
                                    return 0;
                                }

                                package* ptr = new exp(tempName, tempAddress, tempContents, tempTransport);
                                operate.insert(ptr);
                                cout << "Expedited delivery added!\n";
                                break;
                            }

                            
                        case '4':
                            {
                                int tempTemp = 0;
                                cout << "You've selected 'Food Delivery'. Please input the temperature in degree's F you'd like the food to be stored in:\n";
                                cin >> tempTemp;
                                cin.ignore(100, '\n');

                                package* ptr = new food(tempName, tempAddress, tempContents, tempTemp);

                                operate.insert(ptr);
                                cout << "\nFood delivery added!\n";
                                break;
                            }

                        default:
                            {
                                cout << "\nInvalid, please try again\n";
                                break;

                            }
                    }
                    delete [] tempName;
                    delete [] tempAddress;
                    delete [] tempContents;

                    break;
                }

            case '2':
                {
                    cout << "\nAll packages: \n";
                    int check = operate.display();
                    if (check == 0)
                        cout << "\nERROR: List is empty\n";

                    break;
                }
            case '3':
                {
                    char* tempSearch = NULL;
                    cout << "\nPlease enter the name of the package you'd like to search for:\n";
                    tempSearch = copy(tempSearch); // Copying user information into tempSearch

                    int check = operate.search(tempSearch); // Passing tempSearch to function call

                    if (check == 1) // Package in list!
                        cout << endl << tempSearch << " is in the list!\n";
                    else
                        cout << endl << tempSearch << " was NOT in the list/\n";


                    delete [] tempSearch;
                    break;
                }
            case '4':
                {
                    char* tempSearch = NULL;
                    cout << "\nPlease enter the name of the package you'd like to remove:\n";
                    tempSearch = copy(tempSearch); // Copying user info into tempSearch

                    int check = operate.remove(tempSearch);

                    if (check == 1) // Package in list!
                        cout << endl << tempSearch << " has been removed!\n";
                    else
                        cout << endl << tempSearch << " was NOT in the list/\n";


                    break;
                }



            case '7':
                {
                    cout << "\nProgram ending...\n";
                    return 0;
                }
            default:
                {
                    cout << "\nInvalid option. Try again\n";
                    break;
                }

        }
    } while (response != '7'); // 7 for end program
}



void showMethods()
{
    cout << "\n\nPlease enter in which delivery methonds you'd like to proceed with:\n";
    cout << "1) Fragile delivery\n"; // char* to enter a cushioning
    cout << "2) Insured delivey\n"; // char* to sign for delivery
    cout << "3) Expedited delivery\n"; // An int to pay for deliver. int $15?
    cout << "4) Food delivery (Temperature dependent)\n";
    // Add more
}

char* copy(char* array){
    char temp[101]; // Temporary buffer variable to store user response

    cin.get(temp, 101, '\n');
    cin.ignore(101, '\n');

    array = new char[strlen(temp) + 1];
    strcpy(array, temp);

    return array;
}




