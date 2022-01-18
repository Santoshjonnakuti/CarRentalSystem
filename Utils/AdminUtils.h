#include <iostream>
#include <string>
#include <string.h>
#include "../sqlite/sqlite3.h"

int adminLoggedIn = 0;
string userName, password;
static int callback(void *data, int argc, char **argv, char **azColName)
{
    if (userName == argv[1] && password == argv[2])
    {
        cout << "Hello" << endl;
        adminLoggedIn = 1;
    }
    for (int i = 0; i < argc; i++)
    {

        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int adminLogin(string userName, string password)
{
    userName = userName;
    password = password;
    sqlite3 *DB;
    int exit = 0;
    char *sqliteError;
    exit = sqlite3_open("./Database/DataBase.db", &DB);
    if (exit)
    {
        cerr << "Error Opening DB " << sqlite3_errmsg(DB) << endl;
        cout << "Error Opening Database...\nTry Again Later" << endl;
        return 0;
    }
    cout << "Database Opened Successfully!" << endl;
    string sql = "SELECT * FROM ADMIN;";
    sqlite3_exec(DB, sql.c_str(), callback, 0, &sqliteError);
    sqlite3_close(DB);
    return 0;
}