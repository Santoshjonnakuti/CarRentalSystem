#ifndef GUESTUSER_H
#define GUESTUSER_H

#include <iostream>
#include <string>

using namespace std;

class GuestUser
{
private:
    string userName;
    string password;
    string name;
    bool isGuestUser;

public:
    void greet()
    {
        cout << "Hello World from GuestUser " << endl;
    }
};
#endif