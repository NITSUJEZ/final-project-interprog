#include "Car.h"

Car::Car(std::string mk, std::string mdl, int yr) : make(mk), model(mdl), year(yr) {}

std::string Car::getCarDetails() const {
    return make + " " + model + " (" + std::to_string(year) + ")";
}
