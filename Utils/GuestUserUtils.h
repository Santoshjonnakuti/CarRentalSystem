#ifndef GUESTUSERUTILS_H
#define GUESTUSERUTILS_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "../sqlite/sqlite3.h"
#include "DataTypes.h"
#include "Messages.h"

using namespace std;

int guestUserLoggedIn = 0;
string GUId = "";
string LoggedInGuestUserID = "";
int totalGuestUsers;

static int getNoOfGUsers(void *data, int argc, char **argv, char **azColName)
{
    totalGuestUsers = atoi(argv[0]);
    LoggedInGuestUserID = LoggedInGuestUserID + to_string(totalGuestUsers + 1);
    return totalGuestUsers;
}
// static int GUCallback(void *data, int argc, char **argv, char **azColName)
// {
//     string uname = string(argv[5]);
//     string passwd = string(argv[6]);
//     if (GUUsername.compare(uname) == 0 && GUPassword.compare(passwd) == 0)
//     {
//         printSuccessMessage("\nLoggedin as " + string(argv[1]) + " ...\n");
//         guestUserLoggedIn = 1;
//     }
//     return 0;
// }
static int GUDetails(void *data, int argc, char **argv, char **azColName)
{
    // string id = string(argv[0]);
    // if (GUId.compare(id) == 0)
    // {
    printGuestUserDetails(argv);
    guestUserLoggedIn = 1;
    // }
    return 0;
}

// int registeredUserLogin(RegisteredUserDataType RU)
// {
//     GUUsername = GUUsername + RU.userName;
//     GUPassword = GUPassword + RU.password;
//     sqlite3 *DB;
//     int exit = 0;
//     char *sqliteError;
//     exit = sqlite3_open("./Database/DataBase.db", &DB);
//     if (exit)
//     {
//         printErrorMessage("\nError Opening Database...\nTry Again Later\n");
//         return 0;
//     }
//     printSuccessMessage("\nDatabase Opened Successfully!\n");
//     string sql = "SELECT * FROM REGISTERED_USER;";
//     sqlite3_exec(DB, sql.c_str(), GUCallback, 0, &sqliteError);
//     sqlite3_close(DB);
//     if (!guestUserLoggedIn)
//     {
//         printErrorMessage("\nInvalid Credentials...\nPlease Try Again...\n");
//     }
//     GUUsername = "";
//     GUPassword = "";
//     return guestUserLoggedIn;
// }

#endif