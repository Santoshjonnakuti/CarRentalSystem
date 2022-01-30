#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>

using namespace std;

struct AdminDetails
{
    string id;
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
struct UserDataType
{
    string id;
    string name;
    string mobileNumber;
    string emailId;
    string address;
    string securityQuestion;
    string securityQuestionAnswer;
};
struct RegisteredUserDataType
{
    UserDataType Data;
    string userName;
    string password;
};
struct GuestUserDataType
{
    string id;
    string name;
    string mobileNumber;
};
struct RUResetPasswordDetailsType
{
    string sQuestion;
    string sQAnswer;
};
struct AdminDashboardDetailsType
{
    int noOfRegisteredUsers;
    int noOfGuestUsers;
    int totalNoOfBookings;
    int totalNoOfBookingsAccepted;
    int totalNoOfBookingsRejected;
    int totalNoOfBOokingsPending;
};
struct CarBookingDataType
{
    string bookingId;
    string carId;
    string userId;
    string startDate;
    string startTime;
    string endDate;
    string endTime;
    double distance;
    double price;
    string pickUpAddress;
    string bookingStatus;
};
struct CarBookingFilterDataType
{
    string minNumberOfSeats;
    string condition;
    string minPricePerKM;
    string maxPricePerKM;
    string minMileage;
    string fuelType;
};

#endif