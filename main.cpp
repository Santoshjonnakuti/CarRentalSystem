#include <iostream>
#include <string.h>
#include <unistd.h>
#include "Classes/Admin.h"
#include "Classes/RegisteredUser.h"
#include "Classes/GuestUser.h"
#include "Classes/Car.h"
#include "Utils/DataTypes.h"
#include "Utils/AdminUtils.h"
#include "Utils/RegisteredUserUtils.h"
#include "Utils/Messages.h"

int main()
{

    AdminDetails AD;
    Admin A;
    RegisteredUserDataType RU;
    RegisteredUser R;
    GuestUser G;
    Car C;
    int choice, car_id, updateChoice;
    Choice admin, registeredUser, guest;
    CarDataType CarDetails;
    while (true)
    {
        cout << "\n1. Login as Admin\n2. Login as Registered User\n3. Login as Guest\n4. Register as User\n5. Exit Application\n"
             << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            A.greet();
            AD.name = "CarRentalAdmin";
            cout << "Enter Username : ";
            cin >> AD.userName;
            cout << "Enter Password : ";
            cin >> AD.password;
            admin.LoggedIn = adminLogin(AD.userName, AD.password);
            while (admin.LoggedIn)
            {
                cout << "\n1. Add New Car\n2. Get All Cars\n3. Get Car Details\n4. Update Car Details\n5. Logout\n"
                     << endl;
                cout << "Enter your Choice : ";
                cin >> admin.choice;
                cin.clear();
                switch (admin.choice)
                {
                case 1:
                    cout << "Enter Car Company : ";
                    cin >> CarDetails.company;
                    cout << "Enter Car Model : ";
                    cin >> CarDetails.model;
                    cin.ignore();
                    cout << "Enter Car Number : ";
                    getline(cin, CarDetails.number);
                    cout << "Enter Car Seating Capacity : ";
                    cin >> CarDetails.seatingCapacity;
                    cout << "Enter Car Fuel Type : ";
                    cin >> CarDetails.fuelType;
                    cout << "Enter Car Mileage : ";
                    cin >> CarDetails.mileage;
                    cout << "Enter Car Condition : ";
                    cin >> CarDetails.condition;
                    cin.ignore();
                    cout << "Enter Car Driver Name : ";
                    getline(cin, CarDetails.driver);
                    cout << "Enter Car Accident History [Yes/No]: ";
                    cin >> CarDetails.accidentHistory;
                    cout << "Enter Car Price Per KM : ";
                    cin >> CarDetails.pricePerKM;
                    cout << "Enter Total Number of Cars : ";
                    cin >> CarDetails.totalNoOfCars;
                    cout << "Enter Total Number of Cars Rented : ";
                    cin >> CarDetails.noOfRentedCars;
                    cout << "Enter Totlal Number of Cars Available : ";
                    cin >> CarDetails.noOfAvailableCars;
                    A.AddNewCar(CarDetails, C);
                    break;
                case 2:
                    A.getAllCars(C);
                    break;
                case 3:
                    cout << "\nEnter the Id of the Car : ";
                    cin >> car_id;
                    A.getCar(car_id, C);
                    break;
                case 4:
                    printInformation("\nChoose the Detail you want to Update :\n1.Name\n2.Capacity\n3.Fuel type\n4.Mileage\n5.Condition\n6.Driver\n7.Accident Hisotry\n8.Price Per KM\n9.Total Cars\n10.Cars Rented\n11.Cars Available");
                    cout << "Enter your Choice : ";
                    cin >> updateChoice;
                    cout << "\nEnter the Id of the Car : ";
                    cin >> car_id;
                    A.updateCar(updateChoice, to_string(car_id), C);
                    break;
                case 5:
                    admin.LoggedIn = 0;
                    break;
                default:
                    printErrorMessage("\nInvalid Choice\n");
                    break;
                }
            }
            break;
        case 2:
            R.greet();
            cout << "\nEnter Your Username : ";
            cin >> RU.userName;
            cout << "\nEnter Your Password : ";
            cin >> RU.password;
            registeredUser.LoggedIn = registeredUserLogin(RU);
            while (registeredUser.LoggedIn)
            {
                cout << "\n1.Book a Car\n2.View Previous Bookings\n3.Cancel a Booking\n4.View You Details\n5.Logout\n"
                     << endl;
                cout << "\nEnter Your Choice : ";
                cin >> registeredUser.choice;
                switch (registeredUser.choice)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    getRegisteredUserInformation(RU);
                    break;
                case 5:
                    registeredUser.LoggedIn = 0;
                    break;
                default:
                    printErrorMessage("\nInvalid Choice\n");
                    break;
                }
            }
            break;
        case 3:
            G.greet();
            break;
        case 4:
            cin.ignore();
            cout << "Enter Your Name : ";
            getline(cin, RU.Data.name);
            cout << "Enter Your Mobile Number : ";
            cin >> RU.Data.mobileNumber;
            cout << "Enter Your Email Id[Used as Username] : ";
            cin >> RU.Data.emailId;
            cin.ignore();
            RU.userName = RU.Data.emailId;
            cout << "Enter Your Address : ";
            getline(cin, RU.Data.address);
            cout << "Enter Your Password : ";
            cin >> RU.password;
            R.addRegisteredUser(RU);
            break;
        case 5:
            cout << "Closing the Application..." << endl;
            return 0;
        default:
            cout << "\nInvalid Choice\n";
            break;
        }
    }
}