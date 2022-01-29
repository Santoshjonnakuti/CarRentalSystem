#include <iostream>
#include <string.h>
#include <unistd.h>
#include "Classes/Admin.h"
#include "Classes/RegisteredUser.h"
#include "Classes/GuestUser.h"
#include "Classes/Car.h"
#include "Utils/DataTypes.h"
#include "Utils/AdminUtils.h"
#include "Utils/Messages.h"

int main()
{

    Admin A;
    RegisteredUser R;
    GuestUser G;
    Car C;
    AdminDetails AD;
    int choice, car_id, updateChoice;
    Choice admin, registeredUser, guest;
    CarDataType CarDetails;
    while (true)
    {
        cout << "\n1. Login as Admin\n2. Login as Registered User\n3. Login as Guest\n4. Exit Application\n"
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
                cout << "\n1. Add New Car\n2. Get Car Details\n3. Update Car Details\n4. Logout\n"
                     << endl;
                cout << "Enter your Choice : ";
                cin >> admin.choice;
                switch (admin.choice)
                {
                case 1:
                    cout << "Enter Car Company : ";
                    getline(cin, CarDetails.company);
                    cout << "Enter Car Model : ";
                    getline(cin, CarDetails.model);
                    cout << "Enter Car Number : ";
                    getline(cin, CarDetails.number);
                    cout << "Enter Car Seating Capacity";
                    cin >> CarDetails.seatingCapacity;
                    cout << "Enter Car Fuel Type : ";
                    getline(cin, CarDetails.fuelType);
                    cout << "Enter Car Mileage : ";
                    cin >> CarDetails.mileage;
                    cout << "Enter Car Condition : ";
                    getline(cin, CarDetails.condition);
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
                    C.AddNewCar(CarDetails);
                    break;
                case 2:
                    cout << "\nEnter the Id of the Car : ";
                    cin >> car_id;
                    C.getCar(car_id);
                    break;
                case 3:
                    printInformation("\nChoose the Detail you want to Update :\n1.Name\n2.Capacity\n3.Fuel type\n4.Mileage\n5.Condition\n6.Driver\n7.Accident Hisotry\n8.Price Per KM\n9.Total Cars\n10.Cars Rented\n11.Cars Available");
                    cout << "Enter your Choice : ";
                    cin >> updateChoice;
                    cout << "\nEnter the Id of the Car : ";
                    cin >> car_id;
                    C.updateCar(updateChoice, to_string(car_id));
                    break;
                case 4:
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
            break;
        case 3:
            G.greet();
            break;
        case 4:
            cout << "Closing the Application..." << endl;
            return 0;
        default:
            cout << "\nInvalid Choice\n";
            break;
        }
    }
}