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
static int RUcallback(void *data, int argc, char **argv, char **azColName)
{
    string uname = string(argv[5]);
    string passwd = string(argv[6]);
    if (RUUserName.compare(uname) == 0 && RUPassword.compare(passwd) == 0)
    {
        printSuccessMessage("\nLoggedin as " + string(argv[1]) + " ...\n");
        registeredUserLoggedIn = 1;
    }
    return 0;
}
static int RUDetails(void *data, int argc, char **argv, char **azColName)
{
    string uname = string(argv[5]);
    string passwd = string(argv[6]);
    if (RUUserName.compare(uname) == 0 && RUPassword.compare(passwd) == 0)
    {
        printRegisteredUserDetails(argv);
        registeredUserLoggedIn = 1;
    }
    return 0;
}

int registeredUserLogin(RegisteredUserDataType RU)
{
    RUUserName = RUUserName + RU.userName;
    RUPassword = RUPassword + RU.password;
    sqlite3 *DB;
    int exit = 0;
    char *sqliteError;
    exit = sqlite3_open("./Database/DataBase.db", &DB);
    if (exit)
    {
        printErrorMessage("\nError Opening Database...\nTry Again Later\n");
        return 0;
    }
    printSuccessMessage("\nDatabase Opened Successfully!\n");
    string sql = "SELECT * FROM REGISTERED_USER;";
    sqlite3_exec(DB, sql.c_str(), RUcallback, 0, &sqliteError);
    sqlite3_close(DB);
    if (!registeredUserLoggedIn)
    {
        printErrorMessage("\nInvalid Credentials...\nPlease Try Again...\n");
    }
    RUUserName = "";
    RUPassword = "";
    return registeredUserLoggedIn;
}
void getRegisteredUserInformation(RegisteredUserDataType RU)
{
    RUUserName = RUUserName + RU.userName;
    RUPassword = RUPassword + RU.password;
    sqlite3 *DB;
    int exit = 0;
    char *sqliteError;
    exit = sqlite3_open("./Database/DataBase.db", &DB);
    if (exit)
    {
        printErrorMessage("\nError Opening Database...\nTry Again Later\n");
        return;
    }
    printSuccessMessage("\nDatabase Opened Successfully!\n");
    string sql = "SELECT * FROM REGISTERED_USER;";
    sqlite3_exec(DB, sql.c_str(), RUDetails, 0, &sqliteError);
    sqlite3_close(DB);
    if (!registeredUserLoggedIn)
    {
        printErrorMessage("\nInvalid Credentials...\nPlease Try Again...\n");
    }
    return;
}
#endif