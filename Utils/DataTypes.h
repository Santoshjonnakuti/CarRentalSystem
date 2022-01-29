#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>

using namespace std;

struct AdminDetails
{
    string name;
    string userName;
    string password;
};
struct Choice
{
    int choice;
    int LoggedIn = 0;
};
struct CarDataType
{
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
};
#endif