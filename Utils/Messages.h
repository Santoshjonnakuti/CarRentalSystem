#ifndef MESSAGES_H
#define MESSAGES_H
#include <iostream>
#include <string>
#include "DataTypes.h"

using namespace std;

void printErrorMessage(string errorMessage)
{
    string error = "\033[1;31m" + errorMessage + "\033[0m\n";
    cout << error << endl;
}
void printSuccessMessage(string successMessage)
{
    string success = "\033[1;32m" + successMessage + "\033[0m\n";
    cout << success << endl;
}
void printWarningMessage(string warningMessage)
{
    string warning = "\033[1;33m" + warningMessage + "\033[0m\n";
    cout << warning << endl;
}
void printInformation(string informationMessage)
{
    string information = "\033[1;34m" + informationMessage + "\033[0m\n";
    cout << information << endl;
}
void printCarDetails(char **argv)
{
    printInformation("--------------------------Car Details-----------------------------------\nCar Name            : " + string(argv[0]) + "\nCar Capacity        : " + argv[2] + "\nCar FuelType        : " + argv[3] + "\nCar Mileage         : " + argv[4] + "\nCar Condition       : " + argv[5] + "\nCar Driver          : " + argv[6] + "\nCar AccidentHistory : " + argv[7] + "\nCar PriccePerKM     : " + argv[8] +
                     "\nCar Total           : " + argv[9] + "\nCar Rented          : " + argv[10] + "\nCar Available       : " + argv[11] + "\nCar ID              : " + argv[1] + "\n");
    return;
}
void printRegisteredUserDetails(char **argv)
{
    printInformation("--------------------------User Details----------------------------------\nUser Name            : " + string(argv[1]) + "\nUser Mobile Number   : " + argv[2] + "\nUser Email Id        : " + argv[3] + "\nUser Address         : " + argv[4] + "\nUser Username        : " + argv[5] + "\nUser Password        : " + argv[6] + "\n");
    return;
}
void printGuestUserDetails(char **argv)
{
    printInformation("------------------------Guest User Details------------------------------\nUser Name            : " + string(argv[1]) + "\nUser Mobile Number   : " + argv[2] + "\nUser Id              : " + argv[0] + "\n");
    return;
}
void printAdminDashboard(AdminDashboardDetailsType ADDT)
{
    printInformation("-------------------------Admin Dashboard--------------------------------\nTotal No of Registered Users  : " + to_string(ADDT.noOfRegisteredUsers) + "\nTotal No of Guest Users       : " + to_string(ADDT.noOfGuestUsers) + "\nTotal No of Bookings          : " + to_string(ADDT.totalNoOfBookings) + "\nTotal No of Bookings Accepted : " + to_string(ADDT.totalNoOfBookingsAccepted) + "\nTotal No of Bookings Rejected : " + to_string(ADDT.totalNoOfBookingsRejected) + "\nTotal No of Bookings Pending  : " + to_string(ADDT.totalNoOfBOokingsPending) + "\n");
}
void printPriceBreakDown(CarBookingDataType CBD)
{
    printInformation("-------------------------Price Breakdown--------------------------------\nTravel Charges  : " + to_string(CBD.price - 1000) + "\nService Charges : 1000\nTotal Charges   : " + to_string(CBD.price) + "\n");
}
void printBookingDetails(char **argv)
{
    printInformation("-------------------------Previous Bookings------------------------------\nBooking ID             : " + string(argv[0]) + "\nBooking Car ID         : " + string(argv[1]) + "\nBooking Start Date     : " + string(argv[3]) + "\nBooking Start Time     : " + string(argv[4]) + "\nBooking End Date       : " + string(argv[5]) + "\nBooking End Time       : " + string(argv[6]) + "\nBooking Distance       : " + string(argv[7]) + "\nBooking Price          : " + string(argv[8]) + "\nBooking Status         : " + string(argv[9]) + "\nBooking Pick Address   : " + string(argv[10]));
    return;
}
void printBooking(char **argv)
{
    printInformation("\nBooking ID             : " + string(argv[0]) + "\nBooking Car ID         : " + string(argv[1]) + "\nBooking Start Date     : " + string(argv[3]) + "\nBooking Start Time     : " + string(argv[4]) + "\nBooking End Date       : " + string(argv[5]) + "\nBooking End Time       : " + string(argv[6]) + "\nBooking Distance       : " + string(argv[7]) + "\nBooking Price          : " + string(argv[8]) + "\nBooking Status         : " + string(argv[9]) + "\nBooking Pick Address   : " + string(argv[10]));
    return;
}
#endif