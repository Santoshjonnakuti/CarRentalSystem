#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include "../sqlite/sqlite3.h"
#include "../Utils/Messages.h"
using namespace std;
int i = 0;

static int getNoOfCars(void *data, int argc, char **argv, char **azColName)
{
    i = atoi(argv[0]);
    return i;
}
static int getCarDetails(void *data, int argc, char **argv, char **azColName)
{
    printInformation("--------------------------Car Details-----------------------------------\nCar Name            : " + string("company") + " " + "model" + " " + "number" + "\nCar Capacity        : " + argv[1] + "\nCar FuelType        : " + argv[2] + "\nCar Mileage         : " + argv[3] + "\nCar Condition       : " + argv[4] + "\nCar Driver          : " + argv[5] + "\nCar AccidentHistory : " + argv[6] + "\nCar PriccePerKM     : " + argv[7] + "\n");
    return 0;
}
class Car
{

private:
    int total_cars;
    string id;
    string name;
    string company;
    string model;
    string number;
    string seatingCapacity;
    string fuelType;
    string mileage;
    string condition;
    string driver;
    string accidentHistory;
    string pricePerKM;

public:
    void getTotalCars()
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
        string sql = "SELECT * FROM NOOFCARS;";
        sqlite3_exec(DB, sql.c_str(), getNoOfCars, 0, &sqliteError);
        total_cars = i;
        sqlite3_close(DB);
        return;
    }
    void AddCar(string company, string model, string number, string seatingCapacity, string fuelType, string mileage, string condition, string driver, string accidentHistory, string pricePerKM)
    {
        getTotalCars();
        this->id = to_string(total_cars + 1);
        this->company = company;
        this->model = model;
        this->number = number;
        this->seatingCapacity = seatingCapacity;
        this->fuelType = fuelType;
        this->mileage = mileage;
        this->condition = condition;
        this->driver = driver;
        this->accidentHistory = accidentHistory;
        this->pricePerKM = pricePerKM;
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
        string sql = "CREATE TABLE IF NOT EXISTS CARS("
                     "ID              INT        NOT NULL, "
                     "CAPACITY        TEXT       NOT NULL, "
                     "FUELTYPE        TEXT       NOT NULL, "
                     "MILEAGE         INT        NOT NULL, "
                     "CONDITION       CHAR(50), "
                     "DRIVER          TEXT, "
                     "ACCIDENTHISTORY TEXT,"
                     "PRICEPERKM      REAL       NOT NULL );";
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        if (exit != SQLITE_OK)
        {
            printErrorMessage("\nError Creating Table...\nTry Again Later\n");

            return;
        }
        printSuccessMessage("\nTable Created Successfully...!\n");

        sql = "INSERT INTO CARS VALUES(" + this->id + ", '" + this->seatingCapacity + "', '" + this->fuelType + "', '" + this->mileage + "', '" + this->condition + "', '" + this->driver + "', '" + this->accidentHistory + "', '" + this->pricePerKM + "');";
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        if (exit != SQLITE_OK)
        {
            printErrorMessage("\nError Inserting into Table...\nTry Again Later\n");
            return;
        }
        printSuccessMessage("\nInsertion Successful...\n");
        sql = "UPDATE NOOFCARS SET TOTAL_CARS=" + this->id + " WHERE TOTAL_CARS=" + to_string(i);
        sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        sqlite3_close(DB);
    }
    void getCar(int car_id)
    {
        getTotalCars();
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
        if (total_cars < car_id)
        {
            printErrorMessage("\nInvalid Car Id...\nUnable to Fetch Details...\n");
            sqlite3_close(DB);
            return;
        }
        string sql = "SELECT * FROM CARS WHERE ID=" + to_string(car_id);
        sqlite3_exec(DB, sql.c_str(), getCarDetails, 0, &sqliteError);
        sqlite3_close(DB);
    }
};
#endif