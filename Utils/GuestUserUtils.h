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
CarBookingDataType GUCBD;
CarBookingFilterDataType GUCBFD;
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
    printGuestUserDetails(argv);
    guestUserLoggedIn = 1;
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
static int getGUCBookingId(void *data, int argc, char **argv, char **azColName)
{
    GUCBD.bookingId = to_string(atoi(argv[0]) + 1);
    return 0;
}
static int getGUCBookingPrice(void *data, int argc, char **argv, char **azColName)
{
    GUCBD.price = atoi(argv[0]) * GUCBD.distance + 1000;
    return 0;
}
static int getGUCBFilteredCars(void *data, int argc, char **argv, char **azColName)
{
    printCarDetails(argv);
    return 0;
}
void GUAddBooking(CarBookingDataType CBD)
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
    string sql = "INSERT INTO BOOKINGS VALUES('" + CBD.bookingId + "', '" + CBD.carId + "', '" + CBD.userId + "', '" + CBD.startDate + "', '" + CBD.startTime + "', '" + CBD.endDate + "', '" + CBD.endTime + "', '" + to_string(CBD.distance) + "', '" + to_string(CBD.price) + "', '" + CBD.bookingStatus + "', '" + CBD.pickUpAddress + "', '" + to_string(CBD.isGuest) + "');";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit != SQLITE_OK)
    {
        cout << sqliteError;
        printErrorMessage("\nCannot Book Right Now...\nPlease Try Again Later...\n");
        return;
    }
    printSuccessMessage("\nBooking Successful...\nBookin Id is " + CBD.bookingId + "\n");
    sql = "UPDATE ADMIN SET BOOKING_REQUESTS=BOOKING_REQUESTS + 1 WHERE ID='1';";
    sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    return;
}
#endif