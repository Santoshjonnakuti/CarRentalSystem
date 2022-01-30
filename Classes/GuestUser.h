#ifndef GUESTUSER_H
#define GUESTUSER_H

#include <iostream>
#include <string>
#include "User.h"
#include "../Utils/GuestUserUtils.h"

using namespace std;

class GuestUser : public User
{
private:
    int totalGUsers;
    string userName;
    string password;

public:
    void greet()
    {
        cout << "Hello World from GuestUser " << endl;
    }
    void getTotalGuestUsers()
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
        string sql = "SELECT count(ID) FROM GUEST_USER;";
        sqlite3_exec(DB, sql.c_str(), getNoOfGUsers, 0, &sqliteError);
        totalGUsers = totalGuestUsers;
        sqlite3_close(DB);
        return;
    }
    int addGuestUser(GuestUserDataType GUData)
    {
        getTotalGuestUsers();
        sqlite3 *DB;
        int exit = 0;
        char *sqliteError;
        GUData.id = to_string(totalGUsers + 1);
        exit = sqlite3_open("./Database/DataBase.db", &DB);
        if (exit)
        {
            printErrorMessage("\nError Opening Database...\nTry Again Later\n");
            return 0;
        }
        printSuccessMessage("\nDatabase Opened Successfully!\n");
        string sql = "INSERT INTO GUEST_USER VALUES('" + GUData.id + "', '" + GUData.name + "', '" + GUData.mobileNumber + "');";
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        if (exit != SQLITE_OK)
        {
            printErrorMessage("\nError Inserting into Table...\nTry Again Later\n");
            return 0;
        }
        printSuccessMessage("\nInsertion Successful...\n");
        printSuccessMessage("\nLogged In as Guest User...\n");
        printInformation("\nYour User Id is " + GUData.id + "..\nUse this Id to Know Your Booking Status of Car...\n");
        sqlite3_close(DB);
        return 1;
    }
    void getGuestUserInformation(GuestUserDataType GU)
    {
        GUId = GUId + GU.id;
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
        string sql = "SELECT * FROM GUEST_USER;";
        sqlite3_exec(DB, sql.c_str(), GUDetails, 0, &sqliteError);
        sqlite3_close(DB);
        if (!guestUserLoggedIn)
        {
            printErrorMessage("\nInvalid Credentials...\nPlease Try Again...\n");
        }
        return;
    }
};
#endif