#ifndef REGISTEREDUSER_H
#define REGISTEREDUSER_H

#include <iostream>
#include <string>

using namespace std;

class RegisteredUser
{
private:
    string userName;
    string password;
    string name;
    bool isRegisteredUser;

public:
    void greet()
    {
        cout << "Hello World from Registered User" << endl;
    }
};

#endif