#include <iostream>
using namespace std;
class P
{
	//temperature attribute in float
	public:
	float c;
	float f;
	float k;
};
class Q : public P
{
	//toFehrenheit() method  °F = °C × (9/5) + 32
	public:
		void toFehrenheit()
		{
			cout<<"Enter Celsius: ";
			cin>>c;
			f=c*1.8+32;
			cout<<"Fehrenheit of "<<c<<" Degree Celsius is "<<f<<" Fehrenheit"<<endl;
		}
}; 
class R : public Q
{
	//toKelvin() method K = (F − 32) × 5 ⁄ 9 + 273.15
	public:
		void toKelvin()
		{
			k=c+273.15;
			cout<<"Kelvin of "<<f<<" Fehrenheit is "<<k<<" Kelvin"<<endl;
		}
};

int main()
{
	R r;
	r.toFehrenheit();
	r.toKelvin();
};