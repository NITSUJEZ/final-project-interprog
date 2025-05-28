#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
protected:
    string make;
    string model;
    int year;

public:
    Car(string mk, string mdl, int yr);
    virtual ~Car() = default;

    virtual void display() const = 0;
    virtual string getCarDetails() const = 0;
};

#endif // CAR_H

