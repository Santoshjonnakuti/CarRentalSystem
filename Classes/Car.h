#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include "../sqlite/sqlite3.h"
#include "../Utils/Messages.h"
#include "../Utils/DataTypes.h"
#include "../Database/DataBaseUtils.h"

using namespace std;
int i = 0;

static int getNoOfCars(void *data, int argc, char **argv, char **azColName)
{
    i = atoi(argv[0]);
    return i;
}
static int getCarDetails(void *data, int argc, char **argv, char **azColName)
{
    printCarDetails(argv);
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
    string totalNoOfCars;
    string noOfRentedCars;
    string noOfAvailableCars;

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
    void AddNewCar(CarDataType CarDetails)
    {
        getTotalCars();
        this->id = to_string(total_cars + 1);
        this->company = CarDetails.company;
        this->model = CarDetails.model;
        this->number = CarDetails.number;
        this->seatingCapacity = CarDetails.seatingCapacity;
        this->fuelType = CarDetails.fuelType;
        this->mileage = CarDetails.mileage;
        this->condition = CarDetails.condition;
        this->driver = CarDetails.driver;
        this->accidentHistory = CarDetails.accidentHistory;
        this->pricePerKM = CarDetails.pricePerKM;
        this->totalNoOfCars = CarDetails.totalNoOfCars;
        this->noOfRentedCars = CarDetails.noOfRentedCars;
        this->noOfAvailableCars = CarDetails.noOfAvailableCars;
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
        string sql = "INSERT INTO CARS VALUES('" + this->company + " " + this->model + " " + this->number + "', " + this->id + ", '" + this->seatingCapacity + "', '" + this->fuelType + "', '" + this->mileage + "', '" + this->condition + "', '" + this->driver + "', '" + this->accidentHistory + "', '" + this->pricePerKM + "', '" + this->totalNoOfCars + "', '" + this->noOfRentedCars + "', '" + this->noOfAvailableCars + "');";
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
        if (total_cars < car_id || car_id <= 0)
        {
            printErrorMessage("\nInvalid Car Id...\nUnable to Fetch Details...\n");
            sqlite3_close(DB);
            return;
        }
        string sql = "SELECT * FROM CARS WHERE ID=" + to_string(car_id);
        sqlite3_exec(DB, sql.c_str(), getCarDetails, 0, &sqliteError);
        sqlite3_close(DB);
    }
    void updateCar(int choice, string car_id)
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
            updateCarsTotal(car_id, newCarsRented);
            break;
        case 11:
            cout << "Enter Cars Available : ";
            cin >> newCarsAvailable;
            updateCarsTotal(car_id, newCarsAvailable);
            break;
        default:
            printErrorMessage("\nInvalid Choice\n");
            break;
        }
    }
};
#endif