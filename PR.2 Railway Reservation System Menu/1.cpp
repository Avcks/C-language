#include<iostream>
using namespace std;

class details
{
	int trainNumber[100];
    char trainName[50][50];
    char source[50][50];
    char destination[50][50];
    char trainTime[10];
    static int trainCount;
    
	public:
	    details() 
		{
            trainCount++;
        }
		void name()
		{
			cout << "Train No: "; 
	        cin >> trainNumber[trainCount];
			cout<<"Enter Train name: ";
			cin>>trainName[trainCount];
			cout<<"Enter Source: ";
			cin>>source[trainCount];
			cout<<"Enter Destination: ";
			cin>>destination[trainCount];
			cout<<"Enter Train Time: ";
			cin>>trainTime[trainCount];
		}
		void display()
		{
			for (int i=0; i<trainCount; i++)
			{
				cout<<"Train number: "<<trainNumber
			        <<"\nTrain name: "<<trainName
			        <<"\nsource: "<<source
			        <<"\ndestination: "<<destination
				    <<"\nTrain Time: "<<trainTime;
			}
		}
		void search()
	    {
        int num; 
	    cout << "Enter Train No: "; 
	    cin >> num;
        for (int i = 0; i < trainCount; i++) 
		{
            if (trainNumber[i]==num) 
		    {
            cout << "Found: " << trainName[i] 
			     << ", From: " << source[i]
                 << ", To: " << destination[i] 
				 << ", Time: " << trainTime[i] << endl;
            return;
            }
        }
        cout << "Train not found!\n";
        }
};
int details::trainCount = 0;
int main()
{
	int a;
	
	while(a!=4)
	{
		details t;
	    cout<<"--- Railway Reservation System Menu ---\n"
	    <<"1. Add New Train Record"
		<<"\n2. Display All Train Records"
		<<"\n3. Search Train by Number"
		<<"\n4. Exit"
		<<"\nEnter your choice: ";
		cin>>a;
		switch(a)
		{
			case 1:
				
				t.name();
				break;
			case 2:
				t.display();
				break;
			case 3:
				cout << "Enter Train Number to search: ";
				break;
			case 4:
				break;
			default:
				cout << "Invalid choice!" << endl;
				break;
		}
	}
}
