#include <iostream>
#include <string.h>
using namespace std;

class Bankaccount 
{
    public:
    double accountnumber;
    char accountholdername[100];
    double balance;

    void accountinfo() 
	{
        cout << "Enter your Account Number: ";
        cin >> accountnumber;
        cout << "Enter Name of Account Holder: ";
        cin >> accountholdername;
        balance = 0;
        double initialDeposit = 0;
        cout << "Enter initial deposit amount: ";
        cin >> initialDeposit;
        balance = initialDeposit;
        cout << "Account created successfully with balance: " << balance << endl;
    }

    void deposit() 
	{
        double d;
        cout << "Enter Amount of Deposit fund: ";
        cin >> d;
        balance += d;
        cout << "Deposit successful. New balance is: " << balance << endl;
    }

    void withdraw() 
	{
        double w;
        cout << "Enter Amount of Withdraw fund: ";
        cin >> w;
            balance -= w;
            cout << "Withdrawal successful. New balance is: " << balance << endl;
    }

    void getbalance() 
	{
        cout << "Your Account Balance is: " << balance << endl;
    }

    void displayaccountinfo() 
	{
        cout << "Your Account Number is: " << accountnumber << endl;
        cout << "Account Holder Name of this Account is: " << accountholdername << endl;
        cout << "Your Account Balance is: " << balance << endl;
    }
};

class savingaccount : public Bankaccount 
{
public:
    int intrestrate = 10;
    double interest;

    void calculateinterest() 
	{
        interest = (balance * intrestrate) / 100;
        cout << "Your interest on this account balance (" << balance << ") per year is: " << interest << endl;
    }
};

class checkingaccount : public Bankaccount 
{
public:
    double overdraftlimit = 0;

    void checkoverdraft(double w) 
	{
        if (w > balance) 
		{
            cout << "You have exceeded your overdraft limit by: " << (w - balance) << endl;
        } else if (w == balance) 
		{
            cout << "You have reached your overdraft limit." << endl;
        } else {
            cout << "You have not overdraft Amount." << endl;
        }
    }
};

int main() 
{
    Bankaccount account;
    savingaccount savings;
    checkingaccount checking;
    int accountStatus = 0;
    int choice;

    while (choice != 7) 
	{
        cout << "\nMenu Options:\n";
        cout << "1. Add new account\n";
        cout << "2. Check your account Balance\n";
        cout << "3. Withdraw From your Account Balance\n";
        cout << "4. Deposit in your Account Balance\n";
        cout << "5. Check Your OverDraft\n";
        cout << "6. Check interest on Saving account\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                account.accountinfo();
                savings = savingaccount();
                savings.accountnumber = account.accountnumber;
                strcpy(savings.accountholdername, account.accountholdername);
                savings.balance = account.balance;

                checking = checkingaccount();
                checking.accountnumber = account.accountnumber;
                strcpy(checking.accountholdername, account.accountholdername);
                checking.balance = account.balance;
                
                accountStatus = 1;
                break;

            case 2:
                if (accountStatus == 0) 
				{
                    cout << "No account created yet. Please create an account first." << endl;
                    break;
                }
                {
//                    int inputAccNo;
//                    cout << "Enter your account number: ";
//                    cin >> inputAccNo;
//                    if (inputAccNo != account.accountnumber) {
//                        cout << "Account number not recognized." << endl;
//                        break;
//                    }
//                    account.getbalance();
                    double inputAccNo;
                    cout << "Enter your account number: ";
                    cin >> inputAccNo;
                    if (inputAccNo == savings.accountnumber) 
					{
                        savings.getbalance();
                    } else if (inputAccNo == checking.accountnumber) 
					{
                        checking.getbalance();
                    } else {
                        cout << "Account number not recognized." << endl;
                    }
                }
                break;

            case 3:
                if (accountStatus == 0) 
				{
                    cout << "No account created yet. Please create an account first." << endl;
                    break;
                }
                else
                {
                    int inputAccNo;
                    cout << "Enter your account number: ";
                    cin >> inputAccNo;
                    if (inputAccNo != account.accountnumber) 
				    {
                        cout << "Account number not recognized." << endl;
                        break;
                    }
                    account.withdraw();
                }
                break;

            case 4:
                if (accountStatus == 0) 
				{
                    cout << "No account created yet. Please create an account first." << endl;
                    break;
                }
				else
                {
                    int inputAccNo;
                    cout << "Enter your account number: ";
                    cin >> inputAccNo;
                    if (inputAccNo != account.accountnumber) 
					{
                        cout << "Account number not recognized." << endl;
                        break;
                    }
                    account.deposit();
                }
                break;

            case 5:
                if (accountStatus == 0) 
				{
                    cout << "No account created yet. Please create an account first." << endl;
                    break;
                }
                else
                {
                    double w;
                    cout << "Enter amount to check overdraft for: ";
                    cin >> w;
                    checking.checkoverdraft(w);
                }
                break;

            case 6:
                if (accountStatus == 0) 
				{
                    cout << "No account created yet. Please create an account first." << endl;
                    break;
                }
                savings.calculateinterest();
                break;

            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
