#include <iostream>
#include <string.h> // For strcmp
using namespace std;

// Class for multiple inheritance (Flyingcar will use this)
class Aircraft 
{
public:
    int flightrange;
    Aircraft() 
    {
        
    }
};

// Base class for all vehicles
class Vehicle 
{
public:
    char vehicleID[50];
    char manufacturer[50];
    int model;
    int year;

    Vehicle() 
    {
        
    }

    void vehicledetails() 
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter Manufacturer: ";
        cin >> manufacturer; // Note: This won't accept spaces
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Year: ";
        cin >> year;
    }

    void display() 
    {
        cout << "Vehicle ID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
    }
};

// Single inheritance: Car inherits from Vehicle
class Car : public Vehicle 
{
public:
    void display() 
    {
        cout << "\nCar Details:\n";
        Vehicle::display();
        cout << endl;
    }
};

// Multilevel inheritance: Electriccar inherits from Car
class Electriccar : public Car 
{
public:
    int batterycapacity;

    Electriccar() 
    {
        
    }

    void vehicledetails() 
    {
        Vehicle::vehicledetails();
        cout << "Enter Battery Capacity (kWh): ";
        cin >> batterycapacity;
    }

    void display() 
    {
        cout << "\nElectric car Details:\n";
        Vehicle::display();
        cout << "\nBattery Capacity: " << batterycapacity << " kWh" << endl;
    }
};

// Multiple inheritance: Flyingcar inherits from Car and Aircraft
class Flyingcar : public Car, public Aircraft 
{
public:
    void vehicledetails() 
    {
        Vehicle::vehicledetails();
        cout << "Enter Flight Range (km): ";
        cin >> flightrange;
    }

    void display() 
    {
        cout << "\nFlyingcar Details:\n";
        Vehicle::display();
        cout << "\nFlight Range: " << flightrange << " km" << endl;
    }
};

// Hierarchical inheritance: Sportscar inherits from Car
class Sportscar : public Car 
{
public:
    int topspeed;
    Sportscar() 
    {
        
    }

    void vehicledetails() 
    {
        Vehicle::vehicledetails();
        cout << "Enter Top Speed (km/h): ";
        cin >> topspeed;
    }

    void display() 
    {
        cout << "\nSportscar Details:\n";
        Vehicle::display();
        cout << "\nTop Speed: " << topspeed << " km/h" << endl;
    }
};

// Hierarchical inheritance: Sedan inherits from Car
class Sedan : public Car 
{
public:
    void display() 
    {
        cout << "\nSedan Details:\n";
        Vehicle::display();
        cout << endl;
    }
};

// Hierarchical inheritance: SUV inherits from Car (same as Sedan)
class SUV : public Car 
{
public:
    void display() 
    {
        cout << "\nSUV Details:\n";
        Vehicle::display();
        cout << endl;
    }
};

// Class to manage all vehicles
class Vehiclesystem 
{
public:
    Car cars[100];
    Electriccar electricCars[100];
    Flyingcar flyingCars[100];
    Sportscar sportsCars[100];
    Sedan sedans[100];
    SUV suvs[100]; // Added array for SUVs
    int totalcars;
    int totalelectriccars;
    int totalflyingcars;
    int totalsportscars;
    int totalsedans;
    int totalsuvs; // Added counter for SUVs

    Vehiclesystem() 
    {
        totalcars = 0;
        totalelectriccars = 0;
        totalflyingcars = 0;
        totalsportscars = 0;
        totalsedans = 0;
        totalsuvs = 0; // Initialize counter for SUVs
    }

    void add() 
    {
        int type;
        cout << "Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): "; // Added SUV option
        cin >> type;

        if (type == 1 && totalcars < 100) 
        {
            cars[totalcars].vehicledetails();
            totalcars++;
        } 
        else if (type == 2 && totalelectriccars < 100) 
        {
            electricCars[totalelectriccars].vehicledetails();
            totalelectriccars++;
        } 
        else if (type == 3 && totalflyingcars < 100) 
        {
            flyingCars[totalflyingcars].vehicledetails();
            totalflyingcars++;
        } 
        else if (type == 4 && totalsportscars < 100) 
        {
            sportsCars[totalsportscars].vehicledetails();
            totalsportscars++;
        } 
        else if (type == 5 && totalsedans < 100) 
        {
            sedans[totalsedans].vehicledetails();
            totalsedans++;
        } 
        else if (type == 6 && totalsuvs < 100) // Added case for SUV
        {
            suvs[totalsuvs].vehicledetails();
            totalsuvs++;
        } 
        else 
        {
            cout << "Vehicle limit reached or invalid type.\n";
        }
    }

