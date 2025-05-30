#include <iostream>
#include <string.h>
using namespace std;

class companies
{
  public:
    int id;
    char name[50];
    int staff_quantity;
    int revenue;
    int import_raw_diamonds;
    int export_raw_diamonds;
    static char ceo[50];
    
//    void setdata()
//	{
//		cout<<"Enter Id: ";
//		cin>>id;
//		
//		cout<<"Enter name: ";
//		cin>>name;
//		
//		cout<<"Enter staff quantity: ";
//		cin>>staff_quantity;
//		
//		cout<<"Enter revenue: ";
//		cin>>revenue;
//		
//		cout<<"Enter no. of imported raw diamonds: ";
//		cin>>import_raw_diamonds;
//		
//		cout<<"Enter no. of export_raw_diamonds: ";
//		cin>>export_raw_diamonds;
//		cout << endl;
//	}
	
	companies()
	{
		cout<<"Enter Id: ";
		cin>>id;
		
		cout<<"Enter name: ";
		cin>>name;
		
		cout<<"Enter staff quantity: ";
		cin>>staff_quantity;
		
		cout<<"Enter revenue: ";
		cin>>revenue;
		
		cout<<"Enter no. of imported raw diamonds: ";
		cin>>import_raw_diamonds;
		
		cout<<"Enter no. of export_raw_diamonds: ";
		cin>>export_raw_diamonds;
		cout << endl;
	}
	
	void getdata()
	{
		cout<<"Id: "<<id
			<<"\nname: "<<name
			<<"\nstaff_quantity: "<<staff_quantity
			<<"\nrevenue: "<<revenue
			<<"\nimport_raw_diamonds: "<<import_raw_diamonds
			<<"\nexport_raw_diamonds: "<<export_raw_diamonds
			<<"\nName of CEO: "<<ceo;
	}
};

char companies :: ceo[50]="Aum Sorathiya";

int main() 
{
	int n;
    cout << "How many no. of dimond company? ";
    cin >> n;
    
    companies c[100];
    for(int i=0; i<n; i++)
	{
        cout << "\nCompany " << i+1 << ":\n";
        c[i].setdata();
    }

    cout << "\n--- Company Details ---\n";
    for (int i=0; i<n; i++)
	{
        cout<<endl;
	}
}