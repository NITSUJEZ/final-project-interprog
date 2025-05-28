#ifndef RENTALCAR_H
#define RENTALCAR_H

#include "Car.h"
#include <iostream>

class RentalCar : public Car {
    double rentalPricePerDay;
    bool available;

public:
    RentalCar(std::string mk, std::string mdl, int yr, double price);
    void display() const override;
    bool isAvailable() const;
    void updateAvailability(bool status);
    double getRentalPrice() const;
    void updateRentalPrice(double newPrice);
};

#endif

