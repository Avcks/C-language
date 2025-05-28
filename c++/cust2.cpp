#include<iostream>
using namespace std;
class customer
{
	private:
		int id;
	    char name[30];
	    int age;
	    char city[30];
	    int mobile_number;
	    int simcard_validity_in_year;
	    char telecom_brand_name[10];
	    
	public:
		void setdata()
		{
			cout<<"Enter Id: ";
			cin>>id;
			cout<<"Enter name: ";
			cin>>name;
			cout<<"Enter age: ";
			cin>>age;
			cout<<"Enter city: ";
			cin>>city;
			cout<<"Enter mobile number: ";
			cin>>mobile_number;
			cout<<"Enter simcard validity in year: ";
			cin>>simcard_validity_in_year;
			cout<<"Enter telecom brand name: ";
			cin>>telecom_brand_name;
			getdata();
		}
		void getdata()
		{
			cout<<"Id: "<<id
			    <<"\nname: "<<name
			    <<"\nage: "<<age
			    <<"\ncity: "<<city
			    <<"\nmobile number"<<mobile_number
			    <<"\nsimcard validity in year"<<simcard_validity_in_year
			    <<"\ntelecom brand name"<<telecom_brand_name;
		}
};
int main()
{
	customer c1, c2, c3, c4, c5;
	c1.setdata();
	c2.setdata();
	c3.setdata();
	c4.setdata();
	c5.setdata();
}