#include <iostream>

using namespace std;

void printErrorMessage(string error)
{
    string err = "\033[1;31m" + error + "\033[0m\n";
    cout << err << endl;
}

void printSuccessMessage(string successMessage)
{
    string sm = "\033[1;32m" + successMessage + "\033[0m\n";
    cout << sm << endl;
}

void printWarningMessage(string warning)
{
    string w = "\033[1;33m" + warning + "\033[0m\n";
    cout << w << endl;
}