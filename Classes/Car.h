#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include "../sqlite/sqlite3.h"
#include "../Utils/Messages.h"
#include "../Utils/DataTypes.h"
#include "../Database/DataBaseUtils.h"

using namespace std;

class Car
{

private:
    int total_cars;
    CarDataType Data;
    friend class Admin;

public:
};
#endif