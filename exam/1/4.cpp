#include <iostream>
#include <string>
using namespace std;

class Device 
{
private:
    string brand;
    double powerConsumption;

public:
    void setBrand(const string &b) 
    {
        brand = b;
    }

    void setPowerConsumption(double power) 
    {
        powerConsumption = power;
    }

    string getBrand() const 
    {
        return brand;
    }

    double getPowerConsumption() const 
    {
        return powerConsumption;
    }

    virtual void display() const = 0;
    virtual double calculateDiscount() const = 0;
};

class Laptop : public Device 
{
public:
    void display() const override 
    {
        cout << "Device Type: Laptop" << endl;
        cout << "Brand: " << getBrand() << endl;
        cout << "Power Consumption: " << getPowerConsumption() << "W" << endl;
    }

    double calculateDiscount() const override 
    {
        return 0.10;
    }
};

class Smartphone : public Device 
{
public:
    void display() const override 
    {
        cout << "Device Type: Smartphone" << endl;
        cout << "Brand: " << getBrand() << endl;
        cout << "Power Consumption: " << getPowerConsumption() << "W" << endl;
    }

    double calculateDiscount() const override 
    {
        return 0.15;
    }
};

int main() 
{
    Laptop laptop;
    Smartphone smartphone;

    string brand;
    string powerInput;
    double power;

    cout << "Enter the brand of the Laptop: ";
    getline(cin, brand);
    laptop.setBrand(brand);

    cout << "Enter the power consumption of the Laptop (in Watts): ";
    getline(cin, powerInput);
    power = stod(powerInput);
    laptop.setPowerConsumption(power);

    cout << "Enter the brand of the Smartphone: ";
    getline(cin, brand);
    smartphone.setBrand(brand);

    cout << "Enter the power consumption of the Smartphone (in Watts): ";
    getline(cin, powerInput);
    power = stod(powerInput);
    smartphone.setPowerConsumption(power);

    Device* devices[2];
    devices[0] = &laptop;
    devices[1] = &smartphone;

    for (int i = 0; i < 2; ++i) 
    {
        devices[i]->display();
        cout << "Discount: " << devices[i]->calculateDiscount() * 100 << "%" << endl;
        cout << endl;
    }
}

/*
Enter the brand of the Laptop: dell
Enter the power consumption of the Laptop (in Watts): 21
Enter the brand of the Smartphone: google
Enter the power consumption of the Smartphone (in Watts): 32
Device Type: Laptop
Brand: dell
Power Consumption: 21W
Discount: 10%

Device Type: Smartphone
Brand: google
Power Consumption: 32W
Discount: 15%
*/