#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int year;
    float speed;

public:
    void setModel(const string &m) 
	{
        model=m;
    }

    string getModel() const 
	{
        return model;
    }

    void setYear(int y) 
	{
        year = y;
    }

    int getYear() const 
	{
        return year;
    }

    void setSpeed(float s) 
	{
        speed = s;
    }

    float getSpeed() const 
	{
        return speed;
    }
};

int main() 
{
    Car myCar;
    string model;
    int year;
    float speed;

    cout<<"Enter Car Model: ";
    getline(cin, model);
    myCar.setModel(model);

    cout<<"Enter Car Year: ";
    cin>>year;
    myCar.setYear(year);

    cout<<"Enter Car Speed (in km/h): ";
    cin>>speed;
    myCar.setSpeed(speed);

    cout<<"\nCar Details:\n";
    cout<<"Car Model: "<<myCar.getModel()<<endl;
    cout<<"Car Year: "<<myCar.getYear()<<endl;
    cout<<"Car Speed: "<<myCar.getSpeed()<<" km/h"<<endl;
}

/*
Enter Car Model: 123
Enter Car Year: 2453
Enter Car Speed (in km/h): 12

Car Details:
Car Model: 123
Car Year: 2453
Car Speed: 12 km/h
*/