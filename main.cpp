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
    A.greet();
    R.greet();
    G.greet();
    Car C;
    C.AddCar("Mahindra", "Xylo", "AP05 DA 2345", 7, "Diesel", "18", "Excellent", "Anand", "No", 12.60);
    C.getCar();
}