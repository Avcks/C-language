#include <iostream>
using namespace std;

const int MAX = 100;

// Parallel arrays to store train data
int trainNumbers[MAX];
string trainNames[MAX];
string sources[MAX];
string destinations[MAX];
string times[MAX];

int totalTrains = 0;

// Function to add a train
void addTrain() {
    if (totalTrains >= MAX) {
        cout << "Train list is full!\n";
        return;
    }

    cout << "Enter Train Number: ";
    cin >> trainNumbers[totalTrains];

    cout << "Enter Train Name (one word): ";
    cin >> trainNames[totalTrains];

    cout << "Enter Source (one word): ";
    cin >> sources[totalTrains];

    cout << "Enter Destination (one word): ";
    cin >> destinations[totalTrains];

    cout << "Enter Time (HH:MM): ";
    cin >> times[totalTrains];

    totalTrains++;
    cout << "Train added!\n";
}

// Function to display all trains
void displayAllTrains() {
    if (totalTrains == 0) {
        cout << "No trains available.\n";
        return;
    }

    for (int i = 0; i < totalTrains; i++) {
        cout << "\nTrain Number: " << trainNumbers[i] << endl;
        cout << "Train Name: " << trainNames[i] << endl;
        cout << "Source: " << sources[i] << endl;
        cout << "Destination: " << destinations[i] << endl;
        cout << "Time: " << times[i] << endl;
    }
}

// Function to search for a train
void searchTrain() {
    int searchNumber;
    cout << "Enter Train Number to search: ";
    cin >> searchNumber;

    bool found = false;
    for (int i = 0; i < totalTrains; i++) {
        if (trainNumbers[i] == searchNumber) {
            cout << "\nTrain Number: " << trainNumbers[i] << endl;
            cout << "Train Name: " << trainNames[i] << endl;
            cout << "Source: " << sources[i] << endl;
            cout << "Destination: " << destinations[i] << endl;
            cout << "Time: " << times[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Train not found!\n";
    }
}

// Main function with switch
int main() {
    int choice;

    do {
        cout << "\n--- Railway Menu ---\n";
        cout << "1. Add Train\n";
        cout << "2. Show All Trains\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTrain();
                break;
            case 2:
                displayAllTrains();
                break;
            case 3:
                searchTrain();
                break;
            case 4:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
