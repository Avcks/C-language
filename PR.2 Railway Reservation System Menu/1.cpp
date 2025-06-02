#include <iostream>
#include <string.h>
using namespace std;

class Train 
{
public:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    void inputTrainDetails() 
	{
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cout << "Enter Train Name: ";
        cin >> trainName;

        cout << "Enter Source: ";
        cin >> source;

        cout << "Enter Destination: ";
        cin >> destination;

        cout << "Enter Train Time: ";
        cin >> trainTime;
    }

    void displayTrainDetails() 
	{
        cout << "\nTrain Number: "<<trainNumber;
        cout << "\nTrain Name: "<<trainName;
        cout << "\nSource: "<<source;
        cout << "\nDestination: "<<destination;
        cout << "\nTrain Time: "<<trainTime<<endl;
    }
};

class RailwaySystem 
{
public:
    Train trains[100];
    int totalTrains=0;

    void addTrain() 
	{
        if (totalTrains<100) 
		{
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        }else{
            cout << "Train limit reached.\n";
        }
    }

    void displayAllTrains() 
	{
        if (totalTrains==0) 
		{
            cout << "No trains available.\n";
        }else{
            for (int i=0; i<totalTrains; i++) 
			{
                cout << "\nTrain "<<(i + 1)<<" details:";
                trains[i].displayTrainDetails();
            }
        }
    }

    void searchTrainByNumber(int number) 
	{
        for (int i=0; i<totalTrains; i++) 
		{
            if (trains[i].trainNumber==number) 
			{
                cout << "\nTrain found:\n";
                trains[i].displayTrainDetails();
            }
        }
        cout << "Train with number "<<number<<" not found.\n";
    }
};

int main() 
{
    RailwaySystem rs;
    int choice, number;

    while (choice != 4)
	{
        cout << "\n--- Railway System Menu ---";
        cout << "\n1. Add New Train Record";
        cout << "\n2. Display All Trains Records";
        cout << "\n3. Search Train by Number";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                rs.addTrain();
                break;
            case 2:
                rs.displayAllTrains();
                break;
            case 3:
                cout << "Enter Train Number to Search: ";
                cin >> number;
                rs.searchTrainByNumber(number);
                break;
            case 4:
                cout << "Goog bye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

/*

--- Railway System Menu ---
1. Add New Train Record
2. Display All Trains Records
3. Search Train by Number
4. Exit
Enter your choice: 1
Enter Train Number: 101
Enter Train Name: okhaexpress
Enter Source: surat
Enter Destination: mumbai
Enter Train Time: 10am

--- Railway System Menu ---
1. Add New Train Record
2. Display All Trains Records
3. Search Train by Number
4. Exit
Enter your choice: 1
Enter Train Number: 102
Enter Train Name: mumbaiexpress
Enter Source: mumbai
Enter Destination: surat
Enter Train Time: 11pm

--- Railway System Menu ---
1. Add New Train Record
2. Display All Trains Records
3. Search Train by Number
4. Exit
Enter your choice: 2

Train 1 details:
Train Number: 101
Train Name: okhaexpress
Source: surat
Destination: mumbai
Train Time: 10am

Train 2 details:
Train Number: 102
Train Name: mumbaiexpress
Source: mumbai
Destination: surat
Train Time: 11pm

--- Railway System Menu ---
1. Add New Train Record
2. Display All Trains Records
3. Search Train by Number
4. Exit
Enter your choice: 3
Enter Train Number to Search: 102

Train found:

Train Number: 102
Train Name: mumbaiexpress
Source: mumbai
Destination: surat
Train Time: 11pm
Train with number 102 not found.

--- Railway System Menu ---
1. Add New Train Record
2. Display All Trains Records
3. Search Train by Number
4. Exit
Enter your choice: 3
Enter Train Number to Search: 103
Train with number 103 not found.

--- Railway System Menu ---
1. Add New Train Record
2. Display All Trains Records
3. Search Train by Number
4. Exit
Enter your choice: 4
Goog bye!
*/
