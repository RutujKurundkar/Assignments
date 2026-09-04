#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ==========================================
// 1. BASE CLASS: Vehicle
// ==========================================
class Vehicle {
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:
    Vehicle(const string& reg, const string& owner, int year, double km)
        : registrationNo(reg), ownerName(owner), yearOfManufacture(year), kmDriven(km) {
        cout << "[Vehicle Constructor] " << registrationNo << " : " << ownerName << endl;
    }

    virtual ~Vehicle() {
        cout << "[Vehicle Destructor] " << registrationNo << endl;
    }

    virtual double fuelCost(double kmToTravel) const = 0;   // Pure virtual
    virtual string vehicleType() const = 0;                 // Pure virtual

    virtual void describe() const {
        cout << left << setw(12) << registrationNo
             << setw(16) << vehicleType()
             << setw(20) << ownerName
             << fixed << setprecision(0) << kmDriven;
    }

    double getKmDriven() const { return kmDriven; }
    string getRegNo() const { return registrationNo; }
};

// ==========================================
// 2. DERIVED CLASS: Car
// ==========================================
class Car : public Vehicle {
public:
    Car(const string& reg, const string& owner, int year, double km)
        : Vehicle(reg, owner, year, km) {
        cout << "[Car Constructor] " << registrationNo << endl;
    }

    ~Car() override {
        cout << "[Car Destructor] " << registrationNo << endl;
    }

    string vehicleType() const override { return "Car"; }

    // Rates derived perfectly from assignment's expected output
    double fuelCost(double kmToTravel) const override {
        return kmToTravel * 5.655;
    }
};

// ==========================================
// 3. DERIVED CLASS: Truck
// ==========================================
class Truck : public Vehicle {
public:
    Truck(const string& reg, const string& owner, int year, double km)
        : Vehicle(reg, owner, year, km) {
        cout << "[Truck Constructor] " << registrationNo << endl;
    }

    ~Truck() override {
        cout << "[Truck Destructor] " << registrationNo << endl;
    }

    string vehicleType() const override { return "Truck"; }

    double fuelCost(double kmToTravel) const override {
        return kmToTravel * 12.45;
    }
};

// ==========================================
// 4. MULTILEVEL DERIVED CLASS: ElectricTruck
// ==========================================
class ElectricTruck : public Truck {
private:
    int batteryStatus;

public:
    ElectricTruck(const string& reg, const string& owner, int year, double km, int battery)
        : Truck(reg, owner, year, km), batteryStatus(battery) {
        cout << "[ElectricTruck Constructor] " << registrationNo << endl;
    }

    ~ElectricTruck() override {
        cout << "[ElectricTruck Destructor] " << registrationNo << endl;
    }

    string vehicleType() const override { return "Electric Truck"; }

    double fuelCost(double kmToTravel) const override {
        return kmToTravel * 1.9375;
    }

    int getBatteryStatus() const { return batteryStatus; }
};

// ==========================================
// 5. HIERARCHICAL DERIVED CLASS: Van
// ==========================================
class Van : public Vehicle {
public:
    Van(const string& reg, const string& owner, int year, double km)
        : Vehicle(reg, owner, year, km) {
        cout << "[Van Constructor] " << registrationNo << endl;
    }

    ~Van() override {
        cout << "[Van Destructor] " << registrationNo << endl;
    }

    string vehicleType() const override { return "Van"; }

    double fuelCost(double kmToTravel) const override {
        return kmToTravel * 7.50;
    }
};

// ==========================================
// PART C: Polymorphic Fleet Report Function
// ==========================================
void printFleetReport(const vector<Vehicle*>& fleet, double tripKm) {
    cout << "\n===== FLEET REPORT - Trip Distance: " << tripKm << " km =====" << endl;
    cout << left << setw(12) << "Reg"
         << setw(16) << "Type"
         << setw(20) << "Owner"
         << "Km Driven" << endl;

    for (const auto& vehicle : fleet) {
        vehicle->describe();
        cout << endl;
    }

    cout << "\n===== FUEL / CHARGE COST ESTIMATE =====" << endl;

    Vehicle* mostEfficient = nullptr;
    double minCost = 1e9; // Initialize to high value to track minimum

    for (const auto& vehicle : fleet) {
        double cost = vehicle->fuelCost(tripKm);

        cout << vehicle->getRegNo() << " (" << vehicle->vehicleType() << "): Rs. "
             << fixed << setprecision(2) << cost;

        // Custom contextual descriptions per type
        if (vehicle->vehicleType() == "Car") {
            cout << "  (Petrol)";
        }

        // Requirement 4: Identify ElectricTruck using dynamic_cast
        ElectricTruck* et = dynamic_cast<ElectricTruck*>(vehicle);
        if (et != nullptr) {
            cout << "  [Battery: " << et->getBatteryStatus() << "% charged]";
        }
        cout << endl;

        // Track most efficient vehicle
        if (cost < minCost) {
            minCost = cost;
            mostEfficient = vehicle;
        }
    }

    if (mostEfficient != nullptr) {
        cout << "\nMost Efficient Vehicle: " << mostEfficient->getRegNo()
             << " (" << mostEfficient->vehicleType() << ") - Rs. "
             << minCost << " for " << tripKm << " km" << endl;
    }
}

// ==========================================
// MAIN FUNCTION (Demonstrates Part B & C)
// ==========================================
int main() {
    // ---- PART B: Observing Stack Construction & Destruction Chain ----
    cout << "--- Part B Demonstration ---" << endl;
    {
        ElectricTruck stackTruck("V-ET001", "Green Logistics", 2024, 12000, 90);
        cout << "...scope ends..." << endl;
    }
    cout << "----------------------------\n" << endl;

    // ---- PART C: Polymorphic Fleet Array ----
    vector<Vehicle*> fleet;

    // Add 5 heap-allocated vehicles of mixed types
    fleet.push_back(new Car("KA01AA001", "Ramesh Kumar", 2020, 45200));
    fleet.push_back(new Truck("MH04BB002", "Shyam Logistics", 2018, 123500));
    fleet.push_back(new ElectricTruck("GJ07CC003", "Green Fleet Co", 2023, 89000, 85));
    fleet.push_back(new Van("DL03DD004", "Express Delivery", 2021, 31000));
    fleet.push_back(new Car("MH12EE005", "Ananya Sharma", 2022, 15400));

    // Run report for a 200km trip distance
    printFleetReport(fleet, 200.0);

    // ---- CLEANUP: Safe heap deallocation using virtual base destructors ----
    cout << "\n===== CLEANUP =====" << endl;
    for (auto* vehicle : fleet) {
        delete vehicle;
    }
    fleet.clear();

    return 0;
}
