#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>

using namespace std;

struct AdminDetails
{
    string name;
    string userName;
    string password;
};
struct Choice
{
    int choice;
    int LoggedIn = 0;
};

#endif