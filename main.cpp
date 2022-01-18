#include <iostream>
#include "Admin.h"
#include "RegisteredUser.h"
#include "GuestUser.h"
#include "Car.h"

int main()
{
    Admin A;
    RegisteredUser R;
    GuestUser G;
    Car C;
    int choice, adminChoice, ad = 1;
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
            while (ad)
            {
                cout << "\n1. Add Car\n2. Get Car\n3. Logout\n"
                     << endl;
                cout << "Enter your Choice : ";
                cin >> adminChoice;
                switch (adminChoice)
                {
                case 1:
                    C.AddCar("Mahindra", "Xylo", "AP05 DA 2345", "7", "Diesel", "18", "Excellent", "Anand", "No", "12.60");
                    break;
                case 2:
                    C.getCar();
                    break;
                case 3:
                    ad = 0;
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