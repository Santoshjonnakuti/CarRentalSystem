#include <iostream>
#include <string>
#include <string.h>
#include "../sqlite/sqlite3.h"

using namespace std;

int adminLoggedIn = 0;
string userName, password;
static int callback(void *data, int argc, char **argv, char **azColName)
{
    const char *uname = userName.c_str();
    const char *passwd = password.c_str();
    cout << uname << " " << passwd << endl;
    cout << argv[1] << " " << argv[2] << endl;
    if (strcmp(uname, argv[1]) == 0 && strcmp(passwd, argv[2]) == 0)
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