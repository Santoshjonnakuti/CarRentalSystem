#ifndef REGISTEREDUSER_H
#define REGISTEREDUSER_H

#include <iostream>
#include <string>
#include "../sqlite/sqlite3.h"
#include "../Utils/RegisteredUserUtils.h"
#include "User.h"

using namespace std;

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
        string sql = "SELECT count(ID) FROM REGISTERED_USER;";
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
        string sql = "INSERT INTO REGISTERED_USER VALUES('" + RUData.Data.id + "', '" + RUData.Data.name + "', '" + RUData.Data.mobileNumber + "', '" + RUData.Data.emailId + "', '" + RUData.Data.address + "', '" + RUData.userName + "', '" + RUData.password + "', '" + RUData.Data.securityQuestion + "', '" + RUData.Data.securityQuestionAnswer + "');";
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        if (exit != SQLITE_OK)
        {
            cout << sqliteError;
            printErrorMessage("\nError Inserting into Table...\nTry Again Later\n");
            return;
        }
        printSuccessMessage("\nInsertion Successful...\n");
        sqlite3_close(DB);
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
        string sql = "SELECT * FROM REGISTERED_USER WHERE ID='" + RU.Data.id + "';";
        sqlite3_exec(DB, sql.c_str(), RUDetails, 0, &sqliteError);
        sqlite3_close(DB);
        if (!registeredUserLoggedIn)
        {
            printErrorMessage("\nInvalid Credentials...\nPlease Try Again...\n");
        }
        return;
    }
    void registeredUserResetPassword(RegisteredUserDataType RU)
    {
        sqlite3 *DB;
        int exit = 0;
        char *sqliteError;
        string sql;
        exit = sqlite3_open("./Database/DataBase.db", &DB);
        if (exit)
        {
            printErrorMessage("\nError Opening Database...\nTry Again Later\n");
            return;
        }
        printSuccessMessage("\nDatabase Opened Successfully!\n");
        sql = "SELECT * FROM REGISTERED_USER WHERE ID='" + RU.Data.id + "';";
        sqlite3_exec(DB, sql.c_str(), RUResetPassword, 0, &sqliteError);
        printInformation("\nAnswer the Below Security Question\nTo Reset Your Password\n");
        string sAns, RURPNewPassword;
        cout << RURPD.sQuestion;
        getline(cin, sAns);
        if (!RURPD.sQAnswer.compare(sAns) == 0)
        {
            printErrorMessage("\nWrong Answer...\nPlease Try Again...\n");
            RURPD.sQuestion = "";
            RURPD.sQAnswer = "";
            sqlite3_close(DB);
            return;
        }
        cout << "Enter Your New Password : ";
        cin >> RURPNewPassword;
        RURPD.sQuestion = "";
        RURPD.sQAnswer = "";
        sql = "UPDATE REGISTERED_USER SET PASSWORD='" + RURPNewPassword + "' WHERE ID='" + RU.Data.id + "';";
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        if (exit != SQLITE_OK)
        {
            printErrorMessage("\nCannot Reset Password...\nTry Again Later...\n");
            sqlite3_close(DB);
            return;
        }
        printSuccessMessage("\nPassword Reset Successful...\n");
        sqlite3_close(DB);
    }
};

#endif