#ifndef MESSAGES_H
#define MESSAGES_H
#include <iostream>

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

#endif