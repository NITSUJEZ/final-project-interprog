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

// Strategy design pattern for discount
class DiscountStrategy {
    public:
        virtual double applyDiscount(double amount) const = 0;
    };
    
    class NoDiscount : public DiscountStrategy {
    public:
        double applyDiscount(double amount) const override {
            return amount;
        }
    };
    
    class TenPercentDiscount : public DiscountStrategy {
    public:
        double applyDiscount(double amount) const override {
            return amount * 0.9;
        }
    };

//rantal system for car
class CarRentalSystem {
    private:
        vector<RentalCar*> cars;
        DiscountStrategy* discountStrategy;
    
        //func to find a car in the system
        RentalCar* findCar(const string& make, const string& model, int year) {
            for (auto& car : cars) {
                if (car->getCarDetails() == make + " " + model + " (" + to_string(year) + ")") {
                    return car;
                }
            }
            return nullptr;
        }

    //Get valid integer input with validation (important)
    int getValidIntegerInput(int minValue = 0, int maxValue = 10000) {
        int value;
        while (true) {
            cin >> value;
            if (cin.fail() || value < minValue || value > maxValue) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a valid number between " << minValue << " and " << maxValue << ": ";
            } else {
                break;
            }
        }
        return value;
    }


    //Double input with validation
    double getValidDoubleInput(double minValue = 0.0) {
        double value;
        while (true) {
            cin >> value;
            if (cin.fail() || value < minValue) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a valid number: ";
            } else {
                break;
            }
        }
        return value;
    }