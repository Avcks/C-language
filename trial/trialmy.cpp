#include <iostream>
using namespace std;
class Bankaccount
{
	public:
	int accountnumber;
	char accountholdername;
	double balance;
	
	void accountinfo()
	{
		cout<<"Enter your Account Number: ";
		cin>>accountnumber;
		cout<<"Enter Name of Account Holder: ";
		cin>>accountholdername;
		balance=0;
	}
	
	void deposit()
	{
		double d;
		cout<<"Enter Amount of Deposit fund: ";
		cin>>d;
		balance = balance + d;
	}
	
	void withdraw()
	{
		double w;
		cout<<"Enter Amount of Withdraw fund: ";
		cin>>w;
		balance = balance - w;
	}
	
	void getbalance()
	{
		cout<<"Your Account Balance is: "<<balance<<endl;
	}
	
	void displayaccountinfo()
	{
		cout<<"Your Account Number is: "<<accountnumber<<endl;
		cout<<"Account Holder Name of this Account is: "<<accountholdername<<endl;
		cout<<"Your Account Balance is: "<<balance<<endl;
	}
};
class savingaccount : public Bankaccount
{
	int intrestrate == 10 ;
	int interst;
	void calculateinterst()
	{
		interst=(balance*intrestrate*1)/100
		cout<<"Your intrest on this account balance ("<<balance<<")  per year is: "<<interst<<endl;
	}
};
class checkingaccount : public Bankaccount
{
	double overdraftlimit=balance;
	void checkoverdraft
	{
		if(w>balance)
		{
			cout<<"You Have exceeds your overdraft limit by: "<<overdraftlimit-w<<endl;
		}
		else if(w=balance)
		{
			cout<<"You have reached to your overdraft limit."<<endl;
		}
		else
		{
			cout<<"You had not overdraft Amount."<<endl;
		}
	}
}
int main()
{
	cout<<"Enter 1 to Add new account."endl;
	cout<<"Enter 2 to Check your account Balance."endl;
	cout<<"Enter 3 to Withdraw From your Account Balance."endl;
	cout<<"Enter 4 to Deposit in your Account Balance."endl;
	cout<<"Enter 5 to Check Your OverDraft."endl;
	cout<<"Enter 6 to Check interst on Saving account."<<endl;
	cout<<"Enter 7 to exit."<<endl
}