#include <iostream>
#include <string>
using namespace std;

// Base Class: Vehicle
class Vehicle {
protected:
    string registrationNumber;
    string ownerName;

public:
    Vehicle() {
        registrationNumber = "UNKNOWN";
        ownerName = "UNKNOWN";
        cout << "Vehicle default constructor called.\n";
    }

    Vehicle(string regNum, string owner) : registrationNumber(regNum), ownerName(owner) {
        cout << "Vehicle parameterized constructor called.\n";
    }

    void displayVehicleInfo() {
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
    }
};

// Independent Class for Insurance
class Insurance {
protected:
    string insuranceCompany;

public:
    Insurance(string company = "No Insurance") : insuranceCompany(company) {
        cout << "Insurance constructor called.\n";
    }

    void displayInsuranceInfo() {
        cout << "Insurance Company: " << insuranceCompany << endl;
    }
};

// Single Inheritance: Car ? Vehicle
class Car : public Vehicle {
protected:
    string model;

public:
    Car(string regNum, string owner, string modelName)
        : Vehicle(regNum, owner), model(modelName) {
        cout << "Car constructor called.\n";
    }

    void displayCarInfo() {
        displayVehicleInfo();
        cout << "Car Model: " << model << endl;
    }
};

// New Base Class: AircraftBase
class AircraftBase {
protected:
    string manufacturer;
    int maxAltitude;

public:
    AircraftBase(string make = "Generic", int altitude = 0)
        : manufacturer(make), maxAltitude(altitude) {
        cout << "AircraftBase constructor called.\n";
    }

    void displayAircraftBaseInfo() {
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Max Altitude: " << maxAltitude << " ft\n";
    }
};

// Hybrid Inheritance: Aircraft ? Vehicle, AircraftBase, Insurance
class Aircraft : public Vehicle, public AircraftBase, public Insurance {
protected:
    string aircraftType;

public:
    Aircraft(string regNum, string owner,
             string make, int altitude,
             string company, string type)
        : Vehicle(regNum, owner),
          AircraftBase(make, altitude),
          Insurance(company),
          aircraftType(type) {
        cout << "Aircraft constructor called.\n";
    }

    void displayAircraftInfo() {
        displayVehicleInfo();         // from Vehicle
        displayAircraftBaseInfo();    // from AircraftBase
        displayInsuranceInfo();       // from Insurance
        cout << "Aircraft Type: " << aircraftType << endl;
    }
};

// Main Program
int main() {
    cout << "\n--- Car Info ---\n";
    Car myCar("CAR123", "Alice", "Honda Civic");
    myCar.displayCarInfo();

    cout << "\n--- Aircraft Info ---\n";
    Aircraft myAircraft("AIR456", "Bob",
                        "Boeing", 41000,
                        "SkySafe", "Commercial Jet");
    myAircraft.displayAircraftInfo();
}
