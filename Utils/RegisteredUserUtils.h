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
string LoggedInRegisteredUserID = "";
RUResetPasswordDetailsType RURPD;
CarBookingDataType RUCBD;
CarBookingFilterDataType RUCBFD;
int totalRegisteredUsers;

static int getNoOfRUsers(void *data, int argc, char **argv, char **azColName)
{
    totalRegisteredUsers = atoi(argv[0]);
    return totalRegisteredUsers;
}
static int RUcallback(void *data, int argc, char **argv, char **azColName)
{
    string uname = string(argv[5]);
    string passwd = string(argv[6]);
    if (RUUserName.compare(uname) == 0 && RUPassword.compare(passwd) == 0)
    {
        LoggedInRegisteredUserID = LoggedInRegisteredUserID + argv[0];
        printSuccessMessage("\nLoggedin as " + string(argv[1]) + " ...\n");
        registeredUserLoggedIn = 1;
    }
    return 0;
}
static int RUDetails(void *data, int argc, char **argv, char **azColName)
{
    printRegisteredUserDetails(argv);
    registeredUserLoggedIn = 1;
    return 0;
}
static int RUResetPassword(void *data, int argc, char **argv, char **azColName)
{
    RURPD.sQuestion += string(argv[7]);
    RURPD.sQAnswer += string(argv[8]);
    return 0;
}
static int getRUCBookingId(void *data, int argc, char **argv, char **azColName)
{
    RUCBD.bookingId = to_string(atoi(argv[0]) + 1);
    return 0;
}
static int getRUCBookingPrice(void *data, int argc, char **argv, char **azColName)
{
    RUCBD.price = atoi(argv[0]) * RUCBD.distance + 1000;
    return 0;
}
static int getRUCBFilteredCars(void *data, int argc, char **argv, char **azColName)
{
    printCarDetails(argv);
    return 0;
}
void addBooking(CarBookingDataType CBD)
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
    string sql = "INSERT INTO BOOKINGS VALUES('" + CBD.bookingId + "', '" + CBD.carId + "', '" + CBD.userId + "', '" + CBD.startDate + "', '" + CBD.startTime + "', '" + CBD.endDate + "', '" + CBD.endTime + "', '" + to_string(CBD.distance) + "', '" + to_string(CBD.price) + "', '" + CBD.bookingStatus + "', '" + CBD.pickUpAddress + "');";
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