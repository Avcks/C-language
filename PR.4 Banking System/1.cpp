#include <iostream>
#include <string.h>
using namespace std;

const int maxac = 100;

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
        char tempName[100];
        cout<<"Enter Name of Account Holder: ";
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

int findaccount(Bankaccount accounts[], int size, double acctnum) 
{
    for (int i=0; i<size; i++) 
    {
        if (accounts[i].accountnumber == acctnum) 
            return i;
    }
    return -1;
}

int main() 
{
    Bankaccount accounts[maxac];
    savingaccount savings[maxac];
    checkingaccount checkings[maxac];

    int numac = 0;
    int choice = 0;

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
                if (numac>=maxac) 
                {
                    cout<<"Maximum number of accounts ("<< maxac <<") reached. Cannot add more.\n\n";
                    break;
                }
                accounts[numac].accountinfo();

                savings[numac].accountnumber = accounts[numac].accountnumber;
                
                strcpy(savings[numac].accountholdername, accounts[numac].accountholdername);
                
                savings[numac].balance = accounts[numac].balance;

                checkings[numac].accountnumber = accounts[numac].accountnumber;
                
                strcpy(checkings[numac].accountholdername, accounts[numac].accountholdername);
                
                checkings[numac].balance = accounts[numac].balance;

                numac++;
                break;

            case 2:
            {
                if (numac==0) 
                {
                    cout<<"No accounts available. Please add an account first.\n\n";
                    break;
                }
                double inputaccno;
                cout << "\nEnter your account number to check balance: ";
                cin >> inputaccno;
                int n = findaccount(accounts, numac, inputaccno);
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
                if (numac==0) 
                {
                    cout<<"No accounts available. Please add an account first.\n\n";
                    break;
                }
                double inputaccno;
                cout<<"\nEnter your account number to withdraw from: ";
                cin>>inputaccno;
                int n=findaccount(accounts, numac, inputaccno);
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
                if (numac==0) 
                {
                    cout<<"No accounts available. Please add an account first.\n\n";
                    break;
                }
                double inputaccno;
                cout<<"\nEnter your account number to deposit to: ";
                cin>>inputaccno;
                int n = findaccount(accounts, numac, inputaccno);
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
                if (numac==0) 
                {
                    cout<<"No accounts available. Please add an account first.\n\n";
                    break;
                }
                double inputaccno;
                cout<<"\nEnter your account number to check overdraft: ";
                cin>>inputaccno;
                int n = findaccount(checkings, numac, inputaccno);
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
                if (numac==0) 
                {
                    cout<<"No accounts available. Please add an account first.\n\n";
                    break;
                }
                double inputaccno;
                cout<<"\nEnter your account number to check interest: ";
                cin>>inputaccno;
                int n = findaccount(savings, numac, inputaccno);
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
/*

--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 1

--- Create New Account ---
Enter your Account Number: 1
Enter Name of Account Holder: a
Enter initial deposit amount: 12
Account created successfully with balance: 12


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 1

--- Create New Account ---
Enter your Account Number: 2
Enter Name of Account Holder: b
Enter initial deposit amount: 12
Account created successfully with balance: 12


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 1

--- Create New Account ---
Enter your Account Number: 3
Enter Name of Account Holder: c
Enter initial deposit amount: 12
Account created successfully with balance: 12


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 2

Enter your account number to check balance: 1

Current Account Balance: 12


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 2

Enter your account number to check balance: 4
Account number not recognized.


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 3

Enter your account number to withdraw from: 2

Enter Amount to Withdraw: 1
Withdrawal successful. New balance is: 11


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 3

Enter your account number to withdraw from: 4
Account number not recognized.


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 4

Enter your account number to deposit to: 3

Enter Amount to Deposit: 1
Deposit successful. New balance is: 13


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 4

Enter your account number to deposit to: 4
Account number not recognized.


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 5

Enter your account number to check overdraft: 1
Enter amount to check overdraft for: 1

Checking overdraft for amount: 1
You have sufficient balance, no overdraft amount.


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 6

Enter your account number to check interest: 1

Interest on balance (12) per year at rate 10% is: 1.2


--- Main Menu ---
1. Add New Account
2. Check Account Balance
3. Withdraw from Account
4. Deposit to Account
5. Check Your Overdraft
6. Check Interest on Savings Account
7. Exit
Please enter your choice: 7

Exiting program. Goodbye!

*/

