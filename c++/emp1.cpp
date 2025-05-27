#include<iostream>
using namespace std;
class employee
{
	public:
	int id;
	char name[30];
	int age;
	char role[30];
	int salary;
	char city[30];
	int experience;
	char company_name[30];
};
int main()
{
	employee e[5];
	
	for(int i=1; i<=5; i++)
	{
	cout << "Enter Id: ";
	cin >> 	e[i].id;
	
	cout << "Enter name: ";
	cin >> 	e[i].name;
	
	cout << "Enter age: ";
	cin >> 	e[i].age;
	
	cout << "Enter role: ";
	cin >> 	e[i].role;
	
	cout << "Enter salary: ";
	cin >> 	e[i].salary;
	
	cout << "Enter city: ";
	cin >> 	e[i].city;
	
	cout << "Enter experience: ";
	cin >> 	e[i].experience;
	
	cout << "Enter company_name: ";
	cin >> 	e[i].company_name;
	cout << endl;
	}
	
	for(int i=1; i<=5; i++)
	{
		cout << "Id of Employee " << i << " is: "<< e[i].id << endl;
		cout << "name of Employee " << i << " is: "<< e[i].name << endl;
		cout << "age of Employee " << i << " is: "<< e[i].age << endl;
		cout << "role of Employee " << i << " is: "<< e[i].role << endl;
		cout << "salary of Employee " << i << " is: "<< e[i].salary << endl;
		cout << "city of Employee " << i << " is: "<< e[i].city << endl;
		cout << "experience of Employee " << i << " is: "<< e[i].experience << endl;
		cout << "company_name of Employee " << i << " is: "<< e[i].company_name << endl << endl;
	}
}