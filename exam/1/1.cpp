#include <iostream>
#include <string>
using namespace std;

class Student 
{
private:
    string name;
    int rollNumber;

public:
    Student(string n, int r) : name(n), rollNumber(r) {}

    Student() : name(""), rollNumber(0) {}

    void display() 
	{
        cout<<"Name: "<<name<<", Roll Number: "<<rollNumber<<endl;
    }
};

int main() 
{
    const int numStudents=3;
    Student students[numStudents];

    for (int i=0; i<numStudents; i++) 
	{
        string name;
        int rollNumber;

        cout<<"Enter name for student: ";
        cin>>name;
        cout<<"Enter roll number for student: ";
        cin>>rollNumber;

        students[i] = Student(name, rollNumber);
    }

    cout << "\nStudent Details:\n";
    for (int i = 0; i < numStudents; i++) 
	{
        students[i].display();
    }
    
}
/*
Enter name for student: asdf
Enter roll number for student: 1
Enter name for student: ghjk
Enter roll number for student: 2
Enter name for student: lzxc
Enter roll number for student: 3

Student Details:
Name: asdf, Roll Number: 1
Name: ghjk, Roll Number: 2
Name: lzxc, Roll Number: 3
*/
