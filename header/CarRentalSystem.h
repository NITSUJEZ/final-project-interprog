#ifndef CARRENTALSYSTEM_H
#define CARRENTALSYSTEM_H

#include <vector>
#include <string>
#include "RentalCar.h"
#include "DiscountStrategy.h"

class CarRentalSystem {
private:
    std::vector<RentalCar*> cars;
    DiscountStrategy* discountStrategy;

    RentalCar* findCar(const std::string& make, const std::string& model, int year);
    int getValidIntegerInput(int minValue = 0, int maxValue = 10000);
    double getValidDoubleInput(double minValue = 0.0);

public:
    CarRentalSystem(DiscountStrategy* discountStrategy = new NoDiscount());

    void addCar();
    void displayAvailableCars() const;
    void changeCarRentalPrice();
    void removeCar();
    void rentCar();
    void returnCar();
    void setDiscountStrategy(DiscountStrategy* newStrategy);
    void toggleDiscount();
};

#endif
