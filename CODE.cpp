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

//derived class para sa RentalCar 
class RentalCar : public Car {
    double rentalPricePerDay;
    bool available;

public:
    RentalCar(string mk, string mdl, int yr, double price)
        : Car(mk, mdl, yr), rentalPricePerDay(price), available(true) {}

    void display() const override {
        cout << getCarDetails() << " - $" << rentalPricePerDay << "/day - "
             << (available ? "Available" : "Not Available") << endl;
    }

    bool isAvailable() const {
        return available;
    }

    void updateAvailability(bool status) {
        available = status;
    }

    double getRentalPrice() const {
        return rentalPricePerDay;
    }

    void updateRentalPrice(double newPrice) {
        rentalPricePerDay = newPrice;
    }
};

