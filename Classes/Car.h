#include <iostream>
#include <string>
#include "../sqlite/sqlite3.h"

using namespace std;

class Car
{

private:
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
    void AddCar(string company, string model, string number, string seatingCapacity, string fuelType, string mileage, string condition, string driver, string accidentHistory, string pricePerKM)
    {
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
        exit = sqlite3_open("./Database/DataBase.db", &DB);
        if (exit)
        {
            cerr << "Error Opening DB " << sqlite3_errmsg(DB) << endl;
            cout << "Error Opening Database...\nTry Again Later" << endl;
            return;
        }
        cout << "Database Opened Successfully!" << endl;
        string sql = "CREATE TABLE IF NOT EXISTS CARS("
                     "ID              INT        NOT NULL, "
                     "CAPACITY        TEXT       NOT NULL, "
                     "FUELTYPE        TEXT       NOT NULL, "
                     "MILEAGE         INT        NOT NULL, "
                     "CONDITION       CHAR(50), "
                     "DRIVER          TEXT, "
                     "ACCIDENTHISTORY TEXT,"
                     "PRICEPERKM      REAL       NOT NULL );";
        char *sqliteError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        if (exit != SQLITE_OK)
        {
            cerr << "Error Creating Table" << sqlite3_errmsg(DB) << endl;
            cout << "Error Creating Table...\nTry Again Later" << endl;
            return;
        }
        cout << "Table Created Successfully..." << endl;
        sql = "INSERT INTO CARS VALUES(" + to_string(1) + ", '" + this->seatingCapacity + "', '" + this->fuelType + "', '" + this->mileage + "', '" + this->condition + "', '" + this->driver + "', '" + this->accidentHistory + "', '" + this->pricePerKM + "');";
        cout << sql << endl;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &sqliteError);
        if (exit != SQLITE_OK)
        {
            cerr << "Error Inserting into Table" << sqlite3_errmsg(DB) << endl;
            cout << "Error Inserting into Table...\nTry Again Later" << endl;
            return;
        }
        cout << "Insertion Successful..." << endl;
        sqlite3_close(DB);
    }
    void getCar()
    {
        cout << "--------------------------Car Details-----------------------------------" << endl;
        cout << "Car Name            : " << company + " " + model + " " + number << endl;
        cout << "Car Capacity        : " << seatingCapacity << endl;
        cout << "Car FuelType        : " << fuelType << endl;
        cout << "Car Mileage         : " << mileage << endl;
        cout << "Car Condition       : " << condition << endl;
        cout << "Car Driver          : " << driver << endl;
        cout << "Car AccidentHistory : " << accidentHistory << endl;
        cout << "Car PriccePerKM     : " << pricePerKM << endl;
    }
};