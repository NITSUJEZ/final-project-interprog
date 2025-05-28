#include "DiscountStrategy.h"

double NoDiscount::applyDiscount(double amount) const {
    return amount;
}

double TenPercentDiscount::applyDiscount(double amount) const {
    return amount * 0.9;
}
