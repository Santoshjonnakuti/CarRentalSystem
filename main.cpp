#include <iostream>
#include <string.h>
#include <unistd.h>
#include "Classes/Admin.h"
#include "Classes/RegisteredUser.h"
#include "Classes/GuestUser.h"
#include "Classes/Car.h"
#include "Utils/DataTypes.h"
#include "Utils/AdminUtils.h"

int main()
{

    Admin A;
    RegisteredUser R;
    GuestUser G;
    Car C;
    AdminDetails AD;
    int choice;
    Choice admin, registeredUser, guest;
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
                cout << "\n1. Add Car\n2. Get Car\n3. Logout\n"
                     << endl;
                cout << "Enter your Choice : ";
                cin >> admin.choice;
                switch (admin.choice)
                {
                case 1:
                    C.AddCar("Mahindra", "Xylo", "AP05 DA 2345", "7", "Diesel", "18", "Excellent", "Anand", "No", "12.60");
                    break;
                case 2:
                    C.getCar();
                    break;
                case 3:
                    admin.LoggedIn = 0;
                    break;
                default:
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