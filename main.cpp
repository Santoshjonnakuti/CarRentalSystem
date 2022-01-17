#include <iostream>
#include "Admin.h"
#include "RegisteredUser.h"
#include "GuestUser.h"

int main()
{
    Admin A;
    RegisteredUser R;
    GuestUser G;
    A.greet();
    R.greet();
    G.greet();
}