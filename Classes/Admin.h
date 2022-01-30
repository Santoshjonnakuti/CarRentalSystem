#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <string.h>
#include "../sqlite/sqlite3.h"
#include "../Utils/Messages.h"
#include "../Utils/DataTypes.h"
#include "../Utils/AdminUtils.h"
#include "../Database/DataBaseUtils.h"
#include "Car.h"

using namespace std;

class Admin
{
private:
    string userName;
    string password;
    string name;
    bool isAdmin;

public:
    void greet()
    {
        cout << "Hello World from Admin" << endl;
    }
    int adminLogin(string uN, string pD)
    {
        AUserName = AUserName + uN;
        APassword = APassword + pD;
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
        AUserName = "";
        APassword = "";
        return adminLoggedIn;
    }
    void adminDashboard()
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
        sqlite3_exec(DB, sql.c_str(), getAdminDashboardRU, 0, &sqliteError);
        sql = "SELECT count(ID) FROM GUEST_USER;";
        sqlite3_exec(DB, sql.c_str(), getAdminDashboardGU, 0, &sqliteError);
        sql = "SELECT count(BOOKING_ID) FROM BOOKINGS;";
        sqlite3_exec(DB, sql.c_str(), getAdminDashboardTB, 0, &sqliteError);
        sql = "SELECT count(BOOKING_ID) FROM BOOKINGS WHERE BOOKING_STATUS='ACCEPTED';";
        sqlite3_exec(DB, sql.c_str(), getAdminDashboardTBA, 0, &sqliteError);
        sql = "SELECT count(BOOKING_ID) FROM BOOKINGS WHERE BOOKING_STATUS='REJECTED';";
        sqlite3_exec(DB, sql.c_str(), getAdminDashboardTBR, 0, &sqliteError);
        ADashboardDetails.totalNoOfBOokingsPending = ADashboardDetails.totalNoOfBookings - (ADashboardDetails.totalNoOfBookingsAccepted +
                                                                                            ADashboardDetails.totalNoOfBookingsRejected);
        printAdminDashboard(ADashboardDetails);
        sqlite3_close(DB);
    }
    void getTotalCars(Car &C)
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
        string sql = "SELECT count(ID) FROM CARS;";
        sqlite3_exec(DB, sql.c_str(), getNoOfCars, 0, &sqliteError);
        C.total_cars = i;
        sqlite3_close(DB);
        return;
    }
    void AddNewCar(CarDataType CarDetails, Car &C)
    {
        getTotalCars(C);
        C.Data.id = to_string(C.total_cars + 1);
        C.Data.company = CarDetails.company;
        C.Data.model = CarDetails.model;
        C.Data.number = CarDetails.number;
        C.Data.seatingCapacity = CarDetails.seatingCapacity;
        C.Data.fuelType = CarDetails.fuelType;
        C.Data.mileage = CarDetails.mileage;
        C.Data.condition = CarDetails.condition;
        C.Data.driver = CarDetails.driver;
        C.Data.accidentHistory = CarDetails.accidentHistory;
        C.Data.pricePerKM = CarDetails.pricePerKM;
        C.Data.totalNoOfCars = CarDetails.totalNoOfCars;
        C.Data.noOfRentedCars = CarDetails.noOfRentedCars;
        C.Data.noOfAvailableCars = CarDetails.noOfAvailableCars;
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
        string sql = "INSERT INTO CARS VALUES('" + C.Data.company + " " + C.Data.model + " " + C.Data.number + "', " + C.Data.id + ", '" + C.Data.seatingCapacity + "', '" + C.Data.fuelType + "', '" + C.Data.mileage + "', '" + C.Data.condition + "', '" + C.Data.driver + "', '" + C.Data.accidentHistory + "', '" + C.Data.pricePerKM + "', '" + C.Data.totalNoOfCars + "', '" + C.Data.noOfRentedCars + "', '" + C.Data.noOfAvailableCars + "');";
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        if (exit != SQLITE_OK)
        {
            printErrorMessage("\nError Inserting into Table...\nTry Again Later\n");
            return;
        }
        printSuccessMessage("\nInsertion Successful...\n");
        sqlite3_close(DB);
    }
    void getCar(int car_id, Car &C)
    {
        getTotalCars(C);
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
        if (C.total_cars < car_id || car_id <= 0)
        {
            printErrorMessage("\nInvalid Car Id...\nUnable to Fetch Details...\n");
            sqlite3_close(DB);
            return;
        }
        string sql = "SELECT * FROM CARS WHERE ID=" + to_string(car_id);
        sqlite3_exec(DB, sql.c_str(), getCarDetails, 0, &sqliteError);
        sqlite3_close(DB);
    }
    void updateCar(int choice, string car_id, Car &C)
    {
        string newCompany, newModel, newNumber, newName;
        string newCapacity, newFuelType, newMileage, newCondition, newDriver, newAccidentHistory, newPricePerKM;
        string newCarsTotal, newCarsRented, newCarsAvailable;
        switch (choice)
        {
        case 1:
            cout << "Enter Car Company : ";
            cin >> newCompany;
            cout << "Enter Car Model : ";
            cin >> newModel;
            cout << "Enter Car Number : ";
            cin.ignore();
            getline(cin, newNumber);
            newName = newCompany + " " + newModel + " " + newNumber;
            updateCarName(car_id, newName);
            break;
        case 2:
            cout << "Enter Car Seating Capacity : ";
            cin >> newCapacity;
            updateCarCapacity(car_id, newCapacity);
            break;
        case 3:
            cout << "Enter Car Fuel Type : ";
            cin >> newFuelType;
            updateCarFuelType(car_id, newFuelType);
            break;
        case 4:
            cout << "Enter Car Mileage : ";
            cin >> newMileage;
            updateCarMileage(car_id, newMileage);
            break;
        case 5:
            cout << "Enter Car Condition : ";
            cin >> newCondition;
            updateCarCondition(car_id, newCondition);
            break;
        case 6:
            cout << "Enter Car Driver : ";
            cin >> newDriver;
            updateCarDriver(car_id, newDriver);
            break;
        case 7:
            cout << "Enter Car Accident History [Yes/No]: ";
            cin >> newAccidentHistory;
            updateCarAccidentHistory(car_id, newAccidentHistory);
            break;
        case 8:
            cout << "Enter Car Price Per KM : ";
            cin >> newPricePerKM;
            updateCarPricePerKM(car_id, newPricePerKM);
            break;
        case 9:
            cout << "Enter Cars Total : ";
            cin >> newCarsTotal;
            updateCarsTotal(car_id, newCarsTotal);
            break;
        case 10:
            cout << "Enter Cars Rented : ";
            cin >> newCarsRented;
            updateCarsRented(car_id, newCarsRented);
            break;
        case 11:
            cout << "Enter Cars Available : ";
            cin >> newCarsAvailable;
            updateCarsAvailabel(car_id, newCarsAvailable);
            break;
        default:
            printErrorMessage("\nInvalid Choice\n");
            break;
        }
    }
    void getAllCars(Car &C)
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
        sqlite3_close(DB);
    }
};

#endif