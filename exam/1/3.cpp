#include <iostream>
#include <string>
using namespace std;

class Device 
{
    private:
    string brand;
    float powerConsumption;

    public:
    void setBrand(const string &b)
	{
        brand=b;
    }

    void setPowerConsumption(float p) 
	{
        powerConsumption=p;
    }

    string getBrand() const
	{
        return brand;
    }

    float getPowerConsumption() const 
	{
        return powerConsumption;
    }
};

class Laptop : public Device 
{
    public:
    void display() 
	{
        cout<<"Laptop Brand: "<<getBrand()<<endl;
        cout<<"Power Consumption: "<<getPowerConsumption()<<" Watts"<<endl;
    }
};

class Smartphone : public Device 
{
    public:
    void display() 
	{
        cout<<"Smartphone Brand: "<<getBrand()<<endl;
        cout<<"Power Consumption: "<<getPowerConsumption()<<" Watts"<<endl;
    }
};

int main() 
{
    Laptop myLaptop;
    Smartphone mySmartphone;
    string laptopBrand;
    float laptopPowerConsumption;

    cout<<"Enter Laptop Brand: ";
    getline(cin, laptopBrand);
    myLaptop.setBrand(laptopBrand);

    cout<<"Enter Laptop Power Consumption (in Watts): ";
    string laptopPowerInput;
    getline(cin, laptopPowerInput);
    laptopPowerConsumption = stof(laptopPowerInput);
    myLaptop.setPowerConsumption(laptopPowerConsumption);

    string smartphoneBrand;
    float smartphonePowerConsumption;

    cout<<"Enter Smartphone Brand: ";
    getline(cin, smartphoneBrand);
    mySmartphone.setBrand(smartphoneBrand);

    cout << "Enter Smartphone Power Consumption (in Watts): ";
    string smartphonePowerInput;
    getline(cin, smartphonePowerInput);
    smartphonePowerConsumption=stof(smartphonePowerInput);
    mySmartphone.setPowerConsumption(smartphonePowerConsumption);

    cout << "\nDevice Information:" << endl;
    myLaptop.display();
    cout<<endl;
    mySmartphone.display();
}

/*
Enter Laptop Brand: dell
Enter Laptop Power Consumption (in Watts): 123
Enter Smartphone Brand: google
Enter Smartphone Power Consumption (in Watts): 12

Device Information:
Laptop Brand: dell
Power Consumption: 123 Watts

Smartphone Brand: google
Power Consumption: 12 Watts
*/