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
#include "Utils/GuestUserUtils.h"
#include "Utils/Messages.h"

int main()
{

    AdminDetails AD;
    Admin A;
    RegisteredUserDataType RUD;
    RegisteredUser R;
    GuestUserDataType GUD;
    GuestUser G;
    Car C;
    int choice, car_id, updateChoice;
    Choice admin, registeredUser, guestUser;
    CarDataType CarDetails;
    while (true)
    {
        cout << "\n1. Login as Admin\n2. Login as Registered User\n3. Login as Guest\n4. Register as User\n5. Know Your Booking Status (Guest)\n6. Exit Application\n"
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
            admin.LoggedIn = A.adminLogin(AD.userName, AD.password);
            AD.id = LoggedInAdminID;
            while (admin.LoggedIn)
            {
                cout << "\n1. View Dashboard\n2. Add New Car\n3. Get All Cars\n4. Get Car Details\n5. Update Car Details\n6. Manage Bookings\n7. Logout\n"
                     << endl;
                cout << "Enter your Choice : ";
                cin >> admin.choice;
                cin.clear();
                switch (admin.choice)
                {
                case 1:
                    A.adminDashboard();
                    break;
                case 2:
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
                case 3:
                    A.getAllCars(C);
                    break;
                case 4:
                    cout << "\nEnter the Id of the Car : ";
                    cin >> car_id;
                    A.getCar(car_id, C);
                    break;
                case 5:
                    printInformation("\nChoose the Detail you want to Update :\n1.Name\n2.Capacity\n3.Fuel type\n4.Mileage\n5.Condition\n6.Driver\n7.Accident Hisotry\n8.Price Per KM\n9.Total Cars\n10.Cars Rented\n11.Cars Available");
                    cout << "Enter your Choice : ";
                    cin >> updateChoice;
                    cout << "\nEnter the Id of the Car : ";
                    cin >> car_id;
                    A.updateCar(updateChoice, to_string(car_id), C);
                    break;
                case 6:
                    A.manageBookings();
                    break;
                case 7:
                    printSuccessMessage("\nAdmin Logout Successful...\n");
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
            cin >> RUD.userName;
            cout << "\nEnter Your Password : ";
            cin >> RUD.password;
            registeredUser.LoggedIn = R.registeredUserLogin(RUD);
            RUD.Data.id = LoggedInRegisteredUserID;
            while (registeredUser.LoggedIn)
            {
                cout << "\n1. Book a Car\n2. View Previous Bookings\n3. Cancel a Booking\n4. View You Details\n5. Reset Password\n6. Logout\n"
                     << endl;
                cout << "\nEnter Your Choice : ";
                cin >> registeredUser.choice;
                cin.ignore();
                switch (registeredUser.choice)
                {
                case 1:
                    R.registeredUserBookACar(RUD);
                    break;
                case 2:
                    R.registeredUserViewPreviousBookings(RUD);
                    break;
                case 3:
                    R.registeredUserCancelABooking(RUD);
                    break;
                case 4:
                    R.getRegisteredUserInformation(RUD);
                    break;
                case 5:
                    R.registeredUserResetPassword(RUD);
                    break;
                case 6:
                    printSuccessMessage("\nRegistered User Logout Successful...\n");
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
            cin.ignore();
            cout << "Enter Your Name : ";
            getline(cin, GUD.name);
            cout << "Enter Your Mobile Number : ";
            cin >> GUD.mobileNumber;
            guestUser.LoggedIn = G.addGuestUser(GUD);
            GUD.id = LoggedInGuestUserID;
            while (guestUser.LoggedIn)
            {
                cout << "\n1. Book a Car\n2. View You Details\n3. Logout\n"
                     << endl;
                cout << "\nEnter Your Choice : ";
                cin >> guestUser.choice;
                switch (guestUser.choice)
                {
                case 1:
                    G.guestUserBookACar(GUD);
                    break;
                case 2:
                    G.getGuestUserInformation(GUD);
                    break;
                case 3:
                    printSuccessMessage("\nGuest User Logout Successful...\n");
                    guestUser.LoggedIn = 0;
                    break;
                default:
                    printErrorMessage("\nInvalid Choice\n");
                    break;
                }
            }
            break;
        case 4:
            cin.ignore();
            cout << "Enter Your Name : ";
            getline(cin, RUD.Data.name);
            cout << "Enter Your Mobile Number : ";
            cin >> RUD.Data.mobileNumber;
            cout << "Enter Your Email Id[Used as Username] : ";
            cin >> RUD.Data.emailId;
            cin.ignore();
            RUD.userName = RUD.Data.emailId;
            cout << "Enter Your Address : ";
            getline(cin, RUD.Data.address);
            cout << "Enter Your Password : ";
            cin >> RUD.password;
            cin.ignore();
            printInformation("\nSecurity Question will be Used to Reset Your Password...\n");
            cout << "Enter a Security Question : ";
            getline(cin, RUD.Data.securityQuestion);
            cout << "Enter Security Question Answer : ";
            getline(cin, RUD.Data.securityQuestionAnswer);
            R.addRegisteredUser(RUD);
            break;
        case 5:
            G.guestUserKnowBookingStatus();
            break;
        case 6:
            printWarningMessage("\nClosing The Application...\n");
            printSuccessMessage("\nApplication Closed...\n");
            return 0;
        default:
            cout << "\nInvalid Choice\n";
            break;
        }
    }
}