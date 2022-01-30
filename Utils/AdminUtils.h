#ifndef ADMINUTILS_H
#define ADMINUTILS_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "../sqlite/sqlite3.h"
#include "Messages.h"

using namespace std;

int adminLoggedIn = 0;
string AUserName = "", APassword = "";
string LoggedInAdminID = "";
int i = 0;

static int getNoOfCars(void *data, int argc, char **argv, char **azColName)
{
    i = atoi(argv[0]);
    return i;
}
static int getCarDetails(void *data, int argc, char **argv, char **azColName)
{
    printCarDetails(argv);
    return 0;
}
static int getAllCarsDetails(void *data, int argc, char **argv, char **azColName)
{
    printCarDetails(argv);
    return 0;
}
static int callback(void *data, int argc, char **argv, char **azColName)
{
    string uname = string(argv[1]);
    string passwd = string(argv[2]);
    if (AUserName.compare(uname) == 0 && APassword.compare(passwd) == 0)
    {
        LoggedInAdminID = LoggedInAdminID + argv[4];
        printSuccessMessage("\nLoggedin as Admin...\n");
        adminLoggedIn = 1;
    }
    return 0;
}

#endif