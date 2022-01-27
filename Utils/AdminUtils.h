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
string userName = "", password = "";
static int callback(void *data, int argc, char **argv, char **azColName)
{
    string uname = string(argv[1]);
    string passwd = string(argv[2]);
    if (userName.compare(uname) == 0 && password.compare(passwd) == 0)
    {
        printSuccessMessage("\nLoggedin as Admin...\n");
        adminLoggedIn = 1;
    }
    return 0;
}

int adminLogin(string uN, string pD)
{
    userName = userName + uN;
    password = password + pD;
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
    string sql = "SELECT * FROM ADMIN;";
    sqlite3_exec(DB, sql.c_str(), callback, 0, &sqliteError);
    sqlite3_close(DB);
    if (!adminLoggedIn)
    {
        printErrorMessage("\nInvalid Credentials...\nPlease Try Again...\n");
    }
    return adminLoggedIn;
}
#endif