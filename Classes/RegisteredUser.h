#ifndef REGISTEREDUSER_H
#define REGISTEREDUSER_H

#include <iostream>
#include <string>
#include "../sqlite/sqlite3.h"
#include "User.h"

using namespace std;

int totalRegisteredUsers;

static int getNoOfRUsers(void *data, int argc, char **argv, char **azColName)
{
    totalRegisteredUsers = atoi(argv[0]);
    return totalRegisteredUsers;
}

class RegisteredUser : public User
{
private:
    string userName;
    string password;
    int totalRUsers;

public:
    void greet()
    {
        cout << "Hello World from Registered User" << endl;
    }
    void getTotalRegisteredUsers()
    {
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
        string sql = "SELECT * FROM NOOFREGISTEREDUSERS;";
        sqlite3_exec(DB, sql.c_str(), getNoOfRUsers, 0, &sqliteError);
        totalRUsers = totalRegisteredUsers;
        sqlite3_close(DB);
        return;
    }
    void addRegisteredUser(RegisteredUserDataType RUData)
    {
        getTotalRegisteredUsers();
        sqlite3 *DB;
        int exit = 0;
        char *sqliteError;
        RUData.Data.id = to_string(totalRUsers + 1);
        exit = sqlite3_open("./Database/DataBase.db", &DB);
        if (exit)
        {
            printErrorMessage("\nError Opening Database...\nTry Again Later\n");
            return;
        }
        printSuccessMessage("\nDatabase Opened Successfully!\n");
        string sql = "INSERT INTO REGISTERED_USER VALUES('" + RUData.Data.id + "', '" + RUData.Data.name + "', '" + RUData.Data.mobileNumber + "', '" + RUData.Data.emailId + "', '" + RUData.Data.address + "', '" + RUData.userName + "', '" + RUData.password + "');";
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        if (exit != SQLITE_OK)
        {
            printErrorMessage("\nError Inserting into Table...\nTry Again Later\n");
            return;
        }
        printSuccessMessage("\nInsertion Successful...\n");
        sql = "UPDATE NOOFREGISTEREDUSERS SET TOTAL_REGISTERED_USERS=" + RUData.Data.id + " WHERE TOTAL_REGISTERED_USERS=" + to_string(totalRUsers);
        sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        sqlite3_close(DB);
    }
};

#endif