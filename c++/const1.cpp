#include <iostream>
using namespace std;

class FastFoodCafe {
    int id, rating, year, staff;
    string name, type, location;

public:
    FastFoodCafe() {
        id = rating = year = staff = 0;
        name = type = location = "";
    }

    void input() {
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Type: "; cin >> type;
        cout << "Rating: "; cin >> rating;
        cout << "Location: "; cin >> location;
        cout << "Year: "; cin >> year;
        cout << "Staff: "; cin >> staff;
    }

    void display() {
        cout << "\nID: " << id << "\nName: " << name << "\nType: " << type
             << "\nRating: " << rating << " Star\nLocation: " << location
             << "\nYear: " << year << "\nStaff: " << staff << endl;
    }
};

int main() {
    int n;
    cout << "No. of cafes: ";
    cin >> n;

    FastFoodCafe cafes[n];
    for (int i = 0; i < n; i++) cafes[i].input();

    cout << "\n--- Cafe Info ---";
    for (int i = 0; i < n; i++) cafes[i].display();

    return 0;
}
