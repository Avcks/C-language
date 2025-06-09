#include <iostream>
#include <string.h>
using namespace std;

const int max = 100;

class Bankaccount 
{
public:
    double accountnumber;
    char accountholdername[100];
    double balance;

    void accountinfo() 
    {
        cout<<"\n--- Create New Account ---\n";
        cout<<"Enter your Account Number: ";
        cin>>accountnumber;
        cout<<"Enter Name of Account Holder (single word): ";
        cin>>tempName;
        strcpy(accountholdername, tempName);
        double initialDeposit = 0;
        cout<<"Enter initial deposit amount: ";
        cin>>initialDeposit;
        balance=initialDeposit;
        cout << "Account created successfully with balance: " << balance << "\n\n";
    }

    void deposit() 
    {
        double d;
        cout<<"\nEnter Amount to Deposit: ";
        cin>>d;
        if (d<0) 
        {
            cout<<"Deposit amount cannot be negative.\n";
            return;
        }
        balance += d;
        cout<<"Deposit successful. New balance is: "<< balance <<"\n\n";
    }

    void withdraw() 
    {
        double w;
        cout<<"\nEnter Amount to Withdraw: ";
        cin>>w;
        if (w<0) 
        {
            cout<<"Withdrawal amount cannot be negative.\n";
            return;
        }
        if (w>balance) 
        {
            cout<<"Insufficient balance. Withdrawal failed.\n\n";
        } 
        else 
        {
            balance -= w;
            cout<<"Withdrawal successful. New balance is: "<< balance <<"\n\n";
        }
    }

    void getbalance() 
    {
        cout<<"\nCurrent Account Balance: "<< balance <<"\n\n";
    }

    void displayaccountinfo() 
    {
        cout<<"\nAccount Information:\n";
        cout<<"Account Number: "<< accountnumber <<"\n";
        cout<<"Account Holder: "<< accountholdername <<"\n";
        cout<<"Account Balance: "<< balance <<"\n\n";
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
        cout<<"\nInterest on balance ("<< balance <<") per year at rate "<< intrestrate <<"% is: "<< interest <<"\n\n";
    }
};

class checkingaccount : public Bankaccount 
{
public:
    double overdraftlimit = 0;

    void checkoverdraft(double w) 
    {
        cout<<"\nChecking overdraft for amount: "<< w <<"\n";
        if (w>balance) 
        {
            cout<<"You have exceeded your overdraft limit by: "<< (w - balance) <<"\n\n";
        } 
        else if (w==balance) 
        {
            cout<<"You have reached your overdraft limit.\n\n";
        } 
        else 
        {
            cout<<"You have sufficient balance, no overdraft amount.\n\n";
        }
    }
};

int findAccountIndexByNumber(Bankaccount accounts[], int size, double acctNum) 
{
    for (int i = 0; i<size; i++) 
    {
        if (accounts[i].accountnumber == acctNum) 
            return i;
    }
    return -1;
}

int main() 
{
    Bankaccount accounts[max];
    savingaccount savings[max];
    checkingaccount checkings[max];

    int numaccounts = 0;
    int choice = 0;

    cout<<"===============================================\n";
    cout<<"     Welcome to the Bank Account Manager       \n";
    cout<<"===============================================\n";

    while (choice!=7) 
    {
        cout<<"\n--- Main Menu ---\n";
        cout<<"1. Add New Account\n";
        cout<<"2. Check Account Balance\n";
        cout<<"3. Withdraw from Account\n";
        cout<<"4. Deposit to Account\n";
        cout<<"5. Check Your Overdraft\n";
        cout<<"6. Check Interest on Savings Account\n";
        cout<<"7. Exit\n";
        cout<<"Please enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                if (numaccounts>=max) 
                {
                    cout<<"Maximum number of accounts ("<< max <<") reached. Cannot add more.\n\n";
                    break;
                }
                accounts[numaccounts].accountinfo();

                savings[numaccounts].accountnumber = accounts[numaccounts].accountnumber;
                strcpy(savings[numaccounts].accountholdername, accounts[numaccounts].accountholdername);
                savings[numaccounts].balance = accounts[numaccounts].balance;

                checkings[numaccounts].accountnumber = accounts[numaccounts].accountnumber;
                strcpy(checkings[numaccounts].accountholdername, accounts[numaccounts].accountholdername);
                checkings[numaccounts].balance = accounts[numaccounts].balance;

                numaccounts++;
                break;

            case 2:
            {
                if (numaccounts==0) 
                {
                    cout<<"No accounts available. Please add an account first.\n\n";
                    break;
                }
                double inputAccNo;
                cout << "\nEnter your account number to check balance: ";
                cin >> inputAccNo;
                int n = findAccountIndexByNumber(accounts, numaccounts, inputAccNo);
                if (n>=0) 
                {
                    accounts[n].getbalance();
                } 
                else 
                {
                    cout << "Account number not recognized.\n\n";
                }
                break;
            }

            case 3:
            {
                if (numaccounts==0) 
                {
                    cout<<"No accounts available. Please add an account first.\n\n";
                    break;
                }
                double inputAccNo;
                cout<<"\nEnter your account number to withdraw from: ";
                cin>>inputAccNo;
                int n=findAccountIndexByNumber(accounts, numaccounts, inputAccNo);
                if (n>=0) 
                {
                    accounts[n].withdraw();
                    savings[n].balance = accounts[n].balance;
                    checkings[n].balance = accounts[n].balance;
                } 
                else 
                {
                    cout<<"Account number not recognized.\n\n";
                }
                break;
            }

            case 4:
            {
                if (numaccounts==0) 
                {
                    cout<<"No accounts available. Please add an account first.\n\n";
                    break;
                }
                double inputAccNo;
                cout<<"\nEnter your account number to deposit to: ";
                cin>>inputAccNo;
                int n = findAccountIndexByNumber(accounts, numaccounts, inputAccNo);
                if (n>=0) 
                {
                    accounts[n].deposit();
                    savings[n].balance=accounts[n].balance;
                    checkings[n].balance=accounts[n].balance;
                }
                else 
                {
                    cout<<"Account number not recognized.\n\n";
                }
                break;
            }

            case 5:
            {
                if (numaccounts==0) 
                {
                    cout<<"No accounts available. Please add an account first.\n\n";
                    break;
                }
                double inputAccNo;
                cout<<"\nEnter your account number to check overdraft: ";
                cin>>inputAccNo;
                int n = findAccountIndexByNumber(checkings, numaccounts, inputAccNo);
                if (n>=0) 
                {
                    double w;
                    cout<<"Enter amount to check overdraft for: ";
                    cin>>w;
                    checkings[n].checkoverdraft(w);
                }
                else 
                {
                    cout<<"Account number not recognized.\n\n";
                }
                break;
            }

            case 6:
            {
                if (numaccounts==0) 
                {
                    cout<<"No accounts available. Please add an account first.\n\n";
                    break;
                }
                double inputAccNo;
                cout<<"\nEnter your account number to check interest: ";
                cin>>inputAccNo;
                int n = findAccountIndexByNumber(savings, numaccounts, inputAccNo);
                if (n>=0) 
                {
                    savings[n].calculateinterest();
                }
                else 
                {
                    cout<<"Account number not recognized.\n\n";
                }
                break;
            }

            case 7:
                cout<<"\nExiting program. Goodbye!\n";
                break;

            default:
                cout<<"\nInvalid choice. Please try again.\n";
                break;
        }
    }

}


