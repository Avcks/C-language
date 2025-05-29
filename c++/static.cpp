#include <iostream>
using namespace std;

class hotel
{
  public:
    int id;
    char name[50];
    char type[20];
    int rating;
    static char location[50];
    int est_year;
    int staff_quantity;
    int room_quantity;
    
    void setdata()
	{
		cout<<"Enter Id: ";
		cin>>id;
		
		cout<<"Enter name: ";
		cin>>name;
		
		cout<<"Enter type: ";
		cin>>type;
		
		cout<<"Enter rating: ";
		cin>>rating;
		
		cout<<"Enter est_year: ";
		cin>>est_year;
		
		cout<<"Enter staff_quantity: ";
		cin>>staff_quantity;
		
		cout<<"Enter room_quantity: ";
		cin>>room_quantity;
		cout << endl;
	}
	
	void getdata()
	{
		cout<<"Id: "<<id
			<<"\nname: "<<name
			<<"\ntype: "<<type
			<<"\nrating: "<<rating
			<<"\nest_year: "<<est_year
			<<"\nstaff_quantity: "<<staff_quantity
			<<"\nroom_quantity: "<<room_quantity;
	}
};

char hotel :: location[50]="surat";

int main() 
{
	int n;
    cout << "How many hotels? ";
    cin >> n;
    
    hotel h[100];
    for(int i=0; i<n; i++)
	{
        cout << "\nHotel " << i+1 << ":\n";
        h[i].setdata();
    }

    cout << "\n--- Hotel Details ---\n";
    for (int i = 0; i < n; i++)
	{
        h[i].getdata();
        cout<<endl;
	}
}