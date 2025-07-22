#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <sstream>
#include <locale>

using namespace std;

// Abstract base class
class Vehicle {
protected:
    double baseRate;
    double taxRate;

public:
    Vehicle(double base, double tax) : baseRate(base), taxRate(tax) {}

    virtual double calculateTaxes() const = 0;
    virtual double calculateTotalCost() const = 0;

    virtual ~Vehicle() = default;
};

// NormalCar derived class
class NormalCar : public Vehicle {
public:
    NormalCar(double base) : Vehicle(base, 0.15) {}

    double calculateTaxes() const override {
        return taxRate * baseRate;
    }

    double calculateTotalCost() const override {
        return baseRate + calculateTaxes();
    }
};

// LuxuryCar derived class
class LuxuryCar : public Vehicle {
private:
    double eduty;

public:
    LuxuryCar(double base) : Vehicle(base, 0.20), eduty(30000) {}

    double calculateTaxes() const override {
        return (taxRate * baseRate) + eduty;
    }

    double calculateTotalCost() const override {
        return baseRate + calculateTaxes();
    }
};

// Helper function to format large numbers with commas (e.g., 2,300,000)
string formatWithCommas(double value) {
    stringstream ss;
    ss.imbue(locale(""));  // Use default locale for commas
    ss << fixed << setprecision(0) << value;
    return ss.str();
}

int main() {
    // Use smart pointers for automatic memory management
    unique_ptr<Vehicle> standardCar = make_unique<NormalCar>(500000);
    unique_ptr<Vehicle> luxuryCar = make_unique<LuxuryCar>(2000000);

    // Output results
    cout << "Standard Car Total Cost: " << formatWithCommas(standardCar->calculateTotalCost()) << endl;
    cout << "Luxury Car Total Cost: "   << formatWithCommas(luxuryCar->calculateTotalCost()) << endl;

    return 0;
}
