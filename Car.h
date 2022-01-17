#include <iostream>
#include <string>

using namespace std;

class Car
{

private:
    int id;
    string name;
    string company;
    string model;
    string number;
    int seatingCapacity;
    string fuelType;
    string mileage;
    string condition;
    string driver;
    string accidentHistory;
    float pricePerKM;

public:
    void AddCar(string company, string model, string number, int seatingCapacity, string fuelType, string mileage, string condition, string driver, string accidentHistory, float pricePerKM)
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