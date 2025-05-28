#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

class DiscountStrategy {
public:
    virtual double applyDiscount(double amount) const = 0;
    virtual ~DiscountStrategy() = default;
};

class NoDiscount : public DiscountStrategy {
public:
    double applyDiscount(double amount) const override;
};

class TenPercentDiscount : public DiscountStrategy {
public:
    double applyDiscount(double amount) const override;
};

#endif
