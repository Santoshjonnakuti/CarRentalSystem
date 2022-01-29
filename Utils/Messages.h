#ifndef MESSAGES_H
#define MESSAGES_H
#include <iostream>
#include <string>

using namespace std;

void printErrorMessage(string errorMessage)
{
    string error = "\033[1;31m" + errorMessage + "\033[0m\n";
    cout << error << endl;
}

void printSuccessMessage(string successMessage)
{
    string success = "\033[1;32m" + successMessage + "\033[0m\n";
    cout << success << endl;
}

void printWarningMessage(string warningMessage)
{
    string warning = "\033[1;33m" + warningMessage + "\033[0m\n";
    cout << warning << endl;
}

void printInformation(string informationMessage)
{
    string information = "\033[1;34m" + informationMessage + "\033[0m\n";
    cout << information << endl;
}
void printCarDetails(char **argv)
{
    printInformation("--------------------------Car Details-----------------------------------\nCar Name            : " + string(argv[0]) + "\nCar Capacity        : " + argv[2] + "\nCar FuelType        : " + argv[3] + "\nCar Mileage         : " + argv[4] + "\nCar Condition       : " + argv[5] + "\nCar Driver          : " + argv[6] + "\nCar AccidentHistory : " + argv[7] + "\nCar PriccePerKM     : " + argv[8] +
                     "\nCar Total           : " + argv[9] + "\nCar Rented          : " + argv[10] + "\nCar Available       : " + argv[11] + "\n");
    return;
}
void printRegisteredUserDetails(char **argv)
{
    printInformation("--------------------------User Details----------------------------------\nUser Name            : " + string(argv[1]) + "\nUser Mobile Number   : " + argv[2] + "\nUser Email Id        : " + argv[3] + "\nUser Address         : " + argv[4] + "\nUser Username        : " + argv[5] + "\nUser Password        : " + argv[6] + "\n");
    return;
}
void printGuestUserDetails(char **argv)
{
    printInformation("------------------------Guest User Details------------------------------\nUser Name            : " + string(argv[1]) + "\nUser Mobile Number   : " + argv[2] + "\nUser Id              : " + argv[0] + "\n");
    return;
}
#endif