    void displayallvehicles() 
    {
        if (totalcars == 0 && totalelectriccars == 0 && totalflyingcars == 0 && totalsportscars == 0 && totalsedans == 0 && totalsuvs == 0) 
        {
            cout << "No vehicles available.\n";
        } 
        else 
        {
            for (int i = 0; i < totalcars; i++) 
            {
                cout << "\nVehicle " << (i + 1) << ":";
                cars[i].display();
            }
            for (int i = 0; i < totalelectriccars; i++) 
            {
                cout << "\nVehicle " << (i + 1 + totalcars) << ":";
                electricCars[i].display();
            }
            for (int i = 0; i < totalflyingcars; i++) 
            {
                cout << "\nVehicle " << (i + 1 + totalcars + totalelectriccars) << ":";
                flyingCars[i].display();
            }
            for (int i = 0; i < totalsportscars; i++) 
            {
                cout << "\nVehicle " << (i + 1 + totalcars + totalelectriccars + totalflyingcars) << ":";
                sportsCars[i].display();
            }
            for (int i = 0; i < totalsedans; i++) 
            {
                cout << "\nVehicle " << (i + 1 + totalcars + totalelectriccars + totalflyingcars + totalsportscars) << ":";
                sedans[i].display();
            }
            for (int i = 0; i < totalsuvs; i++) // Added loop for SUVs
            {
                cout << "\nVehicle " << (i + 1 + totalcars + totalelectriccars + totalflyingcars + totalsportscars + totalsedans) << ":";
                suvs[i].display();
            }
        }
    }

    void search(char id[50]) 
    {
        for (int i = 0; i < totalcars; i++) 
        {
            if (strcmp(cars[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                cars[i].display();
            }
        }
        for (int i = 0; i < totalelectriccars; i++) 
        {
            if (strcmp(electricCars[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                electricCars[i].display();
            }
        }
        for (int i = 0; i < totalflyingcars; i++) 
        {
            if (strcmp(flyingCars[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                flyingCars[i].display();
            }
        }
        for (int i = 0; i < totalsportscars; i++) 
        {
            if (strcmp(sportsCars[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                sportsCars[i].display();
            }
        }
        for (int i = 0; i < totalsedans; i++) 
        {
            if (strcmp(sedans[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                sedans[i].display();
            }
        }
        for (int i = 0; i < totalsuvs; i++) // Added loop for SUVs
        {
            if (strcmp(suvs[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                suvs[i].display();
            }
        }
			cout << "Vehicle with ID " << id << " not found.\n";
    }
};

int main() 
{
    Vehiclesystem v1;
    int ch;
    char id[50];

    while (ch != 4) 
    {
        cout << "\n--- Vehicle System Menu ---";
        cout << "\n1. Add New Vehicle Record";
        cout << "\n2. Display All Vehicles Records";
        cout << "\n3. Search Vehicle by ID";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) 
        {
            case 1:
                v1.add();
                break;
            case 2:
                v1.displayallvehicles();
                break;
            case 3:
                cout << "Enter Vehicle ID to Search: ";
                cin >> id;
                v1.search(id);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}


/*

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 1
Enter Vehicle ID: 12
Enter Manufacturer: ford
Enter Model: 1234
Enter Year: 2002

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 2
Enter Vehicle ID: 13
Enter Manufacturer: ford
Enter Model: 12345
Enter Year: 2004
Enter Battery Capacity (kWh): 123

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 3
Enter Vehicle ID: 14
Enter Manufacturer: ford
Enter Model: 123456
Enter Year: 2004
Enter Flight Range (km): 123

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 4
Enter Vehicle ID: 15
Enter Manufacturer: ford
Enter Model: 6789
Enter Year: 2007
Enter Top Speed (km/h): 300

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 5
Enter Vehicle ID: 16
Enter Manufacturer: ford
Enter Model: 2345
Enter Year: 2018

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 6
Enter Vehicle ID: 17
Enter Manufacturer: ford
Enter Model: 6789
Enter Year: 2017

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 2

Vehicle 1:
Car Details:
Vehicle ID: 12
Manufacturer: ford
Model: 1234
Year: 2002

Vehicle 2:
Electric car Details:
Vehicle ID: 13
Manufacturer: ford
Model: 12345
Year: 2004
Battery Capacity: 123 kWh

Vehicle 3:
Flyingcar Details:
Vehicle ID: 14
Manufacturer: ford
Model: 123456
Year: 2004
Flight Range: 123 km

Vehicle 4:
Sportscar Details:
Vehicle ID: 15
Manufacturer: ford
Model: 6789
Year: 2007
Top Speed: 300 km/h

Vehicle 5:
Sedan Details:
Vehicle ID: 16
Manufacturer: ford
Model: 2345
Year: 2018

Vehicle 6:
SUV Details:
Vehicle ID: 17
Manufacturer: ford
Model: 6789
Year: 2017

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 3
Enter Vehicle ID to Search: 17

Vehicle found:

SUV Details:
Vehicle ID: 17
Manufacturer: ford
Model: 6789
Year: 2017

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 3
Enter Vehicle ID to Search: 18
Vehicle with ID 18 not found.

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 4
Goodbye!
*/