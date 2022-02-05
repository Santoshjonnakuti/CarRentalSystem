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
        cout << RURPD.sQuestion + " ";
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
    void registeredUserBookACar(RegisteredUserDataType RU)
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
        string sql = "SELECT * FROM CARS;";
        sqlite3_exec(DB, sql.c_str(), getAllCarsDetails, 0, &sqliteError);
        printSuccessMessage("\nRemember Car Id of the required Car to Book...\n");
        printWarningMessage("\nDo You Want to Filter Cars According to Your Requirements [Y/N]: ");
        char isFiltering;
        cin >> isFiltering;
        while (isFiltering == 'Y' || isFiltering == 'y')
        {
            cout << "Enter min Seating Capacity : ";
            cin >> RUCBFD.minNumberOfSeats;
            cout << "Enter fuel Type of the Car [Petrol/Diesel/CNG]: ";
            cin >> RUCBFD.fuelType;
            cout << "Enter min Mileage of Car : ";
            cin >> RUCBFD.minMileage;
            cout << "Enter max Price Per KM of Car : ";
            cin >> RUCBFD.maxPricePerKM;
            sql = "SELECT * FROM CARS WHERE CAPACITY >= '" + RUCBFD.minNumberOfSeats + "' AND MILEAGE >= '" + RUCBFD.minMileage + "' AND PRICEPERKM <= '" + RUCBFD.maxPricePerKM + "' AND FUELTYPE = '" + RUCBFD.fuelType + "';";
            exit = sqlite3_exec(DB, sql.c_str(), getRUCBFilteredCars, 0, &sqliteError);
            if (exit != SQLITE_OK)
            {
                printErrorMessage("\nUnable to Filter Now...\n");
                break;
            }
            printWarningMessage("\nDo You Want to Filter Again [Y/N]: ");
            cin >> isFiltering;
        }
        RUCBD.userId = RU.Data.id;
        sql = "SELECT count(BOOKING_ID) FROM BOOKINGS;";
        sqlite3_exec(DB, sql.c_str(), getRUCBookingId, 0, &sqliteError);
        cout << "Enter the Card Id : ";
        cin >> RUCBD.carId;
        cout << "Enter the Start Date of Booking [DD/MM/YYYY] : ";
        cin >> RUCBD.startDate;
        cout << "Enter the Start Time of Bookin [HH:MM] : ";
        cin >> RUCBD.startTime;
        cout << "Enter the End Date of Booking [DD/MM/YYYY] : ";
        cin >> RUCBD.endDate;
        cout << "Enter the End Time of Booking [HH:MM] : ";
        cin >> RUCBD.endTime;
        cout << "Enter the Distance in KM : ";
        cin >> RUCBD.distance;
        cin.ignore();
        cout << "Enter Car Pick Up Address : ";
        getline(cin, RUCBD.pickUpAddress);
        RUCBD.bookingStatus = "PENDING";
        RUCBD.isGuest = 0;
        sql = "SELECT PRICEPERKM FROM CARS WHERE ID = '" + RUCBD.carId + "';";
        sqlite3_exec(DB, sql.c_str(), getRUCBookingPrice, 0, &sqliteError);
        printPriceBreakDown(RUCBD);
        char RUCBDCountinueBooking;
        cout << "Continue Booking [Y/N]: ";
        cin >> RUCBDCountinueBooking;
        if (RUCBDCountinueBooking == 'Y' || RUCBDCountinueBooking == 'y')
        {
            sqlite3_close(DB);
            RUAddBooking(RUCBD);
            return;
        }
        printErrorMessage("\nBooking Terminated...\n");
        sqlite3_close(DB);
    }
    void registeredUserViewPreviousBookings(RegisteredUserDataType RU)
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
        string sql = "SELECT * FROM BOOKINGS WHERE ISGUEST=0 AND BOOKING_USER_ID='" + RU.Data.id + "' ORDER BY BOOKING_ID DESC;";
        sqlite3_exec(DB, sql.c_str(), RUViewPreviousBookings, 0, &sqliteError);
        sqlite3_close(DB);
    }
    void registeredUserCancelABooking(RegisteredUserDataType RU)
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
        cout << "Enter the Id of the Booking : ";
        cin >> cancelBookingId;
        string sql = "SELECT * FROM BOOKINGS WHERE ISGUEST=0 AND BOOKING_ID='" + cancelBookingId + "';";
        sqlite3_exec(DB, sql.c_str(), RUCancelBooking, 0, &sqliteError);
        sqlite3_close(DB);
    }
};

#endif