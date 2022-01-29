#ifndef DATABASEUTILS_H
#define DATABASEUTILS_H

#include <iostream>
#include <string>
#include "../sqlite/sqlite3.h"
#include "../Utils/Messages.h"

using namespace std;

void updateCarName(string car_id, string newName)
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
    string sql = "UPDATE CARS SET NAME='" + newName + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nName Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Name...\nTry Again Later...\n");
    return;
}
void updateCarCapacity(string car_id, string newCapacity)
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
    string sql = "UPDATE CARS SET CAPACITY='" + newCapacity + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nSeating Capacity Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Seating Capacity...\nTry Again Later...\n");
    return;
}
void updateCarFuelType(string car_id, string newFuelType)
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
    string sql = "UPDATE CARS SET FUELTYPE='" + newFuelType + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nFuel Type Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Fuel Type...\nTry Again Later...\n");
    return;
}
void updateCarMileage(string car_id, string newMileage)
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
    string sql = "UPDATE CARS SET MILEAGE='" + newMileage + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nMileage Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Mileage...\nTry Again Later...\n");
    return;
}
void updateCarCondition(string car_id, string newCondition)
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
    string sql = "UPDATE CARS SET CONDITION='" + newCondition + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nCondition Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Condition...\nTry Again Later...\n");
    return;
}
void updateCarDriver(string car_id, string newDriver)
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
    string sql = "UPDATE CARS SET DRIVER='" + newDriver + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nDriver Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Driver...\nTry Again Later...\n");
    return;
}
void updateCarAccidentHistory(string car_id, string newAccidentHistory)
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
    string sql = "UPDATE CARS SET ACCIDENTHISTORY='" + newAccidentHistory + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nAccident History Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Accident History...\nTry Again Later...\n");
    return;
}
void updateCarPricePerKM(string car_id, string newPricePerKM)
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
    string sql = "UPDATE CARS SET PRICEPERKM='" + newPricePerKM + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nPrice Per KM Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Price Per KM...\nTry Again Later...\n");
    return;
}
void updateCarsTotal(string car_id, string newCarsTotal)
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
    string sql = "UPDATE CARS SET TOTAL_NO_OF_CARS='" + newCarsTotal + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nCars Total Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Cars Total...\nTry Again Later...\n");
    return;
}
void updateCarsRented(string car_id, string newCarsRented)
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
    string sql = "UPDATE CARS SET NO_OF_RENTED_cARS='" + newCarsRented + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nCars Rented Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Cars Rented...\nTry Again Later...\n");
    return;
}
void updateCarsAvailabel(string car_id, string newCarsAvailable)
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
    string sql = "UPDATE CARS SET NO_OF_AVAILABLE_CARS='" + newCarsAvailable + "' WHERE ID='" + car_id + "';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
    if (exit == SQLITE_OK)
    {
        printSuccessMessage("\nCars Available Updated Successfully...\n");
        return;
    }
    printErrorMessage("\nCannot Update Cars Available...\nTry Again Later...\n");
    return;
}

#endif