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
        guestUserLoggedIn = 1;
        return 1;
    }
    void getGuestUserInformation(GuestUserDataType GU)
    {
        cout << GU.id << endl;
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
        string sql = "SELECT * FROM GUEST_USER WHERE ID='" + GU.id + "';";
        sqlite3_exec(DB, sql.c_str(), GUDetails, 0, &sqliteError);
        sqlite3_close(DB);
        if (!guestUserLoggedIn)
        {
            printErrorMessage("\nInvalid Credentials...\nPlease Try Again...\n");
        }
        return;
    }
    void guestUserBookACar(GuestUserDataType GU)
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
            cin >> GUCBFD.minNumberOfSeats;
            cout << "Enter fuel Type of the Car [Petrol/Diesel/CNG]: ";
            cin >> GUCBFD.fuelType;
            cout << "Enter min Mileage of Car : ";
            cin >> GUCBFD.minMileage;
            cout << "Enter max Price Per KM of Car : ";
            cin >> GUCBFD.maxPricePerKM;
            sql = "SELECT * FROM CARS WHERE CAPACITY >= '" + GUCBFD.minNumberOfSeats + "' AND MILEAGE >= '" + GUCBFD.minMileage + "' AND PRICEPERKM <= '" + GUCBFD.maxPricePerKM + "' AND FUELTYPE = '" + GUCBFD.fuelType + "';";
            exit = sqlite3_exec(DB, sql.c_str(), getGUCBFilteredCars, 0, &sqliteError);
            if (exit != SQLITE_OK)
            {
                printErrorMessage("\nUnable to Filter Now...\n");
                break;
            }
            printWarningMessage("\nDo You Want to Filter Again [Y/N]: ");
            cin >> isFiltering;
        }
        GUCBD.userId = GU.id;
        sql = "SELECT count(BOOKING_ID) FROM BOOKINGS;";
        sqlite3_exec(DB, sql.c_str(), getGUCBookingId, 0, &sqliteError);
        cout << "Enter the Card Id : ";
        cin >> GUCBD.carId;
        cout << "Enter the Start Date of Booking [DD/MM/YYYY] : ";
        cin >> GUCBD.startDate;
        cout << "Enter the Start Time of Bookin [HH:MM] : ";
        cin >> GUCBD.startTime;
        cout << "Enter the End Date of Booking [DD/MM/YYYY] : ";
        cin >> GUCBD.endDate;
        cout << "Enter the End Time of Booking [HH:MM] : ";
        cin >> GUCBD.endTime;
        cout << "Enter the Distance in KM : ";
        cin >> GUCBD.distance;
        cin.ignore();
        cout << "Enter Car Pick Up Address : ";
        getline(cin, GUCBD.pickUpAddress);
        GUCBD.bookingStatus = "PENDING";
        GUCBD.isGuest = 1;
        sql = "SELECT PRICEPERKM FROM CARS WHERE ID = '" + GUCBD.carId + "';";
        sqlite3_exec(DB, sql.c_str(), getGUCBookingPrice, 0, &sqliteError);
        printPriceBreakDown(GUCBD);
        char GUCBDCountinueBooking;
        cout << "Continue Booking [Y/N]: ";
        cin >> GUCBDCountinueBooking;
        if (GUCBDCountinueBooking == 'Y' || GUCBDCountinueBooking == 'y')
        {
            sqlite3_close(DB);
            GUAddBooking(GUCBD);
            return;
        }
        printErrorMessage("\nBooking Terminated...\n");
        sqlite3_close(DB);
    }
    void guestUserKnowBookingStatus()
    {
        string gID, bId;
        cout << "Enter Your User Id : ";
        cin >> gID;
        cout << "Enter Your Booking Id : ";
        cin >> bId;
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
        string sql = "SELECT * FROM BOOKINGS WHERE ISGUEST=1 AND BOOKING_USER_ID='" + gID + "' AND BOOKING_ID='" + bId + "';";
        sqlite3_exec(DB, sql.c_str(), GUKnowBookingStatus, 0, &sqliteError);
        if (!knowBookingStatusCheck)
        {
            printErrorMessage("\nInvalid Details...\nBooking Not Found...\n");
            return;
        }
        return;
    }
};
#endif