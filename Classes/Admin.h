#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>

using namespace std;

class Admin
{
private:
    string userName;
    string password;
    string name;
    bool isAdmin;

public:
    void greet()
    {
        cout << "Hello World from Admin" << endl;
    }
};

#endif