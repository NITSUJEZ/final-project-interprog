#include "RentalCar.h"

RentalCar::RentalCar(std::string mk, std::string mdl, int yr, double price)
    : Car(mk, mdl, yr), rentalPricePerDay(price), available(true) {}

void RentalCar::display() const {
    std::cout << getCarDetails() << " - $" << rentalPricePerDay << "/day - "
              << (available ? "Available" : "Not Available") << std::endl;
}

bool RentalCar::isAvailable() const {
    return available;
}

void RentalCar::updateAvailability(bool status) {
    available = status;
}

double RentalCar::getRentalPrice() const {
    return rentalPricePerDay;
}

void RentalCar::updateRentalPrice(double newPrice) {
    rentalPricePerDay = newPrice;
}

