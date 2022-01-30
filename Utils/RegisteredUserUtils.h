#ifndef REGISTEREDUSERUTILS_H
#define REGISTEREDUSERUTILS_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "../sqlite/sqlite3.h"
#include "DataTypes.h"
#include "Messages.h"

using namespace std;

int registeredUserLoggedIn = 0;
string RUUserName = "", RUPassword = "";
string LoggedInRegisteredUserID = "";
int totalRegisteredUsers;

static int getNoOfRUsers(void *data, int argc, char **argv, char **azColName)
{
    totalRegisteredUsers = atoi(argv[0]);
    return totalRegisteredUsers;
}
static int RUcallback(void *data, int argc, char **argv, char **azColName)
{
    string uname = string(argv[5]);
    string passwd = string(argv[6]);
    if (RUUserName.compare(uname) == 0 && RUPassword.compare(passwd) == 0)
    {
        LoggedInRegisteredUserID = LoggedInRegisteredUserID + argv[0];
        printSuccessMessage("\nLoggedin as " + string(argv[1]) + " ...\n");
        registeredUserLoggedIn = 1;
    }
    return 0;
}
static int RUDetails(void *data, int argc, char **argv, char **azColName)
{
    // string uname = string(argv[5]);
    // string passwd = string(argv[6]);
    // if (RUUserName.compare(uname) == 0 && RUPassword.compare(passwd) == 0)
    // {
    printRegisteredUserDetails(argv);
    registeredUserLoggedIn = 1;
    // }
    return 0;
}

#endif