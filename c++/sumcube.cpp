#include <iostream>
using namespace std;
class X
{
	public:
		int a;
		int b;
		int c;
		int sumcube;
};
class Y : public X
{
	public:
		void setdata()
		{
			cout<<"Enter First Number: ";
			cin>>a;
			cout<<"Enter Second Number: ";
			cin>>b;
			cout<<"Enter Third Number: ";
			cin>>c;	
		}
		void getdata()
		{
			sumcube=a*a*a+b*b*b+c*c*c;
			cout<<"Sum of cube of all three numbers is: "<<sumcube<<endl;
		}
};
int main()
{
	Y y;
	y.setdata();
	y.getdata();
}
