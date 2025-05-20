#include <iostream>
#include <vector>

using namespace std;

//Ito yung base class para sa kotse
class Car {
protected:
    string make, model;
    int year;

public:
    Car(string mk, string mdl, int yr) : make(mk), model(mdl), year(yr) {}
    virtual void display() const = 0;
    virtual string getCarDetails() const {
        return make + " " + model + " (" + to_string(year) + ")";
    }
};