#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int age;

public:
    Employee(const string& n, int a) : name(n), age(a) {}

    int absolute(int value) const {
        return (value < 0) ? -value : value;
    }

    int operator-(const Employee& other) {
        return absolute(age - other.age);
    }

    void display() const {
        cout << "Employee Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    string name1, name2;
    int age1, age2;

    cout << "Enter the name of the first employee: ";
    getline(cin, name1);
    cout << "Enter the age of the first employee: ";
    cin >> age1;

    cin.ignore();
    cout << "Enter the name of the second employee: ";
    getline(cin, name2);
    cout << "Enter the age of the second employee: ";
    cin >> age2;

    Employee emp1(name1, age1);
    Employee emp2(name2, age2);

    emp1.display();
    emp2.display();

    int ageDifference = emp1 - emp2;
    cout << "Age Difference: " << ageDifference << " years" << endl;
}


/*
Enter the name of the first employee: qwert
Enter the age of the first employee: 40
Enter the name of the second employee: yuiop
Enter the age of the second employee: 99
Employee Name: qwert, Age: 40
Employee Name: yuiop, Age: 99
Age Difference: 59 years
*/