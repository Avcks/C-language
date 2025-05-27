#include<iostream>
using namespace std;
class car
{
	public:
	int id;
	char company_name[30];
	char color[30];
	int model;
	int release_year;
};
int main()
{
	car e[5];
	
	for(int i=1; i<=2; i++)
	{
	cout << "Enter Id: ";
	cin >> 	e[i].id;
	
	cout << "Enter company_name: ";
	cin >> 	e[i].company_name;
	
	cout << "Enter color: ";
	cin >> 	e[i].color;
	
	cout << "Enter model: ";
	cin >> 	e[i].model;
	
	cout << "Enter release_year: ";
	cin >> 	e[i].release_year;
	cout << endl;
	}
	
	for(int i=1; i<=2; i++)
	{
		cout << "Id of car " << i << " is: "<< e[i].id << endl;
		cout << "Company name of car " << i << " is: "<< e[i].company_name << endl;
		cout << "Color of car " << i << " is: "<< e[i].color << endl;
		cout << "Model of car " << i << " is: "<< e[i].model << endl;
		cout << "Release year of car " << i << " is: "<< e[i].release_year << endl << endl;
	}
}