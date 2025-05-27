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

    public:
    CarRentalSystem(DiscountStrategy* discountStrategy = new NoDiscount())
        : discountStrategy(discountStrategy) {}

    //Adding a new car
    void addCar() {
        string make, model;
        int year;
        double rentalPricePerDay;

        cout << "Enter car brand: "; 
        cin >> make;
        if (make.empty()) {
            cout << "Brand cannot be empty!" << endl;
            return;
        }

        cout << "Enter car model: ";
        cin >> model;
        if (model.empty()) {
            cout << "Model cannot be empty!" << endl;
            return;
        }

        cout << "Enter car year (1886 to current year): ";
        year = getValidIntegerInput(1886, 2025);

        cout << "Enter rental price per day: $";
        rentalPricePerDay = getValidDoubleInput(0.01);

        auto car = new RentalCar(make, model, year, rentalPricePerDay);
        cars.push_back(car);
        cout << "Car added successfully!\n";
    }

    //Display available cars
    void displayAvailableCars() const {
        bool found = false;
        cout << "Available Cars for Rent:\n";
        for (const auto& car : cars) {
            if (car->isAvailable()) {
                car->display();
                found = true;
            }
        }
        if (!found) {
            cout << "No cars available for rent.\n";
        }
    }

    //Change car rental price 
    void changeCarRentalPrice() {
        string make, model;
        int year;
        double newPrice;

        cout << "Enter car brand: ";
        cin >> make;
        if (make.empty()) {
            cout << "Brand cannot be empty!" << endl;
            return;
        }

        cout << "Enter car model: ";
        cin >> model;
        if (model.empty()) {
            cout << "Model cannot be empty!" << endl;
            return;
        }

        cout << "Enter car year: ";
        year = getValidIntegerInput(1886, 2025);

        auto car = findCar(make, model, year);
        if (car) {
            cout << "Enter new rental price per day: $";
            newPrice = getValidDoubleInput(0.01);
            car->updateRentalPrice(newPrice);
            cout << "Updated rental price successfully.\n";
        } else {
            cout << "Car not found to update.\n";
        }
    }

    //Remove a car from the system
    void removeCar() {
        string make, model;
        int year;

        cout << "Enter car brand: ";  
        cin >> make;
        if (make.empty()) {
            cout << "Brand cannot be empty!" << endl;
            return;
        }

        cout << "Enter car model: ";
        cin >> model;
        if (model.empty()) {
            cout << "Model cannot be empty!" << endl;
            return;
        }

        cout << "Enter car year: ";
        year = getValidIntegerInput(1886, 2025);

        auto car = findCar(make, model, year);
        if (car) {
            //Find car using loop then erase
            auto it = cars.begin();
            for (; it != cars.end(); ++it) {
                if (*it == car) {
                    break;
                }
            }

            //Pag nakita na yung car
            if (it != cars.end()) {
                cars.erase(it);
                cout << "Car removed successfully.\n";
            }
        } else {
            cout << "Car not found to remove.\n";
        }
    }

    //Rent a car
    void rentCar() {
        string make, model;
        int year, days;

        cout << "Enter car brand: ";  
        cin >> make;
        if (make.empty()) {
            cout << "Brand cannot be empty!" << endl;
            return;
        }

        cout << "Enter car model: ";
        cin >> model;
        if (model.empty()) {
            cout << "Model cannot be empty!" << endl;
            return;
        }

        cout << "Enter car year: ";
        year = getValidIntegerInput(1886, 2025);

        cout << "Enter number of days to rent: ";
        days = getValidIntegerInput(1);

        auto car = findCar(make, model, year);
        if (car && car->isAvailable()) {
            car->updateAvailability(false);
            double totalAmount = discountStrategy->applyDiscount(car->getRentalPrice() * days);
            cout << "\nReceipt:\n";
            cout << "Car rented: " << car->getCarDetails() << " for " << days << " days\n";
            cout << "Total Rental Charges: $" << totalAmount << "\n";
        } else {
            cout << "Car not available or not found.\n";
        }
    }

    //Return a car
    void returnCar() {
        string make, model;
        int year;

        cout << "Enter car brand: ";  
        cin >> make;
        if (make.empty()) {
            cout << "Brand cannot be empty!" << endl;
            return;
        }

        cout << "Enter car model: ";
        cin >> model;
        if (model.empty()) {
            cout << "Model cannot be empty!" << endl;
            return;
        }

        cout << "Enter car year: ";
        year = getValidIntegerInput(1886, 2025);

        auto car = findCar(make, model, year);
        if (car) {
            car->updateAvailability(true);
            cout << "\nCar returned successfully.\n";
        } else {
            cout << "Car not found for return.\n";
        }
    }

    //Set discount strategy
    void setDiscountStrategy(DiscountStrategy* newStrategy) {
        discountStrategy = newStrategy;
    }

    //Toggle discount (turn off 10% discount)
    void toggleDiscount() {
        if (dynamic_cast<TenPercentDiscount*>(discountStrategy)) {
            discountStrategy = new NoDiscount(); //Turn off discount
            cout << "Discount has been turned off.\n";
        } else {
            discountStrategy = new TenPercentDiscount(); //Apply 10% discount
            cout << "10% Discount has been applied.\n";
        }
    }
};

int main() {
    CarRentalSystem system;
    int choice;

    do {
        cout << "\n--- Car Rental System Menu ---\n";
        cout << "1. Add Car\n";
        cout << "2. Display Available Cars\n";
        cout << "3. Rent Car\n";
        cout << "4. Return Car\n";
        cout << "5. Remove Car\n";
        cout << "6. Change Car Rental Price\n";  
        cout << "7. Apply 10% Discount\n";
        cout << "8. Turn Off Discount\n";  
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addCar();
                break;
            case 2:
                system.displayAvailableCars();
                break;
            case 3:
                system.rentCar();
                break;
            case 4:
                system.returnCar();
                break;
            case 5:
                system.removeCar();
                break;
            case 6:
                system.changeCarRentalPrice();  
                break;
            case 7:
                system.setDiscountStrategy(new TenPercentDiscount());
                cout << "Discount strategy set to 10% off.\n";
                break;
            case 8:
                system.toggleDiscount();  
                break;
            case 9:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